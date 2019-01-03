
#include <iostream>
#include <cstring>
#include "CString.h"

using namespace std;

unsigned STORED = 3u;

namespace w1 {
    CString::CString(const char* str): MAX(STORED){
        if(str != nullptr){
            m_str = new char[MAX + 1];
            strncpy(m_str, str, MAX);
            m_str[MAX] = '\0';
        }else
            m_str = nullptr;
    }
    
    void CString::display(ostream& os) const{
        if(m_str != nullptr) cout << m_str;
    }
    
    CString::~CString(){
        delete [] m_str;
    }
    
    std::ostream& operator<<(ostream& os, const CString& CString){
        static unsigned cnt = 0u;
        os << cnt++ << ": ";
        CString.display(os);
        return os;
    }
}



