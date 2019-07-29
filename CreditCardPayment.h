//Credit card payments: Credit card payments are only available for 
//amounts greater than $50. A 2% service charge is added to each payment.

#pragma once
#include "Payment.h"

class CreditCardPayment : public Payment{

public:
	CreditCardPayment(int id, double totalWithTaxes);
	~CreditCardPayment() = default;
	double calculateAmountCharged(double totalWithTaxes);
	bool checkForApproval();
private:
	ApprovalAuthority approvalAuthority;
};

