#pragma once
#include "Item.h"

class Inventory {

public:
	Inventory(); // default constructor for array initiliazation 
	//Inventory(Item& item, int quantity); // initializes item and adds to inventory
	// i commented out this constructor because we should only have to instantiate
	// the inventory once, and there's no need to add an item at the same time
	~Inventory() = default; // default deconstructor 
	void addItem(Item* item, int quantity); // adds item to the inventory
	void removeItem(Item*, int); // removes item from inventory
	bool itemCheck(Item*); // verifies if the item is there

private:
	static const int maxCapacity = 50; // capacity of the inventory and quantity arrays
	Item** inventory; // inventory is an array of Item pointers
	int quantities[maxCapacity] = { 0 }; // the quantity of each of the items in inventory
	int inventoryCount = 0;
//	Item item; commented this out since I'm not sure why we have this
};