#include "tcp_connection.h"


namespace jc
{
    // ~ TCP Connection member definitions
    asio::ip::tcp::socket& tcp_connection::socket()
    {
        return socket_;
    }

    void tcp_connection::start()
    {
        std::cout << "Server calls new_connection->start() in response to a new request...\n";

        // Create and set message_
        message_ = make_daytime_string();

        // Send message_ as buffer to the tcp_connection's socket
        async_write(
            socket_,
            asio::buffer(message_),
            std::bind(
                &tcp_connection::handle_write,
                shared_from_this(),
                asio::placeholders::error,
                asio::placeholders::bytes_transferred
            )
        );
    }

    tcp_connection::tcp_connection(asio::io_context &io_context)
        : socket_(io_context) {}

    void tcp_connection::handle_write(const asio::error_code &error, size_t bytes_transferred)
    {
        std::cout << "Server emitted handle_write callback... Rolling total of bytes_transferred: "
            << bytes_transferred << '\n';
        if (error)
        {
            std::cerr << "Error message: \n" << error.message() << "\n";
        }
    }
}
