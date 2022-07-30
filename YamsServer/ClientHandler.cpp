#include "ClientHandler.h"

void ClientHandler::run()
{
	while (m_running)
	{
		//Client packet handler
		sf::Packet packet;
		if (m_sock->receive(packet) != sf::Socket::Done)
			continue;
	}
}

ClientHandler::ClientHandler(sf::TcpSocket* sock, Server* server) :
	m_sock(sock), m_server(server)
{
	m_handler = std::thread([this] {this->run(); });
}

ClientHandler::~ClientHandler()
{
	m_handler.join();
	delete m_sock;
}