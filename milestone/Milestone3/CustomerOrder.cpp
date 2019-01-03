
#include <iomanip>
#include <utility>
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(const std::string& record){
    Utilities custOrders;
    size_t startIndex = 0, itemStartIndex = 0;
    string temp = "";
    bool valid = true;
    
    if(!record.empty()){
        try{
            m_name = custOrders.extractToken(record, startIndex, valid);
            m_product = custOrders.extractToken(record, startIndex, valid);
            itemStartIndex = startIndex;
            while (valid) {
                temp = custOrders.extractToken(record, itemStartIndex, valid);
                m_cntItem++;
            }
            if(m_cntItem){
                m_lstItem = new ItemInfo*[m_cntItem];
                for(size_t i = 0; i < m_cntItem; ++i){
                    m_lstItem[i] = new ItemInfo(custOrders.extractToken(record, startIndex, valid));
                }
            }
            m_widthField = m_widthField < custOrders.getFieldWidth()? custOrders.getFieldWidth(): m_widthField;
        }catch(const char* errMsg){
            cout << errMsg << endl;
        }
    }
}

CustomerOrder::CustomerOrder(const CustomerOrder&){
    throw "Cannot make copies.";
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept{
    *this = move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src){
    if(this != &src){
        m_name = src.m_name;
        m_product = src.m_product;
        
        for(size_t i = 0; i < m_cntItem; ++i){
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
        }
        
        delete [] m_lstItem;
        m_lstItem = src.m_lstItem;
        m_cntItem = src.m_cntItem;
        src.m_name = "";
        src.m_product = "";
        src.m_cntItem = 0;
        src.m_lstItem = nullptr;
    }
    return *this;
}

CustomerOrder::~CustomerOrder(){
    for(size_t i = 0; i < m_cntItem; ++i)
        delete m_lstItem[i];
    delete [] m_lstItem;
}

bool CustomerOrder::getItemFillState(std::string itemName) const{
    for(size_t i = 0; i < m_cntItem; ++i){
        if(m_lstItem[i]->m_itemName == itemName)
            return m_lstItem[i]->m_fillState;
    }
    return true;
}

bool CustomerOrder::getOrderFillState() const{
    bool filled = true;
    for(size_t i = 0; i < m_cntItem && filled; ++i){
        if(!m_lstItem[i]->m_fillState)
            filled = false;
    }
    return filled;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os){
    for(size_t i = 0; i < m_cntItem; ++i){
        if(m_lstItem[i]->m_itemName == item.getName() && item.getQuantity()){
            item.updateQuantity();
            m_lstItem[i]->m_serialNumber = item.getSerialNumber();
            m_lstItem[i]->m_fillState = true;
            os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
        }else if(m_lstItem[i]->m_itemName == item.getName()){
            os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
        }
    }
}
void CustomerOrder::display(std::ostream& os) const{
    if(!m_name.empty()){
        os << m_name << " - " << m_product << endl;
        for(size_t i = 0; i < m_cntItem; ++i){
            os << "[" << setfill('0') << right << setw(6) << m_lstItem[i]->m_serialNumber << "]" << ' ' << setfill(' ');
            os << setw(m_widthField) << left << m_lstItem[i]->m_itemName <<  " - ";
            os << (m_lstItem[i]->m_fillState? "FILLED": "MISSING") << endl;
        }
        os << right;
    }
}

