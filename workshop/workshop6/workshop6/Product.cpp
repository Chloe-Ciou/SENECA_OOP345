
#include "Product.h"
using namespace std;

namespace w6 {
    double Product::getPrice() const{
        return m_price;
    }
    void Product::display(std::ostream& os) const{
        os << right << setw(16) << m_productNum << setw(16) << setprecision(2) << m_price;
    }
}
