/*
Name - Hansl Kumar
Roll no - 23308
Problem Statement:
"Implementing Queues and Stacks Using Linked Lists for Real-World Task Management Systems"
This program demonstrates:
1. Task Scheduling (Queue - FIFO)
2. Undo/Redo Functionality (Stack - LIFO)
*/


#include <bits/stdc++.h>
using namespace std;

// ---------------- STRUCTURE ----------------
struct mnode
{
    string title;
    int time;
    mnode *next;
};

// ---------------- QUEUE CLASS ----------------
class tqueue
{
    mnode *front;
    mnode *rear;

public:
    tqueue()
    {
        front = rear = NULL;
    }

    mnode *getnode()
    {
        mnode *t = new mnode();
        cout << "ENTER TITLE OF THE TASK : ";
        cin >> t->title;
        cout << "ENTER NUMBER OF HOURS INVESTED : ";
        cin >> t->time;
        t->next = NULL;
        return t;
    }

    void enqueue()
    {
        mnode *temp = getnode();
        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "NO TASKS TO DELETE!\n";
            return;
        }
        mnode *temp = front;
        front = front->next;
        delete temp;
        if (front == NULL)
            rear = NULL;
        cout << "TASK REMOVED SUCCESSFULLY!\n";
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "NO TASKS TO DISPLAY!\n";
            return;
        }
        mnode *temp = front;
        cout << "\n---- TASK LIST ----\n";
        while (temp != NULL)
        {
            cout << "TITLE: " << temp->title << " | HOURS: " << temp->time << endl;
            temp = temp->next;
        }
    }
};

// ---------------- STACK CLASS ----------------
class tstack
{
    mnode *top;

public:
    tstack()
    {
        top = NULL;
    }

    mnode *getnode()
    {
        mnode *t = new mnode();
        cout << "ENTER OPERATION NAME (e.g., Typing, Delete, Copy): ";
        cin >> t->title;
        cout << "ENTER DURATION IN SECONDS: ";
        cin >> t->time;
        t->next = NULL;
        return t;
    }

    void push()
    {
        mnode *temp = getnode();
        if (top == NULL)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "NOTHING TO UNDO!\n";
            return;
        }
        mnode *temp = top;
        top = top->next;
        cout << "UNDO OPERATION: " << temp->title << " (" << temp->time << "s)" << endl;
        delete temp;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "STACK IS EMPTY!\n";
            return;
        }
        mnode *temp = top;
        cout << "\n---- CURRENT OPERATIONS (Undo Stack) ----\n";
        while (temp != NULL)
        {
            cout << "OPERATION: " << temp->title << " | DURATION: " << temp->time << "s" << endl;
            temp = temp->next;
        }
    }
};

// ---------------- MAIN PROGRAM ----------------
int main()
{
    cout << "------------ TASK MANAGEMENT SYSTEM USING LINKED LISTS -----------\n";
    int choice_main;

    tqueue q;
    tstack s;
    char cont = 'y';

    while (cont == 'y')
    {
        cout << "\nCHOOSE MODULE:\n";
        cout << "1. Task Scheduler (QUEUE)\n";
        cout << "2. Undo/Redo System (STACK)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_main;

        switch (choice_main)
        {
        case 1:
        {
            int ch;
            char cont_q = 'y';
            while (cont_q == 'y')
            {
                cout << "\n--- TASK SCHEDULER MENU (QUEUE) ---\n";
                cout << "1. Add Task (Enqueue)\n";
                cout << "2. Remove Task (Dequeue)\n";
                cout << "3. Display Tasks\n";
                cout << "Enter your choice: ";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    q.enqueue();
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.display();
                    break;
                default:
                    cout << "INVALID CHOICE!\n";
                }
                cout << "\nContinue with Queue? (y/n): ";
                cin >> cont_q;
            }
            break;
        }

        case 2:
        {
            int ch;
            char cont_s = 'y';
            while (cont_s == 'y')
            {
                cout << "\n--- UNDO/REDO MENU (STACK) ---\n";
                cout << "1. Perform Operation (Push)\n";
                cout << "2. Undo Operation (Pop)\n";
                cout << "3. Show Operation Stack\n";
                cout << "Enter your choice: ";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    s.push();
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                default:
                    cout << "INVALID CHOICE!\n";
                }
                cout << "\nContinue with Stack? (y/n): ";
                cin >> cont_s;
            }
            break;
        }

        case 3:
            cout << "\nEXITING PROGRAM...\n";
            return 0;

        default:
            cout << "INVALID MAIN MENU CHOICE!\n";
        }

        cout << "\nReturn to Main Menu? (y/n): ";
        cin >> cont;
    }

    cout << "\nTHANK YOU FOR USING THE PROGRAM!\n";
    return 0;
}
