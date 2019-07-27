#include "ApprovalAuthority.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// the randomization is seeded from the id of the payment
bool ApprovalAuthority::checkApproval()
{
	srand(time(0));
	double rando = rand() / RAND_MAX;

	std::cout << rando;
	return true;
}
