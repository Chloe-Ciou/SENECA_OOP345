
#include <iomanip>
#include "Utilities.h"
#include "Item.h"
using namespace std;

std::size_t Item::m_widthField = 0u;

Item::Item(const std::string& str){
    Utilities item;
    size_t startIndex = 0;
    bool valid = true;
    if(!str.empty()){
        try{
            m_name = item.extractToken(str, startIndex, valid);
            m_serialNumber = (unsigned int)std::stoi(item.extractToken(str, startIndex, valid));
            m_quantity = (unsigned int)std::stoi(item.extractToken(str, startIndex, valid));
            m_description = item.extractToken(str, startIndex, valid);
            m_widthField = item.getFieldWidth();
        }catch(const char* errMsg){
            cout << errMsg << endl;
        }
    }
}

const std::string& Item::getName() const{
    return m_name;
}
const unsigned int Item::getSerialNumber(){
    return m_serialNumber++;
}
const unsigned int Item::getQuantity(){
    return m_quantity;
}
void Item::updateQuantity(){
    if(m_quantity > 0u)
        m_quantity--;
}
void Item::display(std::ostream& os, bool full) const{
    if(!m_name.empty()){
        os << left << setw(m_widthField) << m_name << ' ';
        os << "[" << right << setfill('0') << setw(6) << m_serialNumber << "]" << setfill(' ');
        if(full){
            os << ' ' << "Quantity: " << left << setw(m_widthField) << m_quantity;
            os << right << " Description: " << m_description;
        }
        os << endl;
    }
}



