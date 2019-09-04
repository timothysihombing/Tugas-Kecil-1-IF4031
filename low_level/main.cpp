#include <memory>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#include <evhttp.h>

int main() {
  if (!event_init()) {
    cerr << "Failed to init libevent." << endl;
    return -1;
  }

  const char SrvAddress[] = "127.0.0.1";
  uint16_t SrvPort = 5555;
  unique_ptr<evhttp, decltype(&evhttp_free)> Server(evhttp_start(SrvAddress, SrvPort), &evhttp_free);

  if (!Server) {
    cerr << "Failed to init http server." << std::endl;
    return -1;
  }

  void (*OnReq)(evhttp_request *req, void *) = [] (evhttp_request *req, void *) {
    auto *OutBuf = evhttp_request_get_output_buffer(req);

    if (!OutBuf)
      return;	

    const char* requestUri = evhttp_request_get_uri(req);
    cout << requestUri << endl;

    const char* filepath;
    if (strcmp(requestUri, "/500bytes.html") == 0) {
      filepath = "./assets/500bytes.html";
    } else if (strcmp(requestUri, "/20KB.html") == 0) {
      filepath = "./assets/20KB.html";
    } else {
      filepath = "./assets/index.html";
    }

    ifstream ifs(filepath); 
    string content;
    content.assign( (istreambuf_iterator<char>(ifs)),
                (istreambuf_iterator<char>()));
    const char* resp = content.c_str();
    evbuffer_add_printf(OutBuf, "%s", resp);
    evhttp_send_reply(req, HTTP_OK, "", OutBuf);
  };

  evhttp_set_gencb(Server.get(), OnReq, nullptr);

  if (event_dispatch() == -1) {
    cerr << "Failed to run messahe loop." << std::endl;
    return -1;
  }

  return 0;
}


