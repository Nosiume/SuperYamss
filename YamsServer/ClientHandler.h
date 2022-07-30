#pragma once

#include <SFML/Network.hpp>
#include <thread>

enum PacketType
{
	CONNECT = 0,
	USERNAME = 1,
	DISCONNECT = 2
};

class ClientHandler
{
private:
	bool running = true;
	std::thread handler;
	sf::TcpSocket* sock = nullptr;
	//Server* server = nullptr;

public:
	//Will start a new thread with a ClientHandler process to handle packets 
	ClientHandler(sf::TcpSocket* _sock);
	ClientHandler(const ClientHandler&) {} // We need this constructor in order to avoid crashes in xmemory
	~ClientHandler();

	//Thread Process
	void run();
};