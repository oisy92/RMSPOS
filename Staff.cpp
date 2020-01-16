#include "pch.h"
#include "Staff.h"

void Staff::changeCredentials(string newUsername, string newPassword)
{
	username = newUsername;
	password = newPassword;
}

string Staff::getUsername()
{
	return username;
}

string Staff::getPassword()
{
	return password;
}

string Staff::getFirstName()
{
	return firstName;
}

string Staff::getLastName()
{
	return lastName;
}

string Staff::getInitials()
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



