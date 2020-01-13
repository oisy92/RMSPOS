#pragma once
#include "pch.h"
#include "Menu.h"

class Dessert : public Menu
{
public:
	Dessert(string newName, int newPrice, bool newVisible);
};