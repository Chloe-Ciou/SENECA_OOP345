
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item{
    std::string m_name = "";
    std::string m_description = "";
    unsigned int m_serialNumber {0u};
    unsigned int m_quantity {0u};
    static std::size_t m_widthField;
public:
    Item(){}
    Item(const std::string&);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
    virtual ~Item(){}
};

#endif

