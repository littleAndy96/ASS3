#include "Sale.h"

int Sale::idCounter = 1;

Sale::Sale(string date,Time* time)
{
    saleItems = new Item* [maxSaleCapacity];

    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        saleItems[i] = new Item(0);
    }
    this->date = date;
    this->time = time;
    id = idCounter;
    ++idCounter;
}

Sale::~Sale()
{
    delete [] saleItems;
}

void Sale::addItemToSale(Item* item, int quantity)
{
	// first, look through the array to see if the item is there, in which case we just add to the quantity
	for (int i = 0; i < maxSaleCapacity; ++i) {
		// first check if inventory[i] is a nullptr because we don't want to call a method on a nullptr
		if (saleItems[i]->getItemId() != 0)
		{
			// now it's safe to call the method and check if we have an id match
			if (saleItems[i]->getItemId() == item->getItemId())
			{
				//if id matches, we just add to the quantity of that item
				quantities[i] += quantity;
                cout << "Amount before taxes: " << calculateRunningTotalBeforeTaxes() << endl;
                cout << "Amount after taxes: " << calculateRunningTotalWithTaxes() << endl;
				return; // we return here to avoid going to the second for loop
			}
		}
		
	}

	// if item is not found, we'll look for a pointer that points to 0, and add the item there
	for (int i = 0; i < maxSaleCapacity; ++i) {
		if (saleItems[i]->getItemId() == 0)
		{
			saleItems[i] = item;
			quantities[i] = quantity;
                cout << "Amount before taxes: " << calculateRunningTotalBeforeTaxes() << endl;
                cout << "Amount after taxes: " << calculateRunningTotalWithTaxes() << endl;            
			return;
		}
	}



}

void Sale::removeItemFromSale(Item* item, int quantity)
{
	for (int i = 0; i < maxSaleCapacity; ++i) {
		// first check if inventory[i] is a nullptr because we don't want to call a method on a nullptr
		if (saleItems[i] != nullptr)
		{
			// now it's safe to call the method and check if we have an id match
			if (saleItems[i]->getItemId() == item->getItemId())
			{
				// if id matches, we then make sure there's enough quantity to remove
				if (quantities[i] >= quantity)
				{
					quantities[i] -= quantity;
					// finally, if the quantity is now 0, then we remove the item from inventory
					if (quantities[i] == 0)
						saleItems[i] = nullptr;
                cout << "Amount before taxes: " << calculateRunningTotalBeforeTaxes() << endl;
                cout << "Amount after taxes: " << calculateRunningTotalWithTaxes() << endl;                        
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
double Sale::calculateRunningTotalBeforeTaxes()
{
    double runningTotal = 0;
    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        runningTotal += (saleItems[i]->getItemPrice()*quantities[i]);
    }
    runningTotalBeforeTaxes = runningTotal;
    return runningTotal;
}

double Sale::calculateRunningTotalWithTaxes()
{
    double taxedAmount = 0;
    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        taxedAmount += (saleItems[i]->getItemPrice()*quantities[i]);

    }
// must add the taxe rate to the amount 
    runningTotalWithTaxes = taxedAmount;

    return taxedAmount*1.19;
    
}
//must set the id for the payments but not sure how to proceed
void Sale::calculateAmountChargedWithMethod(string method)
{
    double taxedAmount = 0;
    for(int i = 0; i < maxSaleCapacity; ++i)
    {
        taxedAmount += (saleItems[i]->getItemPrice()*quantities[i]);

    }
    taxedAmount = taxedAmount * 1.19;

    if(method == "cash" || method == "CASH" || method == "Cash")
    {
        payment = new CashPayment(id,taxedAmount);
		this->amountCharged = payment->calculateAmountCharged(taxedAmount);
		cout << "Amount charged: " << amountCharged << '\n';
    }
    else if(method == "credit" || method == "CREDIT" || method == "Credit")
    {
        payment = new CreditCardPayment(id,taxedAmount);
		this->amountCharged = payment->calculateAmountCharged(taxedAmount);
		cout << "Amount charged: " << amountCharged << '\n';
    }
	else
	{
		payment = new DebitCardPayment(id, taxedAmount);
		this->amountCharged = payment->calculateAmountCharged(taxedAmount);
		cout << "Amount charged: " << amountCharged << '\n';
	}

}

bool Sale::completeTransaction()
{
	string method;
	cout << "Please input method of payment: " << '\n';
	cin >> method;
	calculateAmountChargedWithMethod(method);
	
	// check for quantities here
	// for loop for every item in saleItems
	// in for loop: itemCheck, removeiItem, etc.

	return this->isComplete;
}
