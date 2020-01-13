#pragma once
#include "pch.h"
#include "Staff.h"
using namespace std;
class Admin : public Staff
{
public:
	Admin(string newFirstName, string newLastName, int newSalary, int newAge, string newGender, string newAddress, string newEmploymentType);
	static vector<Admin> adminsVector;

};
