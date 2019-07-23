#include "Item.h"


double Item::taxRate = 0.15;

Item::Item(){
        itemPrice = 0;
}
Item::Item(double itemPrice,double taxRate){
        this->itemPrice = itemPrice;
        this->taxRate = taxRate;
}
void Item::setItemPrice(double itemPrice){
    this->itemPrice = itemPrice;
}
void Item::setTaxRate(double taxRate){
    Item::taxRate = taxRate;
}
double Item::getItemPrice() const{
    return this->itemPrice;
}
double Item::getTaxRate(){
    return Item::taxRate;
}
double Item::getItemTaxed(){
    double total;
    total = this->itemPrice * this->taxRate;
    return total;
}
double Item::getTaxOfItem(){
    return this->itemPrice * this->taxRate;
}