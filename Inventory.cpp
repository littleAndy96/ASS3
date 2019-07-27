#include "Inventory.h"
#include "Item.h"
#include <iostream>
/*
I think we should make a new dynamic array for every item we create to make it easier to add and remove
compared to having a large array and just stacking on that
 */

using namespace std;

Inventory::Inventory()
{
	inventory = new Item * [maxCapacity];
	// assign a default Item (id = 0) to all pointers in the array
	for (int i = 0; i < maxCapacity; ++i)
	{
		inventory[i] = new Item(0);
	}
	// the values of the quantities array were already set to 0
	// in the header for inventory class
}

// removed the other constructor as it was unnecessary

void Inventory::addItem(Item* item, int quantity) {
	// first, look through the array to see if the item is there, in which case we just add to the quantity
	for (int i = 0; i < maxCapacity; ++i) {
		// first check if inventory[i] is a nullptr because we don't want to call a method on a nullptr
		if (inventory[i] != nullptr)
		{
			// now it's safe to call the method and check if we have an id match
			if (inventory[i]->getItemId() == item->getItemId())
			{
				//if id matches, we just add to the quantity of that item
				quantities[i] += quantity;
				return; // we return here to avoid going to the second for loop
			}
		}
		
	}

	// if item is not found, we'll look for a pointer that points to nullptr, and add the item there
	for (int i = 0; i < maxCapacity; ++i) {
		if (inventory[i] == nullptr)
		{
			inventory[i] = item;
			quantities[i] = quantity;
			return;
		}
	}
}

void Inventory::removeItem(Item* item, int quantity) {
	for (int i = 0; i < maxCapacity; ++i) {
		// first check if inventory[i] is a nullptr because we don't want to call a method on a nullptr
		if (inventory[i] != nullptr)
		{
			// now it's safe to call the method and check if we have an id match
			if (inventory[i]->getItemId() == item->getItemId())
			{
				// if id matches, we then make sure there's enough quantity to remove
				if (quantities[i] >= quantity)
				{
					quantities[i] -= quantity;
					// finally, if the quantity is now 0, then we remove the item from inventory
					if (quantities[i] == 0)
						inventory[i] = nullptr;
					return;
				}
				// when there is not enough quantity to remove:
				else {
					cout << "You're trying to remove more than we have in stock!\n";
					return;
				}
			}
		}

	}
	// here is what happens when the item is not found
	cout << "Item not found!\n";
	return;
}

bool Inventory::itemCheck(Item* item) {
	for (int i = 0; i < maxCapacity; ++i) {
		if (inventory[i]->getItemId() == item->getItemId())
		{
			cout << inventory[i]->getItemName() << " quantity: " << quantities[i] << '\n';
			return true;
		}
	}
	// we will return false if we exit the for loop without finding the item
	cout << "Item with ID #" << item->getItemId() << " not found.\n";
	return false;
}
