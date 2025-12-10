#include "Pistol.h"
#include <iostream>

Pistol::Pistol(int damage, int range, const std::string& caliber, int rounds, int magSize) :
	//member initialization list
	//  call the base ctor here too
	Weapon(damage, range),
	caliber_(caliber),
	rounds_(rounds),
	magSize_(magSize)
{
	//caliber_ = caliber;
	//rounds = rounds_; //backwards! wrong!
	//magSize_ = magSize;
}

int Pistol::CalculateDamage()
{
	//How do I want to override the base method?
	// - FULLY OVERRIDE: do NOT call the base method
	// - EXTENSION OVERRIDE : call the base method
	std::cout << "\nPistol Damage\n";
	int baseDmg = Weapon::CalculateDamage();
	return baseDmg + rand() % 25;
}
