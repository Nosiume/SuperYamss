#include "ClientHandler.h"

void ClientHandler::run()
{
	while (running)
	{
		//Client packet handler
		sf::Packet packet;
		if (sock->receive(packet) != sf::Socket::Done)
			continue;
	}
}

ClientHandler::ClientHandler(sf::TcpSocket* _sock)
{
	sock = _sock;
	//server = _server;
	handler = std::thread([this] {this->run(); });
}

ClientHandler::~ClientHandler()
{
	handler.join();
	delete sock;
}