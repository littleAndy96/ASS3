#include "CashPayment.h"

CashPayment::CashPayment(int id, double totalWithTaxes)
	: Payment(id)
{
	amountCharged = calculateAmountCharged(totalWithTaxes);
	isApproved = checkForApproval(); 	// cash payments are always approved
}

CashPayment::~CashPayment() = default;

// calculate the amount charged, given that totals over 
// 200 dollars get a 5% rebate
double CashPayment::calculateAmountCharged(double totalWithTaxes)
{
	if (totalWithTaxes > 200.0)
		return 0.95 * totalWithTaxes;
	else return totalWithTaxes;
}

// cash payments are always approved
bool CashPayment::checkForApproval()
{
	return true;
}
