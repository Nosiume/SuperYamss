#include <iostream>
#include "Server.h"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "Server parameters are : ./YamsServer.exe <ip> <port>" << std::endl;
		std::cerr << "	ip - The IP Address of this host" << std::endl;
		std::cerr << "	port - 2 BYTES value representing the server's port" << std::endl;
		return -1;
	}

	const char* ip = argv[1];
	unsigned short port = atoi(argv[2]);

	//Make server and run it
	Server server(ip, port);
	server.run();

	return 0;
}