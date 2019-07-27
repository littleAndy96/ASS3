#include "Item.h"
#include "Inventory.h"
#include "Payment.h"
#include "ApprovalAuthority.h"

#include <iostream>

using namespace std;

int main() {
	ApprovalAuthority a1;
	a1.checkApproval(); 
	
	//UNFINISHED

	cout << '\n';

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


	delete item1;
	delete inventory;

	return 0;
}
