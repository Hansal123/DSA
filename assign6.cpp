#include <iostream>
#include <string>
using namespace std;

class HashTable {
    static const int SIZE = 10;  // hash table size

    struct Record {
        string username;
        string password;
    };

    Record chainTable[SIZE][5];   // each index can have up to 5 users
    int chainCount[SIZE];         // tracks how many users are in each chain
    Record openAddressTable[SIZE]; // each index stores only one user

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            chainCount[i] = 0;
            openAddressTable[i].username = "";
            openAddressTable[i].password = "";
        }
    }

    int hashFunction(string key) {
        int sum = 0;
        for (char c : key)
            sum += c;
        return sum % SIZE;   // simple hash
    }

    void insertChaining(string user, string pass) {
        int index = hashFunction(user);
        int pos = chainCount[index];  // number of users already in that index

        if (pos < 5) {
            chainTable[index][pos].username = user;
            chainTable[index][pos].password = pass;
            chainCount[index]++;
            cout << "Stored at index " << index << " using chaining.\n";
        } else {
            cout << "No space in chain at index " << index << "!\n";
        }
    }

    void searchChaining(string user) {
        int index = hashFunction(user);
        for (int i = 0; i < chainCount[index]; i++) {
            if (chainTable[index][i].username == user) {
                cout << "Found user at index " << index << " (position " << i << ") using chaining.\n";
                cout << "Password: " << chainTable[index][i].password << "\n";
                return;
            }
        }
        cout << "User not found in chaining.\n";
    }

    void insertOpenAddress(string user, string pass) {
        int index = hashFunction(user);

        for (int i = 0; i < SIZE; i++) {
            int newIndex = (index + i) % SIZE;  // linear probing
            if (openAddressTable[newIndex].username == "") {  // empty slot
                openAddressTable[newIndex].username = user;
                openAddressTable[newIndex].password = pass;
                cout << "Stored at index " << newIndex << " using open addressing.\n";
                return;
            }
        }
        cout << "Table full, cannot insert (open addressing)!\n";
    }

    void searchOpenAddress(string user) {
        int index = hashFunction(user);

        for (int i = 0; i < SIZE; i++) {
            int newIndex = (index + i) % SIZE;
            if (openAddressTable[newIndex].username == user) {
                cout << "Found user at index " << newIndex << " using open addressing.\n";
                cout << "Password: " << openAddressTable[newIndex].password << "\n";
                return;
            }
            if (openAddressTable[newIndex].username == "")
                break; // if empty spot, stop (user not present)
        }
        cout << "User not found in open addressing.\n";
    }
};

// -------------------- MAIN FUNCTION --------------------
int main() {
    HashTable ht;

    int n;
    cout << "=== INSERTING (CHAINING) ===\n";
    cout << "Enter number of users to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string user, pass;
        cout << "\nEnter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;
        ht.insertChaining(user, pass);
    }

    cout << "\n=== SEARCHING (CHAINING) ===\n";
    cout << "Enter username to search: ";
    string searchUser1;
    cin >> searchUser1;
    ht.searchChaining(searchUser1);

    cout << "\n=== INSERTING (OPEN ADDRESSING) ===\n";
    cout << "Enter number of users to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string user, pass;
        cout << "\nEnter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;
        ht.insertOpenAddress(user, pass);
    }

    cout << "\n=== SEARCHING (OPEN ADDRESSING) ===\n";
    cout << "Enter username to search: ";
    string searchUser2;
    cin >> searchUser2;
    ht.searchOpenAddress(searchUser2);

    return 0;
}
