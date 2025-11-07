/*
Name - Hansal Kumar
Roll no. - 23308
Problem Statement:
 Implementation of a PriorityQueue
 • Develop a priority queue where elements are dequeued based on priority rather than
 insertion order. 
 • Support operations such as insertion,deletion,and display.
 Implementation of a Double-Ended Queue(Deque)
 • Implement a double-ended queue where insertion and deletion can happen from both ends.
 • Support operations such as enqueue front , enqueue rear, deque front, dequeue rear.
 
*/
#include <bits/stdc++.h>
using namespace std;

struct Patient {
    string pname;       // patient name
    string condition;   // emergency type
    Patient *next;      // pointer to next patient
};

class Hospital {
private:
    Patient *front;     // start of the list
    Patient *back;      // end of the list

public:
    Hospital() {
        front = nullptr;
        back = nullptr;
    }

    // Take input for a new patient
    Patient *getDetails() {
        Patient *temp = new Patient();
        cout << "\nEnter Patient Name: ";
        cin >> temp->pname;
        cout << "Enter Emergency Type (disease / small_bleeding / accident): ";
        cin >> temp->condition;
        temp->next = nullptr;
        return temp;
    }

    // Assign priority to emergencies
    int getPriority(string cond) {
        if (cond == "disease") return 1;
        else if (cond == "small_bleeding") return 2;
        else if (cond == "accident") return 3;
        else return 0; // unknown condition
    }

    // Register a new patient according to priority
    void registerPatient() {
        Patient *temp = getDetails();

        // If list is empty
        if (front == nullptr) {
            front = back = temp;
            return;
        }

        // If new patient has higher priority than the first one
        if (getPriority(temp->condition) > getPriority(front->condition)) {
            temp->next = front;
            front = temp;
            return;
        }

        // Otherwise, find correct position
        Patient *curr = front;
        while (curr->next != nullptr &&
               getPriority(curr->next->condition) >= getPriority(temp->condition)) {
            curr = curr->next;
        }

        // Insert patient in correct position
        temp->next = curr->next;
        curr->next = temp;

        // Update tail if inserted at end
        if (temp->next == nullptr)
            back = temp;
    }

    // Display all patients
    void showPatients() {
        if (front == nullptr) {
            cout << "\nNo patients in queue.\n";
            return;
        }

        cout << "\n--- Patient Queue (Highest priority first) ---\n";
        Patient *ptr = front;
        while (ptr != nullptr) {
            cout << "Name: " << ptr->pname
                 << " | Emergency: " << ptr->condition
                 << " | Priority: " << getPriority(ptr->condition) << endl;
            ptr = ptr->next;
        }
    }
};

int main() {
    Hospital hosp;
    int choice;

    do {
        cout << "\n===== HOSPITAL EMERGENCY MANAGEMENT =====";
        cout << "\n1. Register New Patient";
        cout << "\n2. Display All Patients";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hosp.registerPatient();
                break;
            case 2:
                hosp.showPatients();
                break;
            case 3:
                cout << "\nExiting system...\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
