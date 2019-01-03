#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H
#include "Product.h"
namespace w6 {
    class TaxableProduct: public Product{
        char m_taxableStatus{'N'};
        static double m_taxRate[2];
    public:
        TaxableProduct(){}
        TaxableProduct(std::string productNum, double price, char taxableStatus): Product(productNum, price), m_taxableStatus{taxableStatus}{}
        static double getTaxRate(char);
        double getPrice() const;
        void display(std::ostream& os) const;
    };
}
#endif 
