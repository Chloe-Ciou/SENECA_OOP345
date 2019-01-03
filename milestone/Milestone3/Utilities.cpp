
#include "Utilities.h"
using namespace std;

char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(std::size_t widthField){
    m_widthField = widthField;
}

size_t Utilities::getFieldWidth() const{
    return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    string temp = str.substr(next_pos);
    
    //Reporting an exception if there are two delimiters with no token between them.
    if(temp[0] == m_delimiter)
        throw "No Token Between";
    
    size_t endIndex = temp.find(m_delimiter);
    if(endIndex != string::npos){
        more = true;
        temp = temp.substr(0, endIndex);
        next_pos += (endIndex + 1);
        m_widthField = m_widthField < temp.length()? temp.length(): m_widthField;
    }else
        more = false;
    return temp;
}

const char Utilities::getDelimiter() const{
    return m_delimiter;
}

