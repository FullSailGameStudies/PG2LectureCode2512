#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int damage, int range, bool serrated, int length) :
		Weapon(damage, range),
		serrated_(serrated),
		length_(length)
	{
	}

	int Length() const { return length_; }
	bool Serrated() const { return serrated_; }

	void Length(int length)
	{
		if (length > 0 && length <= 12)
		{
			length_ = length;
		}
	}
	void Serrated(bool serrated)
	{
		serrated_ = serrated;
	}
private:
	bool serrated_;
	int length_;

};

