#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        const auto endpoints = resolver.resolve("127.0.0.1", "7666");
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        for (;;) {
            boost::array<char, 128> buf{};
            boost::system::error_code error;

            const size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof)
                break;
            else if (error)
                throw boost::system::system_error(error);

            std::cout.write(buf.data(), len);
        }
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
