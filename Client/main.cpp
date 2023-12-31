#include "Chat.h"
#include "Client.h"
#include <iostream>

using namespace std;

int main()
{
    Chat chat;
    chat.createChat();

    Client& c = Client::cli();
    char message[MESSAGE_LENGTH];

    while (chat.ChatWorker())
    {
        bzero(message, sizeof(message));
        std::cout << std::endl;
        std::cout << "Enter message you want to send the server: " << std::endl;
        std::cin >> message;
        if (strncmp("End", message, 3) == 0)
        {
            write(c.getSocket_file_descriptor(), message, sizeof(message));
            std::cout << "Client is gone" << std::endl;
            chat.closeChat();
            continue;
        }
        ssize_t bytes = write(c.getSocket_file_descriptor(), message, sizeof(message));
        if (bytes >= 0)
        {
            std::cout << std::endl;
            std::cout << "Message is send successfully the server" << std::endl;
        }
        bzero(message, sizeof(message));
        read(c.getSocket_file_descriptor(), message, sizeof(message));
        std::cout << std::endl;
        std::cout << "Message received from the server: " << std::endl << message << std::endl;
    }

    return 0;
}
