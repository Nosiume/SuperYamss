#pragma once

#include <SFML/Network.hpp>
#include <thread>

#include "Server.h"

enum PacketType
{
	CONNECT = 0,
	USERNAME = 1,
	DISCONNECT = 2
};

class ClientHandler
{
private:
	Server* m_server = nullptr;

	bool m_running = true;
	std::thread m_handler;
	sf::TcpSocket* m_sock = nullptr;

public:
	//Will start a new thread with a ClientHandler process to handle packets 
	ClientHandler(sf::TcpSocket* _sock, Server* server);
	ClientHandler(const ClientHandler&) {} // We need this constructor in order to avoid crashes in xmemory
	~ClientHandler();

	//Thread Process
	void run();
};