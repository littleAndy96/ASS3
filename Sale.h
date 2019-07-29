#pragma once
#include "Item.h"
#include "Inventory.h"
#include "Payment.h"

class Sale
{
public:
	Sale();
	~Sale();
	void addItemToSale(Item* item, int quantity);
	void removeItemFromSale(Item*,int);
	double getRunningTotalBeforeTaxes(Sale* sale);
	double getRunningTotalWithTaxes(Sale* sale);
	double getRunningTotalWithMethod(Sale* sale,string method);
	bool completeTransaction(Sale* sale);
private:
	double runningTotalBeforeTaxes;
	double runningTotalWithTaxes;
	double amountCharged;
	Item** sale; // sale is an array of item pointers 
	Sale* completedSale = new Sale[maxSaleCapacity]; // array of completed sales
	static const int maxSaleCapacity = 1000;
	int quantities[maxSaleCapacity] = { 0 };
};

