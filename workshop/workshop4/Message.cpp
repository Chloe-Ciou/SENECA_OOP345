#include "Message.h"
using namespace std;

namespace w4 {
    Message::Message(std::ifstream& in, char c){
        
        if(!in.eof()){
            //Get a line of characters
            string Message;
            getline(in, Message, c);
            
            //i: index, start: starting index, count: how many characters
            size_t i = 0u, start = 0u, count = 0u;
            
            //get index of the first space in the string
            while (Message[i] != '\0' && Message[i] != ' ') {
                i++;
            }
            // check if the message is valid
            if(Message[i] != '\0'){
                m_user = Message.substr(start, i);
                
                //ignore leading white spaces
                while (Message[i] != '\0' && Message[i] == ' ') ++i;
                
                //get replay message
                if(Message[i] != '\0' && Message[i] == '@'){
                    start = ++i;
                    while (Message[i] != '\0' && Message[i] != ' ') {
                        i++;
                        count++;
                    }
                    m_reply = Message.substr(start, count);
                    ++i;
                }
                m_tweet = Message.substr(i, Message.size());
            }
        }
    }
    
    bool Message::empty() const{
        return m_tweet.empty();
    }
    
    void Message::display(std::ostream& os) const{
        if(!empty()){
            cout << "Message" << endl;
            cout << " User  : " << m_user << endl;
            if(!m_reply.empty())
                cout << " Reply : " << m_reply << endl;
            cout << " Tweet : " << m_tweet << endl << endl;
        }
    }
}

