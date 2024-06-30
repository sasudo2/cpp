#include <iostream>
#include <asio.hpp>

void print(const std::error_code& ){
    std::cout << "Hello World" << std::endl;
}

int main(){
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(5));
    t.async_wait(&print);
    io.run();
    return 0;
}