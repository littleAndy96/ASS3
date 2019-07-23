#include "Item.h"

class Inventory : public Item {

public:
    Inventory(); // default constructor for array initiliazation 
    Inventory(Item&, int); // initializes item and adds to inventory
    ~Inventory() = default; // default deconstructor 
    void addItem(Item&,int); // adds item to the inventory
    void removeItem(Item&,int); // removes item from inventory
    bool itemCheck(Item&); // verifies if the item is there

private:
    Inventory* inventory; // = new Inventory[1000];
    int inventoryCount = 0;
    Item item;
};