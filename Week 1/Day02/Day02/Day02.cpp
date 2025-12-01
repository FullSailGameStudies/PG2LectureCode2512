#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"

const double pi = 3.14159;
const int NOT_FOUND = -1;

//default parameter
bool postFix(std::string& hero, int universe = 0)
{
	srand((unsigned int)time(NULL));
	int postFixNumber;
	if (universe == 0)
		postFixNumber = rand() % 1000;
	else
		postFixNumber = universe;
	hero = hero + "-" + std::to_string(postFixNumber);
	return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
	//scores.push_back(5); //not allowed because it is marked as const
	float sum = 0;
	for (auto score : scores)
		sum += score;

	return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
	std::cout << "----SCORES----\n";
	int index = 1;
	for (int score : scores)
		std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
	//size() - # of items in the vector
	//capacity() - how big the internal array is
	//fuel tank in your car
	//size() <= capacity()
	std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//pass by reference (ALIAS)
//  - prevents a copy (performance)
//  - allows access to a variable in a different scope
void AddMe(int& num)
{
	num++;
}
void RandomMinMax(int& min, int& max)
{
	min = rand();
	max = rand();
}
//void AddMe(int me)//pass by value (COPY)
//{
//
//}

//when to use pass by reference?
// - for class types for performance (to prevent a copy)
// - if you need to access the other scope to update it

int main()
{
	int n = 5;
	AddMe(n);
	//only set the reference when you create the variable
	int& nRef = n;
	nRef = 10;
	int n2 = 20;
	nRef = n2;//copy n2 to nRef (n)
	std::cout << n << "\n";
	/*
		╔══════════════════════════════╗
		║Parameters: Pass by Reference.║
		╚══════════════════════════════╝
		Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

		NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
			This is because the parameter is actually just a new name for the other variable.
	*/
	std::string spider = "Spiderman";
	bool isEven = postFix(spider);//universe = 0
	isEven = postFix(spider, 644);//universe = 644
	std::string evenResult = (isEven) ? "TRUE" : "FALSE";
	std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


	/*
		CHALLENGE 1:

			Write a method to fill the vector of floats with grades.
			1) pass it in by reference
			2) add 10 grades to the vector
			3) call the method to fill
			4) print the vector in main

	*/
	std::vector<float> grades;
	FullSailCourse pg2;
	const FullSailCourse pg1;//can ONLY call const functions on this object
	//pg1.SetCourseName("PG1");
	pg2.SetCourseName();// "PG2 2512");
	pg2.GetGrades(grades);
	pg2.PrintGrades(grades);



	/*
		╔══════════════════╗
		║ const parameters ║
		╚══════════════════╝
		const is short for constant. It prevents the variable from being changed in the method.

		This is the way you pass by reference and prevent the method from changing the variable.
	*/
	std::vector<int> highScores;
	highScores.reserve(10);
	printInfo(highScores);//size: 0  capacity: 0
	for (int i = 0; i < 10; ++i)
	{
		highScores.push_back(rand() % 5000);
		printInfo(highScores);//size: ?  capacity: ?
	}
	float avg = average(highScores);



	/*
		CHALLENGE 2:

			Write a method to calculate the stats on a vector of grades
			1) create a method to calculate the min, max.
				pass the grades vector as a const reference.
				Use ref parameters for min and max.
			2) call the method in main and print out the min, max.

	*/
	float minGrade, maxGrade;
	pg2.CalculateStats(grades, minGrade, maxGrade);
	std::cout << "\n\nMin Grade: " << minGrade << "\nMax Grade: " << maxGrade << "\n\n";





	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝

		[  Removing from a vector  ]

		clear() - removes all elements from the vector
		erase(position) - removes the element at the position
		erase(starting position, ending position) - removes a range of elements. the end position is not erased.

	*/
	print(highScores);

	//erase all scores < 2500
	for (int i = 0; i < highScores.size(); i++)
	{
		if (highScores[i] < 2500)
		{
			highScores.erase(highScores.begin() + i);
			i--;
		}
	}
	//OR....
	for (int i = 0; i < highScores.size(); )
	{
		if (highScores[i] < 2500)
		{
			highScores.erase(highScores.begin() + i);
		}
		else//increment when we do NOT erase
			i++;
	}
	//OR...
	for (int i = highScores.size() - 1; i >= 0; i--)
	{
		if (highScores[i] < 2500)
		{
			highScores.erase(highScores.begin() + i);
		}
	}
	//OR...
	for (auto it = highScores.begin(); it != highScores.end();)
	{
		if (*it < 2500)
		{
			it = highScores.erase(it);
		}
		else//increment when we do NOT erase
			it++;
	}
	print(highScores);



	/*
		CHALLENGE 3:

			Using the vector of grades you created.
			Remove all the failing grades (grades < 59.5).
			Print the grades.
	*/





	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝


		size(): # of items that have been ADDED
		capacity(): length of the internal array
		reserve(n): presizes the internal array
	*/
	std::vector<int> scores;
	scores.reserve(10); //makes the internal array to hold 10 items.

	printInfo(scores);
}