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
    Course* courseHead;   
    Student* next;        

    Student(int id, string name, float gpa);

    void addCourse(const string& courseName, const string& location);
    void displayCourses() const;
};

#endif

