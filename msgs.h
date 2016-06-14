#pragma once

#include <string>
#include "zmq.hpp"

std::string get_str(const zmq::message_t& msg){
    return std::string((char*) msg.data(), msg.size());
}

zmq::message_t get_msg(const std::string& str){
    zmq::message_t msg(str.length());
    memcpy ((void *) msg.data (), str.c_str(), str.length());
    return msg;
}
