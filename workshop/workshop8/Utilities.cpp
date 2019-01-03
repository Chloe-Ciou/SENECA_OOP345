
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers
        for(size_t i = 0; i < desc.size(); ++i){
            for(size_t j = 0; j < price.size(); ++j){
                if(desc[i].code == price[j].code){
                    Product* temp(new Product(desc[i].desc, price[j].price));
                    temp->validate();
                    priceList += temp;
                    delete temp;
                }
            }
        }
        return priceList;
    }
    
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for(size_t i = 0; i < desc.size(); ++i){
            for(size_t j = 0; j < price.size(); ++j){
                if(desc[i].code == price[j].code){
                    unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
                    temp->validate();
                    priceList += std::move(temp);
                }
            }
        }
        return priceList;
    }
}
