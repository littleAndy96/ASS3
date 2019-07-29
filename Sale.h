#pragma once
#include "Item.h"
#include "Inventory.h"
#include "Payment.h"
#include "CashPayment.h"
#include "CreditCardPayment.h"
#include "DebitCardPayment.h"
#include "Time.h"

class Sale
{
public:
	Sale(string date,Time* time);
	~Sale();
	void addItemToSale(Item* item, int quantity);
	void removeItemFromSale(Item*,int);
	double calculateRunningTotalBeforeTaxes();
	double calculateRunningTotalWithTaxes();
	double calculateRunningTotalWithMethod(string method);
	bool completeTransaction();
private:
	int id;
	static int idCounter;
	double runningTotalBeforeTaxes;
	double runningTotalWithTaxes;
	double amountCharged;
	Item** saleItems; // sale is an array of item pointers 
	//Sale* completedSale = new Sale[maxSaleCapacity]; // array of completed sales moved to registry
	static const int maxSaleCapacity = 1000;
	int quantities[maxSaleCapacity] = { 0 };
	string date;
	Time* time;
	Payment* payment;
};

