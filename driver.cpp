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

    void insertStudent(int id, string name, float gpa) {
        Student* newStudent = new Student(id, name, gpa);

        if (head == nullptr) {
            head = newStudent;
        }
        else {
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
    }

    bool deleteStudent(int id) {
        Student* temp = head;
        Student* prev = nullptr;

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return false;

        if (prev == nullptr) {
            head = head->next;
        }
        else {
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
            cout << "No students in the list.\n";
            return;
        }

        Student* temp = head;
        while (temp != nullptr) {
            cout << temp->id << " " << temp->name << " " << temp->gpa << " ";
            if (temp->courseHead == nullptr) {
                cout << "None";
            }
            else {
                cout << "\nCourses:\n";
                temp->displayCourses();
            }
            cout << "\n";
            temp = temp->next;
        }
    }

    int countStudents() {
        int count = 0;
        Student* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool addCourseToStudent(int id, string courseName, string location) {
        Student* student = searchStudent(id);
        if (student == nullptr)
            return false;

        student->addCourse(courseName, location);
        return true;
    }
};

int main() {
    LinkedList list;
    int choice;

    while (true) {
        cout << "\n1. Insert Student\n"
            << "2. Delete Student\n"
            << "3. Search Student\n"
            << "4. Display All\n"
            << "5. Count Students\n"
            << "6. Add a course\n"
            << "7. Exit\n"
            << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float gpa;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            list.insertStudent(id, name, gpa);

        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            if (list.deleteStudent(id))
                cout << "Deleted student with ID " << id << endl;
            else
                cout << "Student with ID " << id << " not found.\n";

        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            Student* student = list.searchStudent(id);
            if (student != nullptr) {
                cout << "Found: " << student->id << " " << student->name << " " << student->gpa << "\nCourses:\n";
                student->displayCourses();
            }
            else {
                cout << "Student not found.\n";
            }

        }
        else if (choice == 4) {
            cout << "Students in List:\n";
            list.displayAll();

        }
        else if (choice == 5) {
            cout << "Total students: " << list.countStudents() << endl;

        }
        else if (choice == 6) {
            int id;
            string courseName, location;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Course Name: ";
            getline(cin, courseName);
            cout << "Enter location: ";
            getline(cin, location);

            if (list.addCourseToStudent(id, courseName, location))
                cout << "Course added.\n";
            else
                cout << "Student not found.\n";

        }
        else if (choice == 7) {
            cout << "Exiting program.\n";
            break;

        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

