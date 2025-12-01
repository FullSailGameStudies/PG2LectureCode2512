#include "FullSailCourse.h"
#include <iostream>

void FullSailCourse::GetGrades(std::vector<float>& course)
{
	for (int i = 0; i < 10; i++)
	{
		course.push_back(rand() % 10001 / 100.f);
	}
}

void FullSailCourse::PrintGrades(const std::vector<float>& course) const
{
    //courseName = "steev";
    std::cout << "\n\n" << courseName << "\n\n";
    for (const float& grade : course)
    {
        //grade += 5;//side effect
        std::cout << grade << "\n";
    }
    std::cout << "\n\n";
}

void FullSailCourse::CalculateStats(const std::vector<float>& course, float& min, float& max) const
{
    if (course.empty())
    {
        min = max = 0;
        return;
    }
    min = max = course[0];
    for (int i = 1; i < course.size(); i++)
    {
        if (min > course[i]) min = course[i];
        if (max < course[i]) max = course[i];
    }
}

void FullSailCourse::SetCourseName(const std::string& name)
{
    courseName = name;
}
