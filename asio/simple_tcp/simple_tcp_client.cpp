
#include <asio.hpp>
#include <iostream>
#include <array>

using asio::ip::tcp;

int main(int argc, char *argv[])
{
  try
  {
    if(argc != 2)
    {
      std::cerr << "usage:: simple_datime_client localhost" << std::endl;

    }

    asio::io_context io;
    tcp::resolver resolver(io);
    tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");
    tcp::socket socket(io);
    asio::connect(socket, endpoints);
    for(;;)
    {
      std::array<char, 128> buf;
      std::error_code e;

      size_t len = socket.read_some(asio::buffer(buf), e);
      if(e == asio::error::eof)
      {
        break;
      }
      else if(e){
        throw std::system_error(e);
      }

      std::cout.write(buf.data(), len);
    }
  }
  catch(std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

}