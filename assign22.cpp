//Problem Statement:
//"Implementing Queues and Stacks Using Linked Lists for Real-World Task Management Systems"
//Application:
//Undo/Redo Functionality (Stack) - Using LIFO (Last In First Out) approach.
//For example: last performed task will be undone first.
#include <bits/stdc++.h>
using namespace std;

// Node for stack
struct mnode {
    string title;
    int time;
    mnode *next;
};

class tstack {
    mnode *top; // Pointer to top of stack

public:
    tstack() {
        top = NULL;//constructor to initialize top as null
    }

    // Function to create a new node
    mnode* getnode() {
        mnode *t = new mnode();
        cout << "ENTER TITLE OF THE TASK: ";
        cin >> t->title;
        cout << "ENTER HOURS INVESTED: ";
        cin >> t->time;
        t->next = NULL;
        return t;
    }
   

    // Push a node on stack
    void push() {//here no need to create a create function as push works as create
        mnode *temp = getnode();
        if (top == NULL) {
            top = temp;
        } else {
            temp->next = top; // New node points to old top
            top = temp;       // Move top to new node
        }
        cout << "Task added \n";
    }

    // Pop a task from stack 
    void pop() {
        if (top == NULL) {
            cout << " No task to undo.\n";
            return;
        }
        mnode *temp = top;//pointing top
        top = top->next;//top moves further
       
        delete temp;//deleted
    }

    // Display all updated tasks in stack
    void display() {
        if (top == NULL) {
            cout << "STACK IS EMPTY!\n";
            cout<<"DO YOU WANT TO CREATE??\n"<<endl;
            string ans;
            cin>>ans;
            if(ans=="yes"){
                push();
            }
            else{
                cout<<"OKAY"<<endl;
            }
        }
        cout << "Tasks in stack : \n";
        mnode *k = top;
        while (k != NULL) {
            cout << "TITLE: " << k->title << ", HOURS: " << k->time << "\n";
            k = k->next;//k age badho
        }
    }
};

int main() {
    cout << "WELCOME to PROGRAM\n";
    tstack s;
    int choice;
    char cont = 'y';

    while (cont == 'y') {
        cout << "\nMENU:\n";
        cout << "1. PUSH (Add Task)\n";
        cout << "2. POP (Undo Last Task)\n";
        cout << "3. DISPLAY (Show All Tasks)\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: s.push(); break;
            case 2: s.pop(); break;
            case 3: s.display(); break;
            default: cout << "INVALID CHOICE!\n";
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> cont;
    }

    cout << "\nEXITING PROGRAM...\n";
    return 0;
}
