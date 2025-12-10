#pragma once
#include <string>
#include "Weapon.h"

// in C++, you can inherite from multiple classes
//	 
class Pistol : public Weapon
{
public:
	//Constructor
	//  IF you do not create a ctor, the compiler will give you a default ctor
	//  default ctor: has no parameters
	//  IF you do create any ctor, the compiler's ctor is not longer created
	Pistol(int damage, int range, const std::string& caliber, int rounds, int magSize);

	//getters/setters to be part of the public interface of the class
	//  the definition can be put in the header with the declaration
	//    for performance. the compiler might make them 'inline'
	// 
	//getters (accessors)
	//   return type matches the type of the field
	//   no parameters (usually)
	//   const (they do not modify the class)
	//	 usually just simply return the field
	int GetRounds() const
	{
		return rounds_;
	}
	int MagSize() const { return magSize_; }
	const std::string& Caliber() const {
		return caliber_;
	}

	//setters (mutators)
	//  void return types
	//  1 parameter (usually) to set the field with
	//  non-const b/c they modify the object
	void SetRounds(int rounds)
	{
		//can add some validation to the parameter
		//before we change the field
		if (rounds >= 0 && rounds <= magSize_)
		{
			//if it passes validation, we can change the field
			rounds_ = rounds;
		}
	}
	void MagSize(int magSize)
	{
		if (magSize > 0 && magSize < 30)
			magSize_ = magSize;
	}

	void Caliber(const std::string& caliber) {
		if (not caliber.empty())
			caliber_ = caliber;
	}

private:
	//encapsulate the data (hide it)
	// protect it from other code
	//FIELDS: (data)
	// naming convention:
	//	  camelCasingNamingConvention
	//	  m_iRounds, m_rounds, mRounds, _rounds, rounds_
	int rounds_, magSize_;
	std::string caliber_;

	void Info(int& rounds)
	{
		rounds = 20;//changing a variable in a different scope
		rounds_ = 10;//changing the object
		int rds = 56;//changing a local variable (smaller scope)
	}
};

