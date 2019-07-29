#include "stdafx.h"
#include "ApprovalAuthority.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

ApprovalAuthority::ApprovalAuthority() = default;

ApprovalAuthority::~ApprovalAuthority() = default;

// the randomization is seeded from the id of the payment
bool ApprovalAuthority::checkApproval()
{
	srand(time(0));
	rand();
	double rando = static_cast<double>(rand()) / RAND_MAX;

	std::cout << rando << '\n';

	if (rando > 0.1)
		return true;
	else return false;
}
