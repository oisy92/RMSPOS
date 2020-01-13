#pragma once
#include "pch.h"
class Menu
{
public:
	string getName();
	int getPrice();
	bool getvisible();
protected:
	string name;
	int price;
	bool visible;
};

