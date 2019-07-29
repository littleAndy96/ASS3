#include "Sale.h"

Sale::Sale()
{
    sale = new Item* [maxSaleCapacity];

    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        sale[i] = new Item(0);
    }

}

Sale::~Sale()
{
    delete [] sale;
}

void Sale::addItemToSale(Item* item, int quantity)
{
	// first, look through the array to see if the item is there, in which case we just add to the quantity
	for (int i = 0; i < maxSaleCapacity; ++i) {
		// first check if inventory[i] is a nullptr because we don't want to call a method on a nullptr
		if (sale[i] != nullptr)
		{
			// now it's safe to call the method and check if we have an id match
			if (sale[i]->getItemId() == item->getItemId())
			{
				//if id matches, we just add to the quantity of that item
				quantities[i] += quantity;
				return; // we return here to avoid going to the second for loop
			}
		}
		
	}

	// if item is not found, we'll look for a pointer that points to nullptr, and add the item there
	for (int i = 0; i < maxSaleCapacity; ++i) {
		if (sale[i] == nullptr)
		{
			sale[i] = item;
			quantities[i] = quantity;
			return;
		}
	}
}

void Sale::removeItemFromSale(Item* item, int quantity)
{
	for (int i = 0; i < maxSaleCapacity; ++i) {
		// first check if inventory[i] is a nullptr because we don't want to call a method on a nullptr
		if (sale[i] != nullptr)
		{
			// now it's safe to call the method and check if we have an id match
			if (sale[i]->getItemId() == item->getItemId())
			{
				// if id matches, we then make sure there's enough quantity to remove
				if (quantities[i] >= quantity)
				{
					quantities[i] -= quantity;
					// finally, if the quantity is now 0, then we remove the item from inventory
					if (quantities[i] == 0)
						sale[i] = nullptr;
					return;
				}
				// when there is not enough quantity to remove:
				else {
					cout << "You're trying to remove more than there are in the sale!\n";
					return;
				}
			}
		}

	}
	// here is what happens when the item is not found
	cout << "Item not found!\n";
	return;
}
// add all the items in the sale * the amount 
double Sale::getRunningTotalBeforeTaxes(Sale* sale)
{
    double amountCharged = 0;
    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        amountCharged += (sale[i]->getItemPrice()*quantities);
    }
    return amountCharged;
}

double Sale::getRunningTotalWithTaxes(Sale* sale)
{
    double amountCharged = 0;
    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        amountCharged += (sale[i]->getItemPrice()*quantities);

    }
// must add the taxe rate to the amount 
    return amountCharged*Item::taxRate;
    
}
//must set the id for the payments but not sure how to proceed
double Sale::getRunningTotalWithMethod(Sale* sale,string method)
{
    double amountCharged = 0;
    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        amountCharged += (sale[i]->getItemPrice()*quantities);

    }
    amountCharged = amountCharged * 1.19;

    if(method == "cash" || method == "CASH" || method == "Cash")
    {
        CashPayment(id,amountCharged);
    }
    else if(method == "credit" || method == "CREDIT" || method == "Credit")
    {
        CreditCardPayment(id,amountCharged);
    }
    else {
        DebitCardPayment(id,amountCharged)
    }
}

bool Sale::completeTransaction(Sale* sale)
{
    

}