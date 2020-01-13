#pragma once
#include "Staff.h"
class Waiter : public Staff
{
public:
	Waiter(string newFirstName, string newLastName, int newSalary, int newAge, string newGender, string newAddress, string newEmploymentType);
	static vector<Waiter> waitersVector;
};

