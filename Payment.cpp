#include "Payment.h"

Payment::Payment(int id)
	: id(id), amountCharged(0)
{
}

Payment::~Payment()
{
}

double Payment::calculateAmountCharged()
{
	return 0.0;
}

bool Payment::checkForApproval()
{
	return false;
}

double Payment::getAmountCharged() const
{
	return amountCharged;
}

bool Payment::getIsApproved() const
{
	return isApproved;
}
