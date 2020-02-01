#include "pch.h"
#include "Menu.h"

string Menu::getName() const
{
	return name;
}

int Menu::getPrice() const
{
	return price;
}

bool Menu::getvisible() const
{
	return visible;
}
