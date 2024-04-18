#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "tcp_connection.h"

#include <iostream>
#include <asio.hpp>
#include <functional>
#include <asio.hpp>



namespace jc
{
    // ~ TCP Server class declaration
    class tcp_client
    {
    public:
        explicit tcp_client(asio::io_context &io_context, const std::string_view &host, const std::string_view &service);

    private:
        void start_resolve(const std::string_view &host, const std::string_view &service);
        void handle_resolve(const asio::error_code &error, const asio::ip::tcp::resolver &resolved_endpoints);
        asio::io_context &io_context_;
        asio::ip::tcp::resolver resolver_;

        asio::ip::tcp::resolver::results_type &endpoints_;
    };
}

#endif //TCP_CLIENT_H
