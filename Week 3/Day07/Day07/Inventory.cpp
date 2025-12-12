#include "Inventory.h"

Inventory::Inventory(const std::vector<Weapon*>& items) :
	maxSize_(items.size()),
	items_(items)
{
	//items_ = items;
}

Inventory::Inventory(int maxSize, const std::vector<Weapon*>& items) :
	maxSize_(maxSize),
	items_(items)
{
}

void Inventory::AddItem(Weapon* wpn)
{
	items_.push_back(wpn);
}

void Inventory::ShowItems()
{
	for (int i = 0; i < items_.size(); i++)
	{
		items_[i]->ShowMe();
	}
}
