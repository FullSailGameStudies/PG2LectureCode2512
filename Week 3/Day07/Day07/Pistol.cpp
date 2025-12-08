#include "Pistol.h"

Pistol::Pistol(const std::string& caliber, int rounds, int magSize) :
	//member initialization list
	caliber_(caliber),
	rounds_(rounds),
	magSize_(magSize)
{
	//caliber_ = caliber;
	//rounds = rounds_; //backwards! wrong!
	//magSize_ = magSize;
}
