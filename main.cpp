#include "main.h"

int main()
{
    if (__argc != 2 && __argc != 3)
    { // Incorrect number of args
        std::cout << "  Usage: client <host>\n";
        return 1;
    }

    if (__argc == 2)
    {
        // Client (just an IP address passed through - no port)
        std::cout << "Starting client...\n";
        try
        {
            asio::io_context io_context;

            asio::ip::tcp::resolver resolver(io_context);
            asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(__argv[1], "daytime");

            asio::ip::tcp::socket socket(io_context);
            asio::connect(socket, endpoints);

            for(;;)
            {
                std::array<char, 128> buf{};
                asio::error_code error;

                size_t len = socket.read_some(asio::buffer(buf), error);

                // Connection closed cleanly per peer
                if(error == asio::error::eof)
                {
                    std::cout << "Client eof error message received...\n";
                    break;
                }
                if(error)
                {
                    // This is a real error - i think?
                    std::cout << "Client side error reading data stream socket connected to server...\n";
                    throw asio::system_error(error);
                }

                // If no error, stream the data from the buffer the buffer from the s
                std::cout.write(buf.data(), len);
            }
        }
        catch
        (std::exception &e)
        {
            std::cout << "Unknown error...?\n";
            std::cerr << e.what() << '\n';
        }
        return 0;
    }

    try
    {
        std::cout << "Starting server...\n";
        asio::io_context io_context;
        jc::tcp_server server(io_context);
        io_context.run();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
