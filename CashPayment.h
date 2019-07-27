#pragma once
#include "Payment.h"

class CashPayment :
	public Payment
{
public:
	CashPayment(int id, double TotalWithTaxes);
	~CashPayment();
	double calculateAmountCharged(double TotalWithTaxes);
	bool checkForApproval();
private:

};

