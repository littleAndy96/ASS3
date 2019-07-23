class Item{
    public:
        Item();
        Item(double itemPrice,double taxRate); 
        ~Item() = default; // default deconstructor 
        static void setTaxRate(double taxRate); // sets the tax rate of the item
        void setItemPrice(double itemPrice); // sets the price of the item
        static double getTaxRate(); // gets the tax rate
        double getItemPrice() const; // gets the price of the item
        double getItemTaxed(); // gets the total of the item * taxes
        double getTaxOfItem(); // gets the taxes applied on the item
    private:
        static double taxRate; // rate of the taxes
        double itemPrice; // price of an item

};