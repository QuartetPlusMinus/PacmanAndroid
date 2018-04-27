#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <unistd.h>
#include <ctime>
#include "cmake-build-debug/generated/service.pb.h"
#include "Service.h"


typedef unsigned long size_t;

using namespace std;
using namespace boost::asio;

static io_service service;
static char buff[1024];
static const unsigned short port = 31415;
static ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), port));

void client_session(string msg, ip::udp::endpoint& sender_ep);

int main() {
    Service service(port);
    service.run();


//    while ( true)
//    {
//        ip::udp::endpoint sender_ep;
//        std::cout<<sender_ep.address()<<std::endl;
//        int bytes = sock.receive_from(buffer(buff), sender_ep);
//        boost::thread( boost::bind(client_session, std::string(buff, bytes), sender_ep));
//
////        ip::udp::endpoint epp(ip::address::from_string(""), 1234);
//    }
//    return 0;
}


//void client_session(string msg, ip::udp::endpoint& sender_ep)
//{
//    std::cout<<sender_ep.address()<<':'<<sender_ep.port()<<std::endl;
//    std::cout<<msg<<std::endl;
//    sock.send_to(buffer(msg), sender_ep);
//}