#include <iostream>
#include <vector>
#include <string>
#include "Calculator.h"
#include "Console.h"
#include "Input.h"
#include <Menu.h>

int AddOne(int localNumber)
{
    return localNumber + 1;
}

void print(const std::vector<std::string>& names)
{
    std::cout << "----NAMES----\n";
    int index = 1;
    for (std::string name : names)
        std::cout << index++ << ". " << name << "\n";
}

void Sample()
{
    int w = Console::GetWindowWidth(), h = Console::GetWindowHeight();
    int x, y;
    int r, g, b;
    while (true)
    {
        x = rand() % w;
        y = rand() % h;
        r = rand() % 255;
        Console::SetBackgroundColor(r, 0, 0);
        Console::SetCursorPosition(x, y);
        Console::Write(" ");
    }
    Console::Reset();
}


//write a method to randomly fill the screen with red blocks
//Console::SetCursorPosition to move the cursor
//SetBackgroundColor to set the color
//Write or cout to print a space
void RandomColors()
{
    int w = Console::GetWindowWidth();
    int h = Console::GetWindowHeight();
    int x, y;
    int red;//0-255
    while (true)
    {
        x = rand() % w;
        y = rand() % h;
        Console::SetCursorPosition(x, y);
        red = rand() % 256;
        Console::SetBackgroundColor(red, 0, 0);
        Console::Write(" ");
    }
    Console::Reset();
}

int main()
{
    // rand() - generates a random # from 0 - 32767
    //how to limit a number to a specific range?
    // % num returns the remainder after dividing by num
    // range: 0 - num-1
    //0 - 100
    // % 101

    Console::ResizeWindow(100, 25);
    //RandomColors();

    Menu cafe;
    cafe.AddMenuItem("coffee");
    cafe.AddMenuItem("tea");
    cafe.AddMenuItem("blueberry muffins");
    cafe.AddMenuItem("bagel");//index 3
    cafe.AddMenuItem("bacon");
    cafe.ShowMenu();
    cafe.EraseItem("Bagel");
    cafe.ShowMenu();

    Menu mcDs;
    mcDs.AddMenuItem("McGriddle");
    mcDs.AddMenuItem("McMuffin");


    Input::PressEnter("Press enter to continue...", true);

    //Input and Console examples   
    // 
    //std::string myName = Input::GetString("What is your name?");
    //int minAge = 0, maxAge = 120;
    //int age = Input::GetInteger("What is your age?", minAge, maxAge);
    Console::Write("Hello Gotham.\t");
    Console::Write("Hello PG2!", ConsoleColor::Red, ConsoleColor::Yellow);
    Console::SetCursorPosition(5, 10);
    Console::WriteLine("Hello Gotham.");
    Console::SetCursorLeft(15);
    Console::WriteLine("Hello PG2!", ConsoleColor::Yellow, ConsoleColor::Red);
    Input::PressEnter("Press enter to continue...", true);

    /*
      Calling a method
        use the methods name.
        1) if the method needs data (i.e. has parameters), you must pass data to the method that matches the parameter types
        2) if the method returns data, it is usually best to store that data in a variable on the line where you call the method.

    */

    /*
        ╔══════════════════════════╗
        ║Parameters: Pass by Value.║
        ╚══════════════════════════╝

        Copies the value to a new variable in the method.

        For example, the AddOne method has a parameter called localNumber. localNumber is a variable that is local ONLY to the method.
        The value of the variable in main, number, is COPIED to the variable in AddOne, localNumber.

    */
    int number = 5;
    int plusOne = AddOne(number);

    //Examples:
    //  calling a static method, prefix with the class name...
    double factor = Calculator::mult(5, 3);

    //calling a non-static method, use the variable...
    Calculator t1000;
    int diff = t1000.minus(7, 2);


    /*
        CHALLENGE:

            Add an isEven method to the calculator.
            It should take 1 parameter and return a bool.

            Call the method on the t1000 calculator instance and print the results.

    */



    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Creating a vector  ]

        vector<T>  - the T is a placeholder for a type.

        When you want to create a vector variable, replace T with whatever type of data you want to store in the vector.



        [  Adding items to a vector  ]

        There are 2 ways to add items to a vector:
        1) on the initializer.
        2) using the push_back(item) method.
    */
    std::vector<std::string> names { "Batman", "Bruce Wayne", "The Best" };
    names.push_back("The Greatest Detective");
    names.push_back("The Bat");
    names.push_back("The Joker");
    names.push_back("Bane");
    names.push_back("Poison Ivy");


    /*
        CHALLENGE:

            Create a vector that stores floats. Call the variable grades.
            Add a few grades to the grades vector.

    */



    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Looping over a vector  ]

        You can loop over a vector with a for loop with iterators or a range-based for loop.

    */
    // begin() -- returns an iterator pointing to the first element
    // end() – returns an iterator pointing to the element AFTER the last element
    std::cout << "--- for loop:\n";
    for (size_t i = 0; i < names.size(); i++)
    {
        std::cout << names[i] << "\n";
    }
    std::cout << "\n\n";


    std::cout << "--- for loop with iterators:\n";
    for (auto i = names.begin(); i != names.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
    std::cout << "\n\n";

    std::cout << "--- Range-based for loop:\n";
    for (auto& name : names)
        std::cout << name << std::endl;
    std::cout << "\n\n";

    /*
        CHALLENGE:

            loop over the grades vector and print out each grade

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(names);

    std::cout << "\nerase the 5th item (" << names[4] << ")\n";
    names.erase(names.begin() + 4); //the position is the 4th item AFTER the first element. in other words, the 5th item.
    print(names);

    std::cout << "\nerase the 3rd item (" << names[2] << ") up to but not including the 5th item (" << names[4] << ")\n";
    std::vector<std::string>::iterator start = names.begin() + 2;//start at the 3rd item.
    std::vector<std::string>::iterator end = start + 2;//ends at the 5th item. 
    names.erase(start, end);//erases elements 3 and 4 but stops at the 5th.
    print(names);


    names.clear();
    std::cout << "\nclear all elements\n";
    print(names);



    /*

        CHALLENGE:

            Using the vector of grades you created.
            Remove the last item in the vector.
            Print the grades.

    */





    /*
        BOSS CHALLENGE:

            1) Add an Average method to the calculator class to calculate the average of a vector.
            2) Call the Average method on the t1000 variable and pass your grades vector to the method.
            3) print the average that is returned.

    */

}
