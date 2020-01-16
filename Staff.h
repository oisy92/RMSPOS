#pragma once
#include "pch.h"

class Waiter;
class Admin;
class Staff
{
public:
	void changeCredentials(std::string newUsername, string newPassword);
	string getUsername();
	string getPassword();
	string getFirstName();
	string getLastName();
	string getInitials();
	string generateID();
protected:
	string username;
	string password;
	string firstName;
	string lastName;
	string gender;
	string address;
	string employmenttype;
	int salary;
	int age;
	int clockin;
	int clockout;
	vector<vector<int>>workTimes;
};

