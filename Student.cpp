// TODO:  Student class methods implementation here.
#include "Student.hpp"
#include <iostream>
using namespace std;

Student::Student(int id, string name, float gpa) {
	this->id = id;
	this->name = name;
	this->gpa = gpa;
	this->courseH = nullptr;
	this->next = nullptr;

}
void Student::addCourse(const string& courseName, const string& location) {
	Course* newCourse = new Course(courseName, location);
	if (courseH == nullptr) {
		courseH = newCourse;
	} else {
		Course* temp = courseH;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newCourse;
	}
}

	}	
	void Student::displayCourses() const {
		if (courseH == nullptr) {
			cout << "No courses enrolled." << endl;
			return;
		}

		Course* temp = courseH;
		while (temp != nullptr) {
			cout << "Course: " << temp->courseName << ", Location: " << temp->location << endl;
			temp = temp->next;
		}
	}
