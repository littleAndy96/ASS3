#pragma once
#include "Payment.h"

class CreditCardPayment :
	public Payment
{
public:
	double calculateAmountCharged();
	bool checkForApproval();
};

