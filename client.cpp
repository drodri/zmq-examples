#include <zmq.hpp>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "msgs.h"

int main (){
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);
    socket.connect ("tcp://localhost:5555");

    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        zmq::message_t request = get_msg("Hello");
        socket.send(request);

        zmq::message_t reply;
        socket.recv (&reply);
        std::string s = get_str(reply);
        std::cout << "Received " << s << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}