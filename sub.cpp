#include <zmq.hpp>
#include <string>
#include <iostream>
#include "msgs.h"

int main () {
    //  Prepare our context and subscriber
    zmq::context_t context;
    zmq::socket_t subscriber (context, ZMQ_SUB);
    subscriber.connect("tcp://localhost:5557");
    subscriber.connect("tcp://localhost:5558");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "H", 1);

    while (1) {
        zmq::message_t msg;
        subscriber.recv(&msg);
		auto s = get_str(msg);
        std::cout<<"Received "<< s <<std::endl;
    }
    return 0;
}