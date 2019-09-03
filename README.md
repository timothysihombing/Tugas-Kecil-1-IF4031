# Tugas Kecil 1 IF4031


## Server Benchmark

We use <b>Apache Bench (Ab)</b> to measure the performance of Apache and Nginx web servers, to access html documents that require about 500 bytes and 20 KB. We also want to check whether this server is capable of serving up to 10,000 concurrent requests.


### Testing Guidance

#### Apache

1. Move to assets directory.
    ```shell
	$ cd assets
	```

2. Turn on Apache server.
    ```shell
	$ sudo apachectl start
	```

3. To help you view initial and peak memory usage, enter a command to see memory usage every 0.2 seconds. Find the difference!
    ```shell
	$ watch -n 0,2
	```

4. Enter the following command to benchmark page 500 bytes.
	```shell
	$ ab -n 10000 -c 10000 -r http://localhost/500b.html
	```

5. Enter the following command to benchmark page 20 KB.
	```shell
	$ ab -n 10000 -c 10000 -r http://localhost/20KB.html
	```

6. Turn off Apache Server.
    ```shell
	$ sudo apachectl stop
	```

#### Nginx

1. Move to assets directory.
    ```shell
	$ cd assets
	```

2. Turn on Nginx server.
    ```shell
	$ sudo service nginx start
	```

3. To help you view initial and peak memory usage, enter a command to see memory usage every 0.2 seconds. Find the difference!
    ```shell
	$ watch -n 0,2
	```

4. Enter the following command to benchmark page 500 bytes.
	```shell
	$ ab -n 10000 -c 10000 -r http://localhost/500b.html
	```

5. Enter the following command to benchmark page 20 KB.
	```shell
	$ ab -n 10000 -c 10000 -r http://localhost/20KB.html
	```

6. Turn off Apache Server.
    ```shell
	$ sudo service nginx stop
	```

#### High-level program (Node.js)

1. Go to directory
	```
	$ cd file_sender_high_level
	```

2. Run node server
	```
	$ node index.js [portNumber]
	```

	Port number defaults to 9000

3. Call the server as such
	```
	http://[IPAddress]:[portNumber]/[file-path]
	```

4. To do benchmark for 500 bytes text file, with port 9000 and localhost, do
	```
	$ ab -n 10000 -c 10000 -r http://localhost:9000/assets/500b.txt
	```

5. To do benchmark for 20 KB text file, with port 9000 and localhost, do
	```
	$ ab -n 10000 -c 10000 -r http://localhost:9000/assets/200kb.txt
	```

### Testing Result

#### Apache

1. Testing C10K 500 byte HTML Page
	<table>
		<tr>
			<th>Eksperimen</th>
			<th>Response Time</th>
			<th>Memory Usage</th>
		</tr>
		<tr>
			<td>1</td>
			<td>Timeout (8412 reqs)</td>
			<td>~110000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Timeout (7888 reqs)</td>
			<td>~98000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Timeout (7045 reqs)</td>
			<td>~89000 KB</td>
		</tr>
	</table>

2. Testing C10K 20 KB HTML Page
	<table>
		<tr>
			<th>Eksperimen</th>
			<th>Response Time</th>
			<th>Memory Usage</th>
		</tr>
		<tr>
			<td>1</td>
			<td>Timeout (7674 reqs)</td>
			<td>~97000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Timeout (7052 reqs)</td>
			<td>~95000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Timeout (6766 reqs)</td>
			<td>~96000 KB</td>
		</tr>
	</table>

#### Nginx

1. Testing C10K 500 byte HTML Page
	<table>
		<tr>
			<th>Eksperimen</th>
			<th>Response Time</th>
			<th>Memory Usage</th>
		</tr>
		<tr>
			<td>1</td>
			<td>Timeout (8412 reqs)</td>
			<td>~110000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Timeout (7888 reqs)</td>
			<td>~98000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Timeout (7045 reqs)</td>
			<td>~89000 KB</td>
		</tr>
	</table>

2. Testing C10K 20 KB HTML Page
	<table>
		<tr>
			<th>Eksperimen</th>
			<th>Response Time</th>
			<th>Memory Usage</th>
		</tr>
		<tr>
			<td>1</td>
			<td>Timeout (7674 reqs)</td>
			<td>~97000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Timeout (7052 reqs)</td>
			<td>~95000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Timeout (6766 reqs)</td>
			<td>~96000 KB</td>
		</tr>
	</table>
