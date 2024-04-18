#include "tcp_client.h"

namespace jc
{
    // ~ TCP Server member definitions
    tcp_client::tcp_client(asio::io_context &io_context, const std::string_view host, const std::string_view service)
        : io_context_(io_context),
          resolver_(io_context)
    {
        start_resolve(host, service);
    }

    // @param: host --> IP Address
    // @param: service --> Port
    void tcp_client::start_resolve(const std::string_view host, const std::string_view service)
    {
        std::cout << "Client attempting to resolve IPv4 address...\n";
        std::cout << "HOST: " << host << '\n';
        std::cout << "SERVICE: " << service << '\n';

        tcp_connection::pointer new_connection = tcp_connection::create(io_context_);

        resolver_.
        async_resolve(
            host,
            service,
            std::bind(&tcp_client::handle_resolve, &new_connection, this, asio::placeholders::error, endpoints_));

        // tcp_connection::pointer new_connection = tcp_connection::create(io_context_);
        // resolver_
        // async_accept(
        //     new_connection->socket(),
        //     std::bind(&tcp_client::handle_accept, this, new_connection, asio::placeholders::error));
    }




    void tcp_client::handle_resolve(
        const tcp_connection::pointer &new_connection,
        const asio::error_code &error,
        const asio::ip::tcp::resolver::results_type results)
    {
        // std::cout << "Client handling a newly received request...\n";
        // if(!error) new_connection->start();
        // start_accept();
    }
}