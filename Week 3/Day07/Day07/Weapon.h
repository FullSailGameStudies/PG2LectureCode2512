#pragma once
#include <iostream>
class Weapon
{
public:
	Weapon(int damage, int range)
		: damage_(damage), range_(range)
	{
		numberOfWeapons++;
	}

	//non-static methods
	//  there is a hidden parameter called 'this'
	//  'this' is a pointer to the object it was called on
	//  can access non-static AND static members
	virtual void ShowMe()
	{
		Weapon* that = this;
		std::cout << "Damage: " << damage_ << " Range: " << range_;
	}

	//static methods
	//  do NOT have a 'this' parameter
	//  can ONLY access other static members
	static void Reporting()
	{
		//std::cout << "Damage: " << damage_ << " Range: " << range_;
		std::cout << "Number of weapons: " << numberOfWeapons << "\n";
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
	static int numberOfWeapons;
	int damage_, range_;

};

int Weapon::numberOfWeapons = 0;
