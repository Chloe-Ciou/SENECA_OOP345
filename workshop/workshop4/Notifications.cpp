#include <iostream>
#include <utility>
#include "Notifications.h"
using namespace std;

namespace w4 {
    Notifications::Notifications(){
        setNullptr();
    }
    
    Notifications::Notifications(const Notifications& srcNo){
        setNullptr();
        *this = srcNo;
    }
    
    Notifications& Notifications::operator=(const Notifications& srcNo){
        if(this != &srcNo){
            for(size_t i = 0; i < m_count; ++i){
                delete m_messages[i];
                m_messages[i] = nullptr;
            }
            m_count = srcNo.m_count;
            for(size_t i = 0; i < m_count; ++i){
                m_messages[i] = new Message(*(srcNo.m_messages[i]));
            }
        }
        return *this;
    }
    
    Notifications::Notifications(Notifications&& srcNo){
        setNullptr();
        *this = move(srcNo);
    }
    
    Notifications& Notifications::operator=(Notifications&& srcNo){
        if(this != &srcNo){
            Message* tempPtr[SIZE];
            size_t tempCount = m_count;
            m_count = srcNo.m_count;
            srcNo.m_count = tempCount;
            
            for(size_t i = 0; i < SIZE; ++i){
                tempPtr[i] = m_messages[i];
                m_messages[i] = srcNo.m_messages[i];
                srcNo.m_messages[i] = tempPtr[i];
            }
        }
        return *this;
    }
    
    Notifications::~Notifications(){
        for(size_t i = 0; i < m_count; ++i){
            delete m_messages[i];
        }
    }
    
    void Notifications::operator+=(const Message& msg){
        if(m_count < SIZE && !msg.empty()){
            m_messages[m_count++] = new Message(msg);
        }
    }
    
    void Notifications::display(std::ostream& os) const{
        for(size_t i = 0; i < m_count; ++i){
            m_messages[i]->display(os);
        }
    }
    
    void Notifications::setNullptr(){
        for(size_t i = 0; i < SIZE; ++i){
            m_messages[i] = nullptr;
        }
    }
}

