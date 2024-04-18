#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H


#include "message_basic.h"

#include <memory>
#include <functional>

#include <asio.hpp>

namespace jc
{
    // ~ TCP Connection class declaration
    class tcp_connection : public std::enable_shared_from_this<tcp_connection>
    {
    public:
        typedef std::shared_ptr<tcp_connection> pointer;

        static pointer create(asio::io_context &io_context)
        {
            return pointer(new tcp_connection(io_context));
        }

        asio::ip::tcp::socket& socket();

        void start();

    private:
        explicit tcp_connection(asio::io_context &io_context);
        void handle_write(const asio::error_code &error, size_t bytes_transferred);
        asio::ip::tcp::socket socket_;
        std::string message_;
    };
}


#endif //TCP_CONNECTION_H
