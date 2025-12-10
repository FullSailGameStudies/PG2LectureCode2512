#pragma once
class Weapon
{
public:
	Weapon(int damage, int range)
		: damage_(damage), range_(range)
	{
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

