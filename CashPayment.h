#pragma once
#include "Payment.h"

class CashPayment : public Payment
{
public:
	CashPayment(int id, double totalWithTaxes);
	~CashPayment();
	double calculateAmountCharged(double totalWithTaxes);
	bool checkForApproval();
private:

};

