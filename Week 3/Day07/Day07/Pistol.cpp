#include "Pistol.h"

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
