#pragma once
#include "pch.h"

class Waiter;
class Admin;
class Staff
{
public:
	void changeCredentials(std::string newUsername, string newPassword);
	string getUsername() const;
	string getPassword() const;
	string getFirstName() const;
	string getLastName() const;
	string getInitials() const;
	string generateID();
protected:
	string username;
	string password;
	string firstName;
	string lastName;
	string gender;
	string address;
	string employmentType;
	int salary;
	int age;
	int clockin;
	int clockout;
	vector<vector<int>>workTimes;
};

