#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H
#include <iomanip>
#include "iProduct.h"

namespace w6 {
    class Product: public iProduct{
        std::string m_productNum = "";
        double m_price {0.0};
    public:
        Product(){}
        Product(std::string productNum, double price): m_productNum{productNum}, m_price{price}{}
        double getPrice() const;
        void display(std::ostream&) const;
    };
}
#endif
