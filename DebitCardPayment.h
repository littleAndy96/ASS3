#pragma once
#include "Payment.h"
#include "ApprovalAuthority.h"

class DebitCardPayment :
	public Payment
{
public:
	DebitCardPayment(int id, double TotalWithTaxes);
	~DebitCardPayment();
	double calculateAmountCharged(double totalWithTaxes);
	bool checkIfApproved();
private:
	ApprovalAuthority approvalAuthority;
};

