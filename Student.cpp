#include "Student.hpp"
#include <iostream>
using namespace std;

Student::Student(int id, string name, float gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->courseHead = nullptr;
    this->next = nullptr;
}

void Student::addCourse(const string& courseName, const string& location) {
    Course* newCourse = new Course(courseName, location);
    if (courseHead == nullptr) {
        courseHead = newCourse;
    } else {
        Course* temp = courseHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newCourse;
    }
}

void Student::displayCourses() const {
    if (courseHead == nullptr) {
        cout << "No courses enrolled." << endl;
        return;
    }

    Course* temp = courseHead;
    while (temp != nullptr) {
        cout << "Course: " << temp->courseName << ", Location: " << temp->location << endl;
        temp = temp->next;
    }
}

