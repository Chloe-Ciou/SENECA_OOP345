#include "TaxableProduct.h"
using namespace std;
namespace w6{
    double TaxableProduct::m_taxRate[2] {0.13, 0.08};
    
    double TaxableProduct::getPrice() const{
        return Product::getPrice() * (1 + getTaxRate(m_taxableStatus));
    }
    void TaxableProduct::display(std::ostream& os) const{
        Product::display(os);
        os << left << (m_taxableStatus == 'H'? " HST": " PST");
    }
    double TaxableProduct::getTaxRate(char taxableStatus){
        return taxableStatus == 'H'? m_taxRate[0]: m_taxRate[1];
    }
    
    
}
