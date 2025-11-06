#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    int roll;
    string name, division, address;

public:
    void addStudent();
    void displayStudent();
    void deleteStudent();
    void modifyStudent();
};

// Add a new student
void Student::addStudent() {
    ofstream fout("student.txt", ios::app); // append mode
    cout << "\nEnter Roll Number: ";
    cin >> roll;
    cin.ignore(); // ignore newline

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Division: ";
    getline(cin, division);

    cout << "Enter Address: ";
    getline(cin, address);

    fout << roll << "," << name << "," << division << "," << address << "\n";
    fout.close();
    cout << "\nStudent added successfully!\n";
}

// Display a student's record by roll number
void Student::displayStudent() {
    ifstream fin("student.txt");
    if (!fin) {
        cout << "File not found!\n";
        return;
    }

    int searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    string line;
    bool found = false;

    while (getline(fin, line)) {
        int pos = line.find(',');
        int fileRoll = stoi(line.substr(0, pos));

        if (fileRoll == searchRoll) {
            cout << "\nRecord Found: " << line << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found!\n";

    fin.close();
}

// Delete a student's record by roll number
void Student::deleteStudent() {
    ifstream fin("student.txt");
    ofstream fout("temp.txt");

    if (!fin) {
        cout << "File not found!\n";
        return;
    }

    int deleteRoll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> deleteRoll;

    string line;
    bool deleted = false;

    while (getline(fin, line)) {
        int pos = line.find(',');
        int fileRoll = stoi(line.substr(0, pos));

        if (fileRoll != deleteRoll)
            fout << line << "\n";
        else
            deleted = true;
    }

    fin.close();
    fout.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (deleted)
        cout << "\nRecord deleted successfully!\n";
    else
        cout << "\nRecord not found!\n";
}

// Modify a student's record by roll number
void Student::modifyStudent() {
    ifstream fin("student.txt");
    ofstream fout("temp.txt");

    if (!fin) {
        cout << "File not found!\n";
        return;
    }

    int modRoll;
    cout << "\nEnter Roll Number to modify: ";
    cin >> modRoll;
    cin.ignore(); // ignore leftover newline

    string line;
    bool modified = false;

    while (getline(fin, line)) {
        int pos = line.find(',');
        int fileRoll = stoi(line.substr(0, pos));

        if (fileRoll == modRoll) {
            cout << "\nCurrent Record: " << line << "\n";

            string newName, newDiv, newAddr;
            cout << "Enter new Name: ";
            getline(cin, newName);
            cout << "Enter new Division: ";
            getline(cin, newDiv);
            cout << "Enter new Address: ";
            getline(cin, newAddr);

            fout << fileRoll << "," << newName << "," << newDiv << "," << newAddr << "\n";
            modified = true;
        } else {
            fout << line << "\n";
        }
    }

    fin.close();
    fout.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (modified)
        cout << "\nRecord modified successfully!\n";
    else
        cout << "\nRecord not found!\n";
}

// Main menu
int main() {
    Student s;
    int choice;

    do {
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Modify Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // important for getline after numeric input

        switch (choice) {
            case 1: s.addStudent(); break;
            case 2: s.displayStudent(); break;
            case 3: s.deleteStudent(); break;
            case 4: s.modifyStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
