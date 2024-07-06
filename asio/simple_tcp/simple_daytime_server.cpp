#include <ctime>
#include <iostream>
#include <asio.hpp>
#include <array>

using asio::ip::tcp;

std::string get_current_time(){
  using namespace std;
  time_t t = time(0);
  return ctime(&t);
}

int main(){
  try{asio::io_context io;
  tcp::acceptor acceptor(io,  tcp::endpoint(tcp::v4(), 13));
  for(;;)
  {
    tcp::socket socket(io);
    acceptor.accept(socket);

    std::string message = get_current_time();
    std::error_code e;
    asio::write(socket, asio::buffer(message), e);
  }}
  catch(std::exception &a){
    std::cerr << a.what() << std::endl;
  }
  
}

