#include <iostream>
#include "Student.hpp"
using namespace std;

class LinkedList {
private:
    Student* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert new student at the end
    void insertStudent(int id, string name, float gpa) {
        Student* newStudent = new Student(id, name, gpa);

        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
    }

    // Delete a student by ID
    bool deleteStudent(int id) {
        Student* temp = head;
        Student* prev = nullptr;

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return false;  // student not found

        if (prev == nullptr) {
            head = head->next;  // deleting head
        } else {
            prev->next = temp->next;
        }

        delete temp;
        return true;
    }

    Student* searchStudent(int id) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "N


