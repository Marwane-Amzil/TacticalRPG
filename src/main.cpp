#include <network.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    iut::ClientSocket client(iut::LOCALHOST, iut::port::DEFAULT);
    client.connect();
    client.send("I am the first client\n");

    while (true)
    {
        const char* message = client.receive();

        if (!strcmp(message, "stop"))
        {
            delete message;
            break;
        }

        std::cout << message << '\n';

        delete message;
    }

    return 0;
}