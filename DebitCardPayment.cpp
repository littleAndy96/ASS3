#include "DebitCardPayment.h"

DebitCardPayment::DebitCardPayment(int id, double runningTotalWithTaxes) 
	: Payment(id)
{
	amountCharged = calculateAmountCharged(runningTotalWithTaxes);
	isApproved = checkForApproval();
}

DebitCardPayment::~DebitCardPayment() = default;

double DebitCardPayment::calculateAmountCharged(double totalWithTaxes)
{
	return totalWithTaxes + 3.0;
}

bool DebitCardPayment::checkIfApproved()
{
	// sales above 1000 are not allowed. the assignment is not clear if
	// the 1000 dollar max is before or after the $3 surcharge.
	// we chose to do the test after applying the $3 surcharge.
	if (amountCharged > 1000)
		return false;
	else return approvalAuthority.checkApproval();
}
