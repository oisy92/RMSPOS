#pragma once
#include "pch.h"
#include "Menu.h"

class Entree : public Menu
{
public:
	Entree(string newName, int newPrice, bool newVisible);
};