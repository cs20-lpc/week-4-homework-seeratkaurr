// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"
using namespace std;

class Student {
public:
    int id;
    string name;
    float gpa;
    Course* courseH;     // Head of course list
    Student* next;

    Student(int id, string name, float gpa);
    void addCourse(const string& courseName, const string& location);
    void displayCourses() const;
};

#endif
