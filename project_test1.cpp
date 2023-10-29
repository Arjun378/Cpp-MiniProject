/*Mini Project - 22070123150*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable {
    int capacity;
    list<pair<int, int>> *table;
public:
    int loc = 0;
    string books[10] = {
        "The Girl with All the Gifts",
        "Dark Matter",
        "Altered Carbon",
        "The Andromeda Strain",
        "Persopolis Rising",
        "Leviathan Wakes",
        "Dune",
        "Knock At The Cabin",
        "The Lord Of The Rings",
        "Do Androids Dream of Electronic Sheep?"
    };
    int book_id[10] = {
        101,
        102,
        103,
        104,
        105,
        106,
        107,
        108,
        109,
        110
    };
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    int searchKey(int key);
    int checkPrime(int n);
    int getPrime(int n);
    int hashFunction(int key);
    void displayHash();
    void displayBooks();
    int bookThere(int id);
};

HashTable::HashTable(int c) {
    int size = getPrime(c);
    this->capacity = size;
    table = new list<pair<int, int>>[capacity];
}

void HashTable::insertItem(int key, int data) {
    int index = hashFunction(key);
    table[index].push_back(make_pair(key, data));
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    int found_item = searchKey(key);
    if (found_item != -1)
    {
        list<pair<int, int>>& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                cout << "Book returned: "<<books[loc]<<endl;
                return;
            }
        }
    }
    else{
        cout << "There were no books issued under this PRN."<<endl;
        return;
    }
    
    
}

int HashTable::searchKey(int key) {
    int index = hashFunction(key);
    list<pair<int, int>>& bucket = table[index];
    for (const pair<int, int>& item : bucket) {
        if (item.first == key) {
            return item.second;
        }
    }
    return -1; // Key not found
}

void HashTable::displayHash() {
    for (int i = 0; i < capacity; ++i) {
        cout << "table[" << i << "]";
        for (const pair<int, int>& item : table[i]) {
            cout << " --> Key: " << item.first << ", Value: " << item.second;
        }
        cout << endl;
    }
}

int HashTable::checkPrime(int n) {
    int i;
    if (n == 1 || n == 0) {
        return 0;
    }
    for (i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int HashTable::getPrime(int n) {
    if (n % 2 == 0) {
        n++;
    }
    while (!checkPrime(n)) {
        n += 2;
    }
    return n;
}

int HashTable::hashFunction(int key) {
    return (key % capacity);
}


void HashTable::displayBooks(){
    
    int count = sizeof(book_id)/sizeof(int);
    for (int i = 0; i < count; i++)
    {
        cout << books[i] << " - ID: " << book_id[i]<< endl;
    }
    return;
}
int HashTable::bookThere(int id){
    int found = 0;
    int count = sizeof(book_id)/sizeof(int);
    for (int i = 0; i < count; i++)
    {
        if (id == book_id[i])
        {
            found = 1;
            loc = i;
        }
        
    }
    if (found==1)
    {
        cout << "Book Issued: " << books[loc]<< endl;
        return 1;
    }
    else{
        cout << "Book Not Found"<< endl;
        return 0;
    }
}
int main() {
    HashTable h(7); // Initialize the hash table with an initial capacity of 7

    while (true) {
        int choice;
        cout << "*--------------------Library Management System--------------------*\n";
        cout << "1. Display Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search for Student\n";
        cout << "5. Display Hash Table\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            h.displayBooks();
        }
        
        else if (choice == 2) {
            int key;
            int value, found;
            cout << "Enter Student PRN: ";
            cin >> key;
            cout << "Enter Book ID: ";
            cin >> value;
            found = h.bookThere(value);
            if (found ==1)
            {
                h.insertItem(key, value);
            }
            
            
        } else if (choice == 3) {
            int key;
            cout << "Enter PRN: ";
            cin >> key;
            h.deleteItem(key);
        } else if (choice == 4) {
            int key;
            cout << "Enter PRN to Search: ";
            cin >> key;
            int foundValue = h.searchKey(key);
            if (foundValue != -1) {
                cout << "Student found. \nIssued Book ID: " << foundValue << endl;
            } else {
                cout << "Student not found." << endl;
            }
        } else if (choice == 5) {
            h.displayHash();
        } else if (choice == 6) {
            break; // Exit the loop and program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
