#include <zmq.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "msgs.h"

int main () {
    zmq::context_t context;
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5557");

    while(1){
        auto m = get_msg("Hello");
        std::cout<<"Sending hello\n";
        publisher.send(m);
        m = get_msg("Bye");
        std::cout<<"Sending bye\n";
        publisher.send(m);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}