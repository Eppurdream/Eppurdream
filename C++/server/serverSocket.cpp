#include <iostream>
#include <WS2tcpip.h>

using namespace std;

#pragma comment(lib, "ws2_32")

int main()
{
	WSADATA wsaData;

	SOCKET sListening;
	SOCKADDR_IN serverAddr;
	{
		serverAddr.sin_port = htons(5678);
		serverAddr.sin_family = AF_INET;
		InetPton(AF_INET, TEXT("127.0.0.1"), &serverAddr.sin_addr);
		serverAddr.sin_addr.s_addr = INADDR_ANY;
	}
	SOCKET sClient;
	SOCKADDR_IN clientAddr;
	int clientAddrSize = sizeof(clientAddr);
	char chMsg[1024];

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	sListening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	bind(sListening, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

	listen(sListening, SOMAXCONN);

	sClient = accept(sListening, (SOCKADDR*)&clientAddr, &clientAddrSize);
	closesocket(sListening);

	while (recv(sClient, chMsg, 1024, 0) != -1)
	{
		cout << "클라이언트 : " << chMsg << endl;
		cin.getline(chMsg, 1024);

		send(sClient, chMsg, 1024, 0);
	}

	closesocket(sClient);
	WSACleanup();

	return 0;
}
