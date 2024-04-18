#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "tcp_connection.h"

#include <functional>

#include <asio.hpp>


namespace jc
{
    // ~ TCP Server class declaration
    class tcp_server
    {
    public:
        explicit tcp_server(asio::io_context &io_context);

    private:
        void start_accept();
        void handle_accept(const tcp_connection::pointer &new_connection, const asio::error_code &error);
        asio::io_context &io_context_;
        asio::ip::tcp::acceptor acceptor_;
    };
}

#endif //TCP_SERVER_H
