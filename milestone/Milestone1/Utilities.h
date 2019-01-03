
#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>

class Utilities{
    std::size_t m_widthField { 1u };
    static char m_delimiter;
public:
    void setFieldWidth(std::size_t);
    std::size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char delimiter){
        m_delimiter = delimiter;
    }
    const char getDelimiter() const;
    virtual ~Utilities(){}
};

#endif
