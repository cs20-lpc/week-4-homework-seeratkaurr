#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using namespace std;

class Course {
public:
    string courseName;  
    string location;
    Course* next;

    Course();
    Course(const string& name, const string& loc);
};

#endif

