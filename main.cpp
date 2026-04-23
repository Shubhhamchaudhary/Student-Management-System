#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "---------------------" << endl;
    }
};

// Add student
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    s.input();
    file << s.id << " " << s.name << " " << s.marks << endl;

    file.close();
    cout << "Student added successfully!\n";
}

// View all students
void viewStudents() {
    ifstream file("students.txt");
    Student s;

    while (file >> s.id >> s.name >> s.marks) {
        s.display();
    }

    file.close();
}

// Search student
void searchStudent() {
    ifstream file("students.txt");
    int searchId;
    bool found = false;

    cout << "Enter ID to search: ";
    cin >> searchId;

    Student s;
    while (file >> s.id >> s.name >> s.marks) {
        if (s.id == searchId) {
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found!\n";

    file.close();
}

// Delete student
void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    int deleteId;
    cout << "Enter ID to delete: ";
    cin >> deleteId;

    Student s;
    bool found = false;

    while (file >> s.id >> s.name >> s.marks) {
        if (s.id != deleteId) {
            temp << s.id << " " << s.name << " " << s.marks << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student deleted successfully!\n";
    else
        cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}