
#include<iostream>
using namespace std;

typedef struct MNode {
    string phno;
    string name;
    string emailid;
    struct MNode* next;
    struct MNode* prev; // added prev pointer
} NODE;

class contact {
    NODE* head;

public:
    contact() { head = NULL; }
    ~contact();
    void create();
    void insert();
    void display();
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
    NODE* p = NULL;
    int n;

    cout << "Enter number of contacts: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        t = new NODE;

        // Name validation (characters only)
        while (1) {
            cout << "Enter name: ";
            cin >> t->name;
            int j;
            for (j = 0; j < (int)t->name.length(); j++) {
                char ch = t->name[j];
                if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
                    cout << "Invalid name. Enter characters only." << endl;
                    break;
                }
            }
            if (j == (int)t->name.length()) {
                break; // valid name
            }
        }

        // Phone number validation (digits only, length 10)
        while (1) {
            cout << "Enter phone number: ";
            cin >> t->phno;

            if ((int)t->phno.length() != 10) {
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
                break; // valid phone
            }
        }

        // Email validation
        while (1) {
            cout << "Enter email ID: ";
            cin >> t->emailid;

            int at = 0;
            int dot = 0;

            for (int j = 0; j < (int)t->emailid.length(); j++) {
                if (t->emailid[j] == '@') at = 1;
                if (t->emailid[j] == '.') dot = 1;
            }

            if (at == 1 && dot == 1) {
                break; // valid email
            } else {
                cout << "Invalid email. Must contain '@' and '.'." << endl;
            }
        }

        // Setup pointers
        t->next = NULL;
        t->prev = NULL;

        if (head == NULL) {
            head = t;
            p = t;
        } else {
            p->next = t;
            t->prev = p;
            p = t;
        }
    }
}

// Getnode function for input data helps to reduce rewriting
NODE* contact::getnode() {
    NODE* temp = new NODE;

    // Name validation
    while (1) {
        cout << "Enter name: ";
        cin >> temp->name;
        int j;
        for (j = 0; j < (int)temp->name.length(); j++) {
            char ch = temp->name[j];
            if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
                cout << "Invalid name. Enter characters only." << endl;
                break;
            }
        }
        if (j == (int)temp->name.length()) break;
    }

    // Phone validation
    while (1) {
        cout << "Enter phone number: ";
        cin >> temp->phno;

        if ((int)temp->phno.length() != 10) {
            cout << "Phone number should be exactly 10 digits." << endl;
            continue;
        }

        int j;
        for (j = 0; j < 10; j++) {
            if (!(temp->phno[j] >= '0' && temp->phno[j] <= '9')) {
                cout << "Phone number must contain digits only." << endl;
                break;
            }
        }

        if (j == 10) break;
    }

    // Email validation
    while (1) {
        cout << "Enter email ID: ";
        cin >> temp->emailid;

        int at = 0;
        int dot = 0;

        for (int j = 0; j < (int)temp->emailid.length(); j++) {
            if (temp->emailid[j] == '@') at = 1;
            if (temp->emailid[j] == '.') dot = 1;
        }

        if (at == 1 && dot == 1) break;
        else cout << "Invalid email. Must contain '@' and '.'." << endl;
    }

    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Insert function to add node in beginning, end or in between
void contact::insert() {
    int choice;
    cout << "Enter 1 to insert at beginning, 2 to insert at end, 3 to insert in between: ";
    cin >> choice;

    switch (choice) {
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
    }
}

// Insert at beginning
void contact::insertB() {
    cout << "Inserting at beginning..." << endl;
    NODE* t = getnode();
    if (head != NULL) {
        head->prev = t;
    }
    t->next = head;
    t->prev = NULL;
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
        t->prev = p;
    }
}

// Insert after a given name (in between)
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
    t->prev = p;

    if (p->next != NULL) {
        p->next->prev = t;
    }
    p->next = t;
}

// Search function
void contact::search() {
    string Name;
    NODE* p;

    cout << "Enter name to be searched: ";
    cin >> Name;

    p = head;

    while (p != NULL) {
        if (p->name == Name) {
            cout << "Name: " << p->name << ", Phone: " << p->phno << ", Email: " << p->emailid << endl;
            return;
        }
        p = p->next;
    }

    cout << "Data not found" << endl;
}

// Delete function
void contact::Ndelete() {
    NODE* p;
    string Name;
    cout << "Enter name to be deleted: ";
    cin >> Name;

    p = head;

    while (p != NULL && p->name != Name) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Data not found" << endl;
        return;
    }

    if (p == head) {
        head = p->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        p->prev->next = p->next;
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
    }

    delete p;
    cout << "Data deleted" << endl;
}

// Display function
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

// Reverse doubly linked list
void contact::reverse() {
    NODE* temp = NULL;
    NODE* current = head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // move to next node (which was prev before swap)
    }

    // Reset head
    if (temp != NULL) {
        head = temp->prev;
    }

    display();
    cout << "Linked list reversed successfully.\n";
}

// Destructor
contact::~contact() {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nLinked list deleted (Destructor called)." << endl;
}

// Main function
int main() {
    contact  c;
    int choice;
    c.create();

    while (true) {
        cout << "1. Insert\n2. Display\n3. Search\n4. Delete\n5. Reverse\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
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
        return 0;
        default:
         cout << "Invalid choice!" << endl;
        }
    }
}
