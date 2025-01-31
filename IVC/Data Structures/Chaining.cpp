/* Kyle Wood - Chaining Lab - 25 Oct 2024 */

/* Prompt:
    Build a hash table that uses chaining for collision resolution. (An array of linked lists)

    Use an int for the key and a string for the value.

    Main
    Make a menu to handle
        Add(int, string)
        Lookup(int) -> string
        Delete(int) -> string
*/

#include <iostream>
#include <string>

struct Node {
    int key;
    std::string value;
    Node* next;

    // node constructor with key, value, and next pointer
    Node(int k, const std::string& v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 17;
    Node* table[TABLE_SIZE];

    // helper function to find the previous node of a given key in the list
    Node* FindPrevious(int key, Node*& head) {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr && current->key < key) {
            prev = current;
            current = current->next;
        }
        return prev;
    }

public:
    // constructor to initialize the hash table with null pointers
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // returns the modulo of the key by table size
    int Hash(int key) const {
        return key % TABLE_SIZE;
    }

    // adds a node in sorted order, prevents duplicate keys
    void add(int key, const std::string& value) {
        int index = Hash(key);
        Node*& head = table[index];

        // check if the key already exists
        // skip add if key exists to prevent duplicate values
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                std::cout << "Key " << key << " already exists. Skipping add.\n";
                return;
            }
            current = current->next;
        }

        // insert new node in sorted order
        Node* newNode = new Node(key, value);
        Node* prev = FindPrevious(key, head);

        if (prev == nullptr) {
            newNode->next = head;
            head = newNode;
        }
        else {
            newNode->next = prev->next;
            prev->next = newNode;
        }

        std::cout << "Added key " << key << " with value \"" << value << "\".\n";
    }

    // finds and returns the value for a given key
    std::string Lookup(int key) const {
        int index = Hash(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return "Key not found.";
    }

    // deletes the node with the specified key
    std::string DeleteKey(int key) {
        int index = Hash(key);
        Node*& head = table[index];

        Node* prev = FindPrevious(key, head);
        Node* toDelete;

        if (prev == nullptr) {
            if (head != nullptr && head->key == key) {
                toDelete = head;
                head = head->next;
            }
            else {
                return "Key not found.";
            }
        }
        else if (prev->next != nullptr && prev->next->key == key) {
            toDelete = prev->next;
            prev->next = toDelete->next;
        }
        else {
            return "Key not found.";
        }

        std::string value = toDelete->value;
        delete toDelete;
        return "Deleted key " + std::to_string(key) + " with value \"" + value + "\".";
    }

    // function to display the contents of the hash table
    // not asked for in prompt but used for troubleshooting and to help user track input values
    void Display() const {
        
        for (int i = 0; i < TABLE_SIZE; i++) {
            bool first = true;
            std::cout << "Index " << i << ": ";
            Node* current = table[i];
            if (!current) {
                std::cout << "empty\n";
            }
            else {
                while (current != nullptr) {
                    if (first) {
                        std::cout << "[" << current->key << ": " << current->value << "] ";
                        first = false;
                    }
                    else {
                        std::cout << "-> " << "[" << current->key << ": " << current->value << "] ";
                    }
                    current = current->next;
                }
                std::cout << std::endl;
            }
        }
    }
};

void Menu() {
    HashTable ht;
    int choice, key;
    std::string value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a key-value pair\n";
        std::cout << "2. Lookup a value using the key\n";
        std::cout << "3. Delete a value using the key\n";
        std::cout << "4. Display the table\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice using the numeric value: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter key (integer): ";
            std::cin >> key;
            std::cout << "Enter value (string): ";
            std::cin.ignore(); // clear newline from input buffer
            std::getline(std::cin, value);
            ht.add(key, value);
            break;
        case 2:
            std::cout << "Enter a key to lookup the correspoding value: ";
            std::cin >> key;
            std::cout << "Value: " << ht.Lookup(key) << std::endl;
            break;
        case 3:
            std::cout << "Enter the key of the value to be deleted: ";
            std::cin >> key;
            std::cout << ht.DeleteKey(key) << std::endl;
            break;
        case 4:
            ht.Display();
            break;
        case 5:
            std::cout << "Exiting, have a great day!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);
}

int main() {
    Menu();
    return 0;
}
