#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	void GetGrades(std::vector<float>& course);
	//const member functions prevent the method
	//  from changing fields of the class
	void PrintGrades(const std::vector<float>& course) const;

	const std::string& GetCourseName() const
	{
		return courseName;
	}
	void SetCourseName(const std::string& name = "PG2");
	void CalculateStats(const std::vector<float>& course, float& min, float& max) const;

private:
	std::string courseName;
};

