#include "pch.h"
#include "Staff.h"

void Staff::changeCredentials(string newUsername, string newPassword)
{
	username = newUsername;
	password = newPassword;
}

string Staff::getUsername() const
{
	return username;
}

string Staff::getPassword() const
{
	return password;
}

string Staff::getFirstName() const 
{
	return firstName;
}

string Staff::getLastName() const
{
	return lastName;
}

string Staff::getInitials() const 
{
	string firstInitial(1, firstName[0]);
	string secondInitial(1, lastName[0]);

	transform(firstInitial.begin(), firstInitial.end(), firstInitial.begin(), ::toupper);
	transform(secondInitial.begin(), secondInitial.end(), secondInitial.begin(), ::toupper);

	return firstInitial + secondInitial;
}

string Staff::generateID()
{
	int range = 100000 - 10000 + 1;
	int num = rand() % range + 10000;

	return to_string(num);
}



