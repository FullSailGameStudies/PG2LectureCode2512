#include "Inventory.h"

Inventory::Inventory(const std::vector<Pistol>& items) :
	maxSize_(items.size()),
	items_(items)
{
	//items_ = items;
}

Inventory::Inventory(int maxSize, const std::vector<Pistol>& items) :
	maxSize_(maxSize),
	items_(items)
{
}
