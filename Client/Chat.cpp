#include "Chat.h"
#include "Client.h"

void Chat::createChat()
{
	Client& client = Client::cli();
	ChatWorker = true;
}

bool Chat::ChatWorker()
{
	return ChatWorker;
}

void Chat::closeChat()
{
	ChatWorker = false;
	close(Client::cli().getSocket_file_descriptor());
}
