#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

const size_t SIZE = 10;

namespace w4 {
    class Notifications{
        Message* m_messages[SIZE];
        size_t m_count = 0u;
        //Seting every element points to nullptr
        void setNullptr();
    public:
        Notifications();
        Notifications(const Notifications&);
        Notifications& operator=(const Notifications&);
        Notifications(Notifications&&);
        Notifications& operator=(Notifications&&);
        virtual ~Notifications();
        void operator+=(const Message& msg);
        void display(std::ostream& os) const;
    };
}

#endif
