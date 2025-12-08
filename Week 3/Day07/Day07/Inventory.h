#pragma once
#include <vector>
#include "Pistol.h"

//class declaration
//   what it can do (methods)
//   what describes it (data)
class Inventory
{
	//Encapsulation
	//  who can see it?
	//  in general, protect it
	//Access modifiers:
	//  public: ALL code can see it
	//  private: (default) ONLY* this class can see it
	//  protected: this class and all of its descendants
	// these sections can be in any order and any number of them
public:
	Inventory(int maxSize) : maxSize_(maxSize)	{}
	Inventory(const std::vector<Pistol>& items);
	Inventory(int maxSize, const std::vector<Pistol>& items);

	//alternate naming:
	//  not use the 'get' prefix
	int Count() const
	{
		return items_.size();
	}
	int MaxSize() const
	{
		return maxSize_;
	}


private:
	//create a Pistol class
	//  number of rounds, caliber, magSize
	std::vector<Pistol> items_;
	int maxSize_;
};

