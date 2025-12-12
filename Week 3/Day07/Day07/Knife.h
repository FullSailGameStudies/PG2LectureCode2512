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
	int CalculateDamage() override
	{
		return Weapon::CalculateDamage();
	}
	void ShowMe() override
	{
		Weapon::ShowMe();
		std::cout << " Serrated: " << serrated_ << " Length: " << length_ << "\n\n";
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

