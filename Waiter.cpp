#include "pch.h"
#include "Waiter.h"

Waiter::Waiter(string newFirstName, string newLastName, int newSalary, int newAge, string newGender, string newAddress, string newEmploymentType)
{
	username = newFirstName;
	password = newLastName;
	firstName = newFirstName;
	lastName = newLastName;
	salary = newSalary;
	age = newAge;
	gender = newGender;
	address = newAddress;
	employmentType = newEmploymentType;
}
