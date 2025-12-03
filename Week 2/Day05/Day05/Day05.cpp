// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

const int NOT_FOUND = -1;

int LinearSearch(const std::vector<int>& nummies, int num)
{
    for (int i = 0; i < nummies.size(); i++)
    {
        if (num == nummies[i])
        {
            return i;
        }
    }
    return NOT_FOUND;//??
}
void FillGrades(const std::vector<std::string>& students,
    std::map<std::string, double>& course)
{
    for (auto& student : students)
    {
        //course[student] = rand() % 10001 / 100.0;
        //OR...
        std::pair<std::string, double> studentToAdd =
            std::make_pair(student, rand() % 10001 / 100.0);
        auto studentInserted = course.insert(studentToAdd);
        if (studentInserted.second == false)
            std::cout << student << " is already enrolled.\n";
    }
}
//add a method to print your grades map
//call the method in main to print it


int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int index = LinearSearch(numbers, searchNumber);
    if (index == NOT_FOUND)
    {
        std::cout << searchNumber << " was not found.\n";
    }
    else
        std::cout << searchNumber << " was found at index " << index << "\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map



    std::map<std::string,float> menu;
    //how to add data?
    //1) easy way  map[key] = value;
    menu["bacon"] = 4.99f;
    menu["egg sandwich"] = 7.49f;
    menu["egg sandwich"] = 7.99f;//overwrite any existing value

    //2) not-easy way map.insert(key-value pair)
    std::pair<std::string, float> menuPair = 
        std::make_pair("coffee", 2.99f);
    menu.insert(menuPair);
    //pair objects have a "first" and "second" parts
    menuPair.second = 3.99f;
    //first: iterator to the key-value pair in the map
    //second: whether it was inserted or not
    std::pair<std::map<std::string,float>::iterator,bool> wasInserted = menu.insert(menuPair);//?? does NOT replace an existing value
    if (wasInserted.second == false)
    {
        std::cout << "item was already on the menu.\n";
        std::cout << "Do you want to change the price?\n";
    }
    else
    {
        //first is an iterator to a key-value pair
        std::cout << wasInserted.first->second << "\n";
    }

    std::string menuItem = "pancakes";
    float price = menu[menuItem];
    std::cout << menuItem << " costs " << price << "\n";

    std::cout << "\n\nPG2 Cafe\n";
    for (auto it = menu.begin(); it != menu.end(); it++)
    {
        std::cout << it->first << "\t\t" << it->second << "\n";
    }
    std::cout << "\n\nPG2 Cafe\n";
    for (auto& kvp : menu)
    {
        std::cout << kvp.first << "\t\t" << kvp.second << "\n";
    }
    std::cout << "\n\nPG2 Cafe\n";
    //use structured binding
    for (auto& [itemName,itemPrice] : menu)
    {
        std::cout << itemName << "\t\t" << itemPrice << "\n";
    }


    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.

    */
    std::map<std::string, double> grades;
    std::vector<std::string> students = {
        "Garrett","Ray","Jedin","Braxton","Foster","Jacob","Audrey",
        "James","Jerry","Raymond","Marley","Gabriel","Sean",
        "Ryan","Whitney","Beavon","Jamichael","Teshantiy"
    };
    FillGrades(students, grades);






    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}