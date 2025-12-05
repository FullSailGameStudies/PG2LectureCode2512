// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include "Console.h"
#include "Input.h"
#include <iomanip>


enum class Weapon
{
	Sword, Axe, Spear, Mace
};

void PrintGrades(const std::map<std::string, double>& grades)
{
	Console::WriteLine("\n\nDCU Grades", ConsoleColor::Cyan);
	for (auto& [student, grade] : grades)
	{
		std::cout << std::setw(7) << std::left << student << " ";
		Console::SetForegroundColor(
			(grade < 59.5) ? ConsoleColor::Red :
			(grade < 69.5) ? ConsoleColor::Yellow :
			(grade < 79.5) ? ConsoleColor::Blue :
			(grade < 89.5) ? ConsoleColor::Magenta :
			ConsoleColor::Green
		);
		std::cout << std::setw(7) << std::right << grade << "\n";
		Console::Reset();
	}
}

int main()
{

	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Removing a key and its value from a map  ]

		erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
		erase(key) -- returns the # of items removed

	*/
	std::map<Weapon, int> dorasBackpack;
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	dorasBackpack[Weapon::Axe] = 3;

	size_t numberRemoved = dorasBackpack.erase(Weapon::Sword);
	if (numberRemoved > 0)
		std::cout << "The Swords were removed.\n";
	else
		std::cout << "Sword was not found in the map.\n";

	std::map<Weapon, int>::iterator found = dorasBackpack.find(Weapon::Axe);
	if (found != dorasBackpack.end())
	{
		dorasBackpack.erase(found);
		std::cout << "The Axes were removed.\n";
	}
	else
		std::cout << "Axe was not found in the map.\n";





	/*
		CHALLENGE 1:

					print the students and grades below
						use std::setw and std::left and std::right to format the output
					ask for the name of the student to drop from the grades map
						use std::getline or Input::GetString to get the user's input
					remove the student from the map
					print message indicating what happened
					if not found print an error message
					else print the map again and print that the student was removed


	*/
	srand((unsigned int)time(NULL));
	std::map<std::string, double> grades;
	grades["Bruce"] = rand() % 101;
	grades["Dick"] = rand() % 101;
	grades["Diana"] = rand() % 101;
	grades["Alfred"] = rand() % 101;
	grades["Clark"] = rand() % 101;
	grades["Arthur"] = rand() % 101;
	grades["Barry"] = rand() % 101;

	do
	{
		PrintGrades(grades);

		std::string student = Input::GetString("Student to drop: ");
		if (student.empty()) break;

		for (char& c : student)
		{
			c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
		}
		student[0] = std::toupper(student[0]);


		auto studentIterator = grades.find(student);
		if (studentIterator == grades.end())
		{
			std::cout << student << " was not enrolled.\n";
		}
		else
		{
			std::cout << student << " had a grade of " << studentIterator->second << ". Dropping.\n";
			grades.erase(studentIterator);
		}

	} while (true);
}