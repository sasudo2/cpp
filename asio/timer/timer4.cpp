#include <iostream>
#include <asio.hpp>
#include <functional>

class printer{
    private:
    int count;
    asio::steady_timer t;
    public:
    printer(asio::io_context &io):t(io, asio::chrono::seconds(1)){
        count = 0;
        t.async_wait(std::bind(&print, this));
    }
    ~printer(){
        std::cout << "Final count is " << count << std::endl;
    }
    void print(){
        if(count < 5){
            std::cout << count << std::endl;
            count++;
            t.expires_at(t.expiry() + asio::chrono::seconds(1));
            t.async_wait(std::bind(&print, this));
        }
    }
};

int main(){
    asio::io_context io;
    printer p(io);
    io.run();
    return 0;
}