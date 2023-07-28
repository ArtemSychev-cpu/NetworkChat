#include "Chat.h"
#include "Server.h"

void Chat::createChat()
{
	Server& server = Server::ser();
	ChatWork = true;
}

bool Chat::ChatWork()
{
	return ChatWork;
}

void Chat::closeChat()
{
	ChatWork = false;
	close(Server::ser().getSocket_file_descriptor());
