#include <iostream>
#include <SFML/Network.hpp>

#include "Server.h"
#include "ClientHandler.h"


Server::Server(const char* ip, unsigned short port)
{
	sf::IpAddress addr(ip);
	std::cout << "Starting server with address " << ip << ":" << port << std::endl;

	if (listener.listen(port, ip) != sf::Socket::Done)
	{
		std::cerr << "[-] Can't start listener for unknown reasons." << std::endl;
		exit(-1); //Crash the program
	}
}

Server::~Server()
{
	//Destroyer, to free any kind of memory that could be manually allocated
}

void Server::parsePacket(sf::Packet& packet, ClientHandler& source)
{
	sf::Int32 type;
	packet >> type; // Load type from packet
	switch (type)
	{
	case PacketType::CONNECT:
	case PacketType::DISCONNECT:
	case PacketType::USERNAME:
	default:
		std::cout << "[-] Received unknown packet" << std::endl;
		break;
	}
}

void Server::run()
{
	while (running)
	{
		sf::TcpSocket client;
		if (listener.accept(client) != sf::Socket::Done)
		{
			std::cerr << "[-] Client connection rejected" << std::endl;
			continue;
		}
		std::cout << "[+] Client connection received from " << client.getRemoteAddress() << std::endl;
		std::cout << "[+] Creating client handler on this socket" << std::endl;
		handlers.push_back(ClientHandler(&client));
	}
}
