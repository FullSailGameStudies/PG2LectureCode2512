#pragma once
#include <iostream>
class Weapon
{
public:
	Weapon(int damage, int range)
		: damage_(damage), range_(range)
	{
	}

	//1. mark the base method as 'virtual'
	virtual int CalculateDamage() = 0 //pure virtual which makes Weapon abstract
	{
		std::cout << "\nWeapon Damage\n";
		return rand() % damage_;
	}

	int Damage() const { return damage_; }
	int Range() const { return range_; }

	void Damage(int dmg)
	{
		damage_ = dmg;
	}
	void Range(int rng)
	{
		range_ = rng;
	}
private:
	int damage_, range_;

};

