#pragma once

#include <SFML/Network.hpp>
#include <vector>

class ClientHandler;

class Server 
{
private:
	sf::TcpListener listener;
	std::vector<ClientHandler> handlers;
	bool running = true;

public:
	Server(const char* ip, unsigned short port);
	~Server();

	void parsePacket(sf::Packet& packet, ClientHandler& source);

	void run();

};