#pragma once

// the payment is only to be created when the Sale is being finalized.
// this class will generally be asked to return two things to the Sale:
// the amount charged, and if the payment was approved
class Payment
{
public:
	Payment(int id);
	~Payment();
	virtual double calculateAmountCharged();
	virtual bool checkForApproval();
	double getAmountCharged() const;
	bool getIsApproved() const;
protected:
	double amountCharged; // amountCharged is determined by the derived class
	bool isApproved; // isApproved is modified by the derived classes
private:
	int id;
};

