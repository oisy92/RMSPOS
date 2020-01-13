#pragma once
#include "pch.h"
#include "Menu.h"

class Drink : public Menu
{
public:
	Drink(string newName, int newPrice, bool newVisible);
};

