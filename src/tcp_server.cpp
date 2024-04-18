#include "tcp_server.h"

namespace jc
{
    // ~ TCP Server member definitions
    tcp_server::tcp_server(asio::io_context &io_context)
        : io_context_(io_context),
          acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 13))
    {
        start_accept();
    }

    void tcp_server::start_accept()
    {
        std::cout << "Server waiting for a new request...\n";
        tcp_connection::pointer new_connection = tcp_connection::create(io_context_);
        acceptor_.async_accept(
            new_connection->socket(),
            std::bind(&tcp_server::handle_accept, this, new_connection, asio::placeholders::error));
    }

    void tcp_server::handle_accept(const tcp_connection::pointer &new_connection, const asio::error_code &error)
    {
        std::cout << "Server handling a newly received request...\n";
        if(!error) new_connection->start();
        start_accept();
    }
}
