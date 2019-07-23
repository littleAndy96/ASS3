#include "Inventory.h"
#include "Item.h"
/*
I think we should make a new dynamic array for every item we create to make it easier to add and remove 
compared to having a large array and just stacking on that
 */


Inventory::Inventory(){

}
Inventory::Inventory(Item& item,int quantity){
    this->item = item;
    for (int i = 0; i < quantity; i++){
        inventory[inventoryCount] = this->item;
        inventoryCount++;
    }
}
void Inventory::addItem(Item& item,int quantity){
    this->item = item;
        for(int i = 0; i < quantity; i++){
            inventory[inventoryCount] = this->item;
            inventoryCount++;
        }
}
void Inventory::removeItem(Item& item,int quantity){
    this->item = item;
        for(int i = 0; i < quantity; i++){
            inventory[inventoryCount] = 0;
            inventoryCount--;
        }
}
bool Inventory::itemCheck(Item& item){
    if(item == this->item)
    return true;
    else return false;
}