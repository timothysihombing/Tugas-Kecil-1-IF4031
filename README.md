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
			<th>Request per Sec (mean)</th>
			<th>Response Time (mean)</th>
			<th>Memory Usage</th>
		</tr>
		<tr>
			<td>1</td>
			<td>2234.16 req/sec</td>
			<td>4475.953 ms</td>
			<td>~110000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>2079.22 req/sec</td>
			<td>4688.21 ms</td>
			<td>~98000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>2592.221 req/sec</td>
			<td>4103.821 ms</td>
			<td>~89000 KB</td>
		</tr>
	</table>

2. Testing C10K 20 KB HTML Page
	<table>
		<tr>
			<th>Eksperimen</th>
			<th>Request per Sec (mean)</th>
			<th>Response Time (mean)</th>
			<th>Memory Usage</th>
		</tr>
		<tr>
			<td>1</td>
			<td>2012.14 req/sec</td>
			<td>4724.522 ms</td>
			<td>~97000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>1971.223 req/sec</td>
			<td>4798.38 ms</td>
			<td>~95000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>1988.72 req/sec</td>
			<td>4771.67 ms</td>
			<td>~96000 KB</td>
		</tr>
	</table>

#### Nginx

1. Testing C10K 500 byte HTML Page
	<table>
		<tr>
			<th>Eksperimen</th>
			<th>Request per Sec (mean)</th>
			<th>Response Time (mean)</th>
			<th>Memory Usage</th>
		</tr>
		<tr>
			<td>1</td>
			<td>16027.41 req/sec</td>
			<td>623.931 ms</td>
			<td>~110000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>16302.87 req/sec</td>
			<td>613.389 ms</td>
			<td>~98000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>15901.32 req/sec</td>
			<td>598.42 ms</td>
			<td>~89000 KB</td>
		</tr>
	</table>

2. Testing C10K 20 KB HTML Page
	<table>
		<tr>
			<th>Eksperimen</th>
			<th>Request / sec (mean)</th>
			<th>Response Time (mean)</th>
			<th>Memory Usage</th>
			<th>Failed Requests</th>
		</tr>
		<tr>
			<td>1</td>
			<td>15271.49 req/sec</td>
			<td>654.815 ms</td>
			<td>~97000 KB</td>
		</tr>
		<tr>
			<td>2</td>
			<td>15364.15 req/sec</td>
			<td>650.866 ms</td>
			<td>~95000 KB</td>
		</tr>
		<tr>
			<td>3</td>
			<td>15920.55 req/sec</td>
			<td>628.119 ms</td>
			<td>~96000 KB</td>
		</tr>
	</table>

#### High-level program (Node.js)
Note: Test is done using Docker Container to run the node server and the ApacheBench tool.

1. Testing receiving C10K 500 byte file
	<table>
		<tr>
			<th>Eksperiment#</th>
			<th>Response Time (mean)</th>
			<th>Memory Usage</th>
			<th>Failed requests</th>
		</tr>
		<tr>
			<td>1</td>
			<td>15513 ms</td>
			<td>~136.315 MB</td>
			<td>6216</td>
		</tr>
		<tr>
			<td>2</td>
			<td>16333 ms</td>
			<td>~144.07434 MB</td>
			<td>5898</td>
		</tr>
		<tr>
			<td>3</td>
			<td>13604 ms</td>
			<td>~140.509 MB</td>
			<td>5295</td>
		</tr>
	</table>

2. Testing receiving C10K 20 KB file
	<table>
		<tr>
			<th>Eksperiment#</th>
			<th>Response Time (mean)</th>
			<th>Memory Usage</th>
			<th>Failed requests</th>
		</tr>
		<tr>
			<td>1</td>
			<td>17230 ms</td>
			<td>~207.618 MB</td>
			<td>5975</td>
		</tr>
		<tr>
			<td>2</td>
			<td>14079 ms</td>
			<td>~200.69745 MB</td>
			<td>5281</td>
		</tr>
		<tr>
			<td>3</td>
			<td>15258 ms</td>
			<td>~197.132 MB</td>
			<td>5326</td>
		</tr>
	</table>
