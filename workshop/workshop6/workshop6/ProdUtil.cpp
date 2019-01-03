#include "TaxableProduct.h"
#include "ProdUtil.h"
namespace w6{
    std::ostream& operator<<(std::ostream& os, const iProduct& iProduct){
        iProduct.display(os);
        os << std::endl;
        return os;
    }
    
    iProduct* readProduct(std::ifstream& f){
        std::string productNum = "";
        double price = 0.0;
        char newline = ' ';
        char taxableStatus;
        iProduct* copy = nullptr;
        getline(f, productNum, ' ');
        if(!productNum.empty()){
            f >> price;
            newline = f.get();
            if(newline == '\n')
                return new Product(productNum, price);
            else{
                f >> taxableStatus;
                f.ignore();
                if(taxableStatus == 'H' || taxableStatus == 'P')
                    return new TaxableProduct(productNum, price, taxableStatus);
                else
                    throw "Unrecognizable Tax Code!";
            }
        }
        return copy;
    }
}




