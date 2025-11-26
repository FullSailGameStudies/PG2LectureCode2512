#include "FullSailCourse.h"

void FullSailCourse::GetGrades(std::vector<float>& course)
{
	for (int i = 0; i < 10; i++)
	{
		course.push_back(rand() % 10001 / 100.f);
	}
}
