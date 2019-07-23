#include "Item.h"

#include <iostream>

using namespace std;

int main() {
    
    Item* item1 = new Item(100,0.15);

    cout << item1->getItemPrice() << endl;
    cout << item1->getTaxRate() << endl;
    
    delete item1;
    
    return 0;
}