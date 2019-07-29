//Credit card payments: Credit card payments are only available for 
//amounts greater than $50. A 2% service charge is added to each payment.

#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment(int id, double totalWithTaxes) : Payment(id)
{
	amountCharged = calculateAmountCharged(totalWithTaxes);
	isApproved = checkForApproval(); // credit card have to get approved 
}
// Must add a 2% service charge to every credit card purchase
double CreditCardPayment::calculateAmountCharged(double totalWithTaxes)
{
	// assignment says that it has to be greater than $50 so is it include ?? AT
	return totalWithTaxes * 1.02;
	

}

bool CreditCardPayment::checkForApproval()
{
	if(amountCharged < 50){
		cout << "This " << getAmountCharged() << "is too low for a credit card payment" << endl;
		return false;
	}
	else 
	return ApprovalAuthority::checkApproval;
}
