//Problem Statement - Efficient Data Management Using Linked Lists: Implementing Dynamic Operations for Contact Management System.
//Using Singly Linked List
#include<iostream>

using namespace std;

typedef struct MNode {
    string phno;
    string name;
    string emailid;
    struct MNode* next;//pointer to next node
} NODE;

class contact {
    NODE* head;//head pointer

public:
    contact() { head = NULL; }//head pointer is NULL
    ~contact();
    void create();
    void insert();
    void display();//Function declaration
    void insertB();
    void insertBt();
    void insertE();
    void search();
    void reverse();
    void Ndelete();
    NODE* getnode();
};

// Creating a linked list
void contact::create() {
    NODE* t;
    NODE* p;
    int n;

    cout << "Enter number of contacts: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        t = new NODE;

        // Name validation
        while (1) {
            cout << "Enter name: ";
            cin >> t->name;
            int j;
            for (j = 0; j < t->name.length(); j++) {
                char ch = t->name[j];
                if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
                    cout << "Invalid name. Enter characters only." << endl;
                    break;
                }
            }
            if (j == t->name.length()) {
                break;  // Name is valid
            }
        }

        // Phone number validation
        while (1) {
            cout << "Enter phone number: ";
            cin >> t->phno;

            if (t->phno.length() != 10) {
                cout << "Phone number should be exactly 10 digits." << endl;
                continue;
            }

            int j;
            for (j = 0; j < 10; j++) {
                if (!(t->phno[j] >= '0' && t->phno[j] <= '9')) {
                    cout << "Phone number must contain digits only." << endl;
                    break;
                }
            }

            if (j == 10) {
                break;  // Phone number is valid
            }
        }

        // Email validation
        while (1) {
            cout << "Enter email ID: ";
            cin >> t->emailid;

            int at = 0;
            int dot = 0;

            for (int j = 0; j < t->emailid.length(); j++) {
                if (t->emailid[j] == '@') {
                    at = 1;
                }
                if (t->emailid[j] == '.') {
                    dot = 1;
                }
            }

            if (at == 1 && dot == 1) {
                break;  // Valid email
            } else {
                cout << "Invalid email. Must contain '@' and '.'." << endl;
            }
        }

        // Add the node to the linked list
        t->next = NULL;
        if (head == NULL) {
            head = t;
            p = t;
        } else {
            p->next = t;
            p = t;
        }
    }
}




// Getnode fuction for input data helps to reduce rewriting
NODE* contact::getnode() {
    NODE* temp = new NODE;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter phone number: ";
    cin >> temp->phno;
    cout << "Enter email ID: ";
    cin >> temp->emailid;
    temp->next = NULL;
    return temp;
}

// Insert function to add node in b/w or at end or at start
void contact::insert() {
    int choice;
    cout << "Enter 1 to insert at beginning, 2 to insert at end, 3 to insert in between: ";
    cin >> choice;

    switch (choice) {                                //switch case to ask user where he want to insert data
    case 1:
        insertB();
        break;
    case 2:
        insertE();
        break;
    case 3:
        insertBt();
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}

// Insert at beginning
void contact::insertB() {
    cout << "Inserting at beginning..." << endl;
    NODE* t = getnode();
    t->next = head;
    head = t;
}

// Insert at end
void contact::insertE() {
    cout << "Inserting at end..." << endl;
    NODE* t = getnode();
    if (head == NULL) {
        head = t;
    } else {
        NODE* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
    }
}

// Insert in between
void contact::insertBt() {
    cout << "Inserting in between..." << endl;
    string afterName;
    cout << "Insert after which name? ";
    cin >> afterName;

    NODE* p = head;
    while (p != NULL && p->name != afterName) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Name not found!" << endl;
        return;
    }

    NODE* t = getnode();
    t->next = p->next;
    p->next = t;
}
//search function to search a contact detail
void contact::search() {
    string Name;
    NODE* p;

    cout << "Enter name to be searched: ";
    cin >> Name;

    p = head;

    while (p != NULL) {
        if (p->name == Name) {  
            cout << "Name: " << p->name << ", Phone: " << p->phno << ", Email: " << p->emailid << endl;
            return;  // Exit after finding the data
        }
        p = p->next;
    }

    cout << "Data not found" << endl;
}

//Delete function to delete a node
void contact ::Ndelete(){
    NODE *p;
    NODE *t;
    string Name;
    cout<<"Enter name to be deleted:";
    cin>>Name;
    p=head;
    t=head;
    while(p->name!=Name){
        t=p;
        p=p->next;
    }
    if(p==NULL){
        cout<<"Data not found"<<endl;
    }else if(p==head){
        head=head->next;
    }else{
        t->next=p->next;
    }
    delete(p);
    cout<<"data is deleted"<<endl;
}


// Display function to print linked list
void contact::display() {
    NODE* p = head;
    if (head == NULL) {
        cout << "Contact list is empty!" << endl;
        return;
    }

    cout << "\nContacts:\n";
    while (p != NULL) {
        cout << "Name: " << p->name << ", Phone: " << p->phno << ", Email: " << p->emailid << endl;
        p = p->next;
    }
}
void contact::reverse(){
    NODE* prev = NULL;
    NODE* current = head;
    NODE* next = NULL;

    while (current != NULL) {
        next = current->next;   // store next
        current->next = prev;   // reverse current node's pointer
        prev = current;         // move pointers one position ahead
        current = next;
    }
    head = prev;
    display();
    cout << "Linked list reversed successfully.\n";
}

// Main function
int main() {
    contact  c;
    int choice;
    c.create();
    while (true) {      //while loop to do multiple task
        cout << "1. Insert\n2. Display\n3.search\n4.delete\n5.Reverse\n6.exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {   //switch case to ask user to insert or display
                                        
        case 1:
            c.insert();
            break;
        case 2:
            c.display();
            break;
        case 3:
           c.search();
            break;
        case 4:
            c.Ndelete();
            break;
        case 5:
            c.reverse();
            break;
        case 6:
           return 0;    //exit the loop
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
contact::~contact() {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nLinked list deleted (Destructor called)." << endl;
}
