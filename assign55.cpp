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
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        next = nullptr;
    }
};

class DEQ {
private:
    Node* front;
    Node* rear;

public:
    DEQ() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueueFront();
    void enqueueRear();
    void dequeueFront();
    void dequeueRear();
    void peekFront();
    void peekRear();
};

// Enqueue at front
void DEQ::enqueueFront() {
    Node* newNode = new Node;
    cout << "Enter data: ";
    cin >> newNode->data;

    if (front == nullptr && rear == nullptr) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
}

// Enqueue at rear
void DEQ::enqueueRear() {
    Node* newNode = new Node;
    cout << "Enter data: ";
    cin >> newNode->data;

    if (rear == nullptr && front == nullptr) {
        rear = front = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue from front
void DEQ::dequeueFront() {
    if (front == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    Node* temp = front;
    if (front->next == nullptr) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }

    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

// Dequeue from rear
void DEQ::dequeueRear() {
    if (rear == nullptr) {
        cout << "Empty" << endl;
        return;
    }

    Node* temp = front;

    // Only one node
    if (temp->next == nullptr) {
        front = rear = nullptr;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        return;
    }

    // Traverse to second last node
    while (temp->next != rear) {
        temp = temp->next;
    }

    Node* toDelete = rear;
    rear = temp;
    rear->next = nullptr;

    cout << "Deleted: " << toDelete->data << endl;
    delete toDelete;
}

// Peek front
void DEQ::peekFront() {
    if (front == nullptr) {
        cout << "Empty" << endl;
    } else {
        cout << "Front: " << front->data << endl;
    }
}

// Peek rear
void DEQ::peekRear() {
    if (rear == nullptr) {
        cout << "Empty" << endl;
    } else {
        cout << "Rear: " << rear->data << endl;
    }
}

int main() {
    DEQ obj;
    char ans = 'y';
    char position;
    char choice;

    while (ans == 'y' || ans == 'Y') {
        cout << "\nEnter the choice:\n1. Enqueue\n2. Dequeue\n3. Peek\n";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the position (f/r): ";
                cin >> position;
                if (position == 'f')
                    obj.enqueueFront();
                else if (position == 'r')
                    obj.enqueueRear();
                else
                    cout << "Invalid choice" << endl;
                break;

            case '2':
                cout << "Enter the position (f/r): ";
                cin >> position;
                if (position == 'f')
                    obj.dequeueFront();
                else if (position == 'r')
                    obj.dequeueRear();
                else
                    cout << "Invalid choice" << endl;
                break;

            case '3':
                cout << "Enter the position (f/r): ";
                cin >> position;
                if (position == 'f')
                    obj.peekFront();
                else if (position == 'r')
                    obj.peekRear();
                else
                    cout << "Invalid choice" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

        cout << "Continue? (y/n): ";
        cin >> ans;
    }

    return 0;
}
