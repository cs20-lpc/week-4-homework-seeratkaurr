// TODO:  Course class methods implementation here.
#include "Course.hpp"

Course::Course() {
    courseName = "";
    location = "";
    next = nullptr;
}

Course::Course(const string& name, const string& loc) {
    courseName = name;
    location = loc;
    next = nullptr;
}
