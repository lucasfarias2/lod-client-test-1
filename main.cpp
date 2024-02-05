#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        std::string server_address = "127.0.0.1";
        tcp::socket socket(io_context);
        tcp::resolver resolver(io_context);
        boost::asio::connect(socket, resolver.resolve(server_address, "1234"));

        std::cout << "Connected to the server. Enter messages to send:\n";

        std::string message;
        while (std::getline(std::cin, message)) {
            message += "\n";
            boost::asio::write(socket, boost::asio::buffer(message));
            std::cout << "Message sent. Enter another message:\n";
        }
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
