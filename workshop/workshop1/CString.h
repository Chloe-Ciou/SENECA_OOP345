
#ifndef W1_CSTRING_H
#define W1_CSTRING_H
#include <iostream>

namespace w1{
    class CString{
        char *m_str;
        const unsigned MAX;
    public:
        CString(const char* str = nullptr);
        CString(const CString&) = delete;
        CString& operator=(const CString&) = delete;
        void display(std::ostream& os) const;
        virtual ~CString();
    };
    std::ostream& operator<<(std::ostream& os, const CString& CString);
}

#endif /* W1_CSTRING_H */
