#include <zmq.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "msgs.h"

int main () {
    zmq::context_t context;
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5558");

    while(1){
        auto m = get_msg("Hola");
        std::cout<<"Sending hola\n";
        publisher.send(m);
        m = get_msg("Adios");
        std::cout<<"Sending adios\n";
        publisher.send(m);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}