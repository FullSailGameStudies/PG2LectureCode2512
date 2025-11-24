#include "Menu.h"
#include <iostream>

//definition - the code for the function
void Menu::AddMenuItem(std::string itemToAdd)
{
	menuItems.push_back(itemToAdd);
}

void Menu::ShowMenu()
{
	std::cout << "\n\nFor loop\n";
	for (int i = 0; i < menuItems.size(); i++)
	{
		std::cout << menuItems[i] << "\n";
	}

	std::cout << "\n\nForeach (range-based) loop\n";
	for (std::string& menuItem : menuItems)
	{
		std::cout << menuItem << "\n";
	}

	std::cout << "\n\nIterator For loop\n";
	for (auto it = menuItems.begin(); it != menuItems.end(); it++)
	{
		std::cout << *it << "\n";
	}
}

void Menu::EraseItem(std::string itemToErase)
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		if (itemToErase == menuItems.at(i))
		{
			//erase REQUIRES an iterator
			menuItems.erase(menuItems.begin() + i);
			break;
		}
	}


	for (auto it = menuItems.begin(); it != menuItems.end(); it++)
	{
		if (itemToErase == *it)
		{
			//erase REQUIRES an iterator
			menuItems.erase(it);
			break;
		}
	}
}
