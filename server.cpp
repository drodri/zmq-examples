#include <zmq.hpp>
#include <string>
#include <iostream>
#include "msgs.h"

int main () {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");

    while (true) {
        zmq::message_t request;
        socket.recv(&request);
        std::string s = get_str(request);
        std::cout << "Received " << s << std::endl;

        zmq::message_t reply = get_msg("World");
        socket.send(reply);
    }
}