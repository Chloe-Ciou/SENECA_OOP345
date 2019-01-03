
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include "Item.h"

struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber {0u};
    bool m_fillState = false;
    
    ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder{
    std::string m_name = "";
    std::string m_product = "";
    unsigned int m_cntItem = {0u};
    ItemInfo** m_lstItem = nullptr;
    static size_t m_widthField;
public:
    CustomerOrder(){}
    CustomerOrder(const std::string& record);
    CustomerOrder(const CustomerOrder&);
    CustomerOrder(CustomerOrder&&) noexcept;
    CustomerOrder& operator=(const CustomerOrder&) = delete;
    CustomerOrder& operator=(CustomerOrder&&);
    virtual ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item& item, std::ostream&);
    void display(std::ostream&) const;
};

#endif
