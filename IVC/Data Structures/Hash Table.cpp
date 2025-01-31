/* Kyle Wood - Hash Table Lab - 25 Oct 2024 */

/* Assignment Prompt:
    Create a hash table class/struct.

    Define an array that holds 27 elements.
    Define a function called Hash(int)
        -This function returns the modulo of that int by the size of the table (array).
    Define an add function that takes an integer.
        -This function takes the integer, determines the hash of that number by calling the above hash function, then adds it to the table using linear probing for collision resolution.
    Define a function that looks up a value, it takes an integer, return -1 if the value is not in the table.
    Create a main that allows the user to add and lookup items in the table.
*/

#include <iostream>

class HashTable {
private:
    static const int TABLE_SIZE = 27;
    int table[TABLE_SIZE];

public:
    // constructor to initialize the table
    // -1 indicates empty slots
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    // Hash function: returns the modulo of the number value by table size
    int Hash(int value) const {
        return value % TABLE_SIZE;
    }

    // add function with linear probing
    void add(int value) {
        int index = Hash(value);
        int start_index = index;
        bool fullTable = false;

        // linear probing to find the next available slot
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;

            // if we return to the start index, the table is full - end loop
            if (index == start_index) {
                fullTable = true;
                break;
            }
        }
        // if loop was broken because table is full, do not add value 
        if (fullTable) {
            std::cout << value << " could not be added to the table because the table is full!" << std::endl;
        }
        else {
            table[index] = value; // add value at proper index
        }
    }

    // lookup function: returns the index if found, -1 if not found
    int lookup(int value) const {
        int index = Hash(value);
        int start_index = index;

        // linear probing to find the value if it exists
        while (table[index] != -1) {
            if (table[index] == value) {
                return index;
            }
            index = (index + 1) % TABLE_SIZE;

            // if we return to the start index, the value is not in the table
            if (index == start_index) {
                break;
            }
        }
        return -1;
    }

    // function to display the contents of the table
    // not requested in assignment prompt - used for troubleshooting
    void display() const {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                std::cout << "Index " << i << ": " << table[i] << std::endl;
            }
            else {
                std::cout << "Index " << i << ": " << "empty" << std::endl;
            }
        }
    }

    // getter function for opening program message
    int GetTableSize() {
        return TABLE_SIZE;
    }
};

void menu() {
    HashTable ht;
    int choice, value, result;

    std::cout << "This program allows you to enter and look up numbers in a hash table with " << ht.GetTableSize() << " elements!" << std::endl;
    do {
        std::cout << "\n* Main Menu *\n";
        std::cout << "Please enter the number corresponding with your desired action:\n";
        std::cout << "1. Add a value to the table\n";
        std::cout << "2. Lookup a value in the table\n";
        std::cout << "3. Display the table\n";
        std::cout << "4. Exit program\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter a value to add to the table: ";
            std::cin >> value;
            ht.add(value);
            break;
        case 2:
            std::cout << "Enter a value to lookup in the table: ";
            std::cin >> value;
            result = ht.lookup(value);
            if (result != -1) {
                std::cout << "The given value " << value << " was found in the table at index " << result << std::endl;                
            }
            else {
                std::cout << "The given value " << value << " was not found in the table." << std::endl;
            }
            break;
        case 3:
            std::cout << "\nThe table is currently as follows: " << std::endl;
            ht.display(); 
            break;
        case 4:
            std::cout << "Exiting, have a great day!\n";
            break;
        default:
            std::cout << "Invalid entry. Please try again.\n";
            break;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}
