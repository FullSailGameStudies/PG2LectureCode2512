#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	//declaration - function signature
	void AddMenuItem(std::string itemToAdd);

	//add a method to show the menu
	void ShowMenu();

	void EraseItem(std::string itemToErase);

private:
	std::vector<std::string> menuItems;
};

