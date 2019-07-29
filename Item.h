#pragma once

#include <string>

using namespace std;

class Item {
public:
	Item(int id);
	Item(int id, double itemPrice, string name);
	~Item() = default; // default deconstructor 
	static void setTaxRate(double taxRate); // sets the tax rate of the item
	void setItemPrice(double itemPrice); // sets the price of the item
	static double getTaxRate(); // gets the tax rate
	int getItemId() const;
	double getItemPrice() const; // gets the price of the item
	double getItemTaxed(); // gets the total of the item * taxes
	double getTaxOfItem(); // gets the taxes applied on the item
	string getItemName(); // returns the product name
protected:
	static double taxRate; // rate of the taxes
private:
	const int id; // item id: can't be changed
	const string productName; // also known as the product description
	static double taxRate; // rate of the taxes
	double itemPrice; // price of an item

};
