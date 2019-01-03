#include <iostream>
#include <fstream>
#include <utility>
#include "Text.h"
using namespace std;

namespace w2{
    Text::Text(const string& fileName){
        ifstream f(fileName);
        
        if(f.is_open()){
            string tempStr;
            while (!f.eof()) {
                ++m_size;
                getline(f, tempStr);
            }
            if(m_size != 0u){
                m_str = new string[m_size];
                f.clear();
                f.seekg(0);
                for(size_t i = 0u; i < m_size; ++i){
                    getline(f, m_str[i]);
                }
            }
            f.close();
        }
    }
    
    Text::Text(const Text& text){
        *this = text;
    }
    
    Text::Text(Text&& text){
        *this = move(text);
    }
    
    Text& Text::operator=(const Text& text){
        if(this != &text){
            delete [] m_str;
            m_size = text.m_size;
            m_str = new string[m_size];
            for(size_t i = 0u; i < m_size; ++i){
                m_str[i] = text.m_str[i];
            }
        }
        return *this;
    }
    
    Text& Text::operator=(Text&& text){
        if(this != &text){
            string* tempStr = m_str;
            m_size = text.m_size;
            m_str = text.m_str;
            text.m_str = tempStr;
            text.m_size = 0u;
        }
        return *this;
    }
    
    Text::~Text(){
        delete [] m_str;
    }
    
    size_t Text::size() const{
        return m_size;
    }
}
