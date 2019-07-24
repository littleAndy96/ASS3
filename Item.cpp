#include "Item.h"

using namespace std;

double Item::taxRate = 0.15;

Item::Item(int id) : id(id) {
	itemPrice = 0;
}
Item::Item(int id, double itemPrice, string name) : id(id), productName(name) {
	this->itemPrice = itemPrice;
	this->taxRate = taxRate;
}
void Item::setItemPrice(double itemPrice) {
	this->itemPrice = itemPrice;
}
void Item::setTaxRate(double taxRate) {
	Item::taxRate = taxRate;
}
double Item::getItemPrice() const {
	return this->itemPrice;
}
double Item::getTaxRate() {
	return Item::taxRate;
}
int Item::getItemId() const
{
	return this->id;
}
double Item::getItemTaxed() {
	double total;
	total = this->itemPrice * this->taxRate;
	return total;
}
double Item::getTaxOfItem() {
	return this->itemPrice * this->taxRate;
}

string Item::getItemName()
{
	return this->productName;
}
