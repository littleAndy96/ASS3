#include "Item.h"
#include "Inventory.h"
#include "Payment.h"
#include "ApprovalAuthority.h"
#include "Sale.h"
#include "Time.h"

#include <iostream>

using namespace std;

int main() {

	Inventory* inventory = new Inventory();
	Item* item1 = new Item(10011, 3.50, "Watermelon");
	Item* item2 = new Item(10012, 3.50, "Milk");
	Item* item3 = new Item(10013, 4.50, "Bag of bagels");

	cout << item1->getItemPrice() << endl;
	cout << item1->getTaxRate() << endl;

	inventory->addItem(item1, 11);
	inventory->itemCheck(item1);
	inventory->addItem(item2, 5);
	inventory->addItem(item2, 1);
	inventory->itemCheck(item2);
	inventory->removeItem(item2, 7);
	inventory->removeItem(item3, 1);

	Time* t1 = new Time();
	t1->setTime(12, 55, 20);

	Sale* s1 = new Sale("1 January 2019", t1);
	s1->addItemToSale(item1, 1);
	s1->addItemToSale(item2, 103);
	s1->removeItemFromSale(item1, 2);
	s1->removeItemFromSale(item2, 1);
	s1->calculateAmountChargedWithMethod("cash");


	delete item1;
	delete inventory;

	return 0;
}
