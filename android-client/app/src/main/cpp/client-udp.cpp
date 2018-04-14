//
// Created by viewsharp on 12.04.18.
//

#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace boost::asio;

io_service service;
ip::udp::endpoint ep( ip::address::from_string("127.0.0.1"), 8001);
void sync_echo(std::string msg)
{
    ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), 0) );
    sock.send_to(buffer(msg), ep);
    char buff[1024];
    ip::udp::endpoint sender_ep;
    int bytes = sock.receive_from(buffer(buff), sender_ep);
    std::string copy(buff, bytes);
    std::cout << "server echoed our " << msg << ": "<< (copy == msg ? "OK" : "FAIL") << std::endl;
    sock.close();
}
int main()
{
    std::string buf;
    while (std::cin>>buf) {
        sync_echo(buf);
    }
}