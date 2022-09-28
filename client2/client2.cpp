using namespace std;

float accumulation = 0;
int counterNow = 0;
double elapsed = 0;

float calculateAverage(float temp) {
	static int counter = 1;

	float average = (accumulation + temp) / counter;
	counterNow = counter;
	counter++;
	return average;
}

//float calcAvgTime(float temp) {
//	float avgOverTime = (accumulation + temp) / (elapsed + 1);
//	return avgOverTime;
//
//}

float calculateAccumulation(float temp) {
	::accumulation += temp;
	return ::accumulation;

}

void main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;

	//start winSock 
	WSAData data;
	WORD version = MAKEWORD(2, 2);

	int wsOk = WSAStartup(version, &data);

	if (wsOk != 0) {

		cout << " Can't Start WinSock " << wsOk;
		return;
	}

	//Create a hint structure for server
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	int serverLength = sizeof(server);

	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

	//create socket

	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);
	//send request from server socket
	string s = "hi";

	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));

	if (sendOk == SOCKET_ERROR) {

		cout << WSAGetLastError() << endl;

	}
	//get temperature and calculate
	 
	char buf[1024];

	start = std::chrono::system_clock::now();

	while (true) {
		ZeroMemory(buf, 1024);

		int bytesIn = recvfrom(out, buf, 1024, 0, (sockaddr*)&server, &serverLength);

		if (bytesIn == SOCKET_ERROR) {
			cout << WSAGetLastError() << endl;
		}
		cout << "Temp received " << buf << endl;
		end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;
		elapsed = floor(elapsed_seconds.count());

	//	cout << "elapsed seconds = " << elapsed << endl;
		float av = calculateAverage(atof(buf));
		//float avOverTime = calcAvgTime(atof(buf));
		float acc = calculateAccumulation(atof(buf));

		if ((int)elapsed % 5 == 0) {


			cout << "average = " << av << endl;
			//cout << "Actual average over time = " << avOverTime << endl;
			cout << "accumulation = " << acc << endl;
		}
	}

	closesocket(out);

	//ShutDOwn Winsock 
	WSACleanup();
}
