#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <string>
#include <fstream>
#include <iostream>

namespace w4 {
    class Message{
        std::string m_user;
        std::string m_reply;
        std::string m_tweet;
    public:
        Message(){}
        Message(std::ifstream& in, char c);
        bool empty() const;
        void display(std::ostream&) const;
    };
}

#endif
