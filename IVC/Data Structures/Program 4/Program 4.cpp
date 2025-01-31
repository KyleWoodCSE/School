/* Kyle Wood - Program 4 - 8 Nov 2024 */

/* 
    Program Specification:

Build a hash table using chaining as the collision resolution technique. Insertions into the hash table will correspond to declarations of variables and values in a program, searches will be requests for the value of a variable. Some variables will be local and have a narrow scope while some variables will be global.

The program will take input from a file, another program written in the omnipotent programming language BORG (Bionicly Omnipotent Resistance Grinders) and generate output from this program.

The BORG language has the following commands (keywords):

START-FINISH blocks. Indicating different scopes.
COM - Single line comments: Text should be ignored if on the same line
VAR varName – Variable Declaration, adds “varName” to the hash table.
variable = expression – Assignment statements, ie GEORGE = 122. Find GEORGE in the hash table and assign 122 to it.
++ - increment operator, syntax: VARIABLE ++
-- - decrement operator, syntax: VARIABLE --
expressions, expressions are limited to unary and binary arithmetic, or variable names
supported operators: +  -  /  *  %  ^ (plus, minus, divide, multiple, modulo, exponent)
PRINT – syntax PRINT expression. If the expression is a variable, and this variable is not in scope, then an error message indicating unknown variable x at line number y. The value printed if there is a variable in scope should be the variable with the closest scope.
Errors – other than the print statements, our interpreter will not be responsible for detecting errors, syntax errors should be disregarded if encountered, assume that the source file is correct.
Our hash function: sum the ordinal values of the characters of the variable multiplied by their position in the string (1-indexing), then taking the modulo by TABLESIZE.

The variable ABC = (65 * 1 + 66 * 2 + 67 * 3) % TABLESIZE
All tokens are separated by one space or a new line.

Output: for this assignment, run your interpreter on this sample source program as well as a program of your own, and turn it the output from both, as well as the source code from your BORG program as well as source code of the assignment and its executable. 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct Node {
    std::string key;
    int value, scope;
    Node* next;

    // node constructor with key, value, scope, and next pointer
    Node(std::string k, int v, int s) : key(k), value(v), scope(s), next(nullptr) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 17;
    Node* table[TABLE_SIZE];

    // helper function to find the previous node of a given key in the list
    Node* FindPrevious(std::string key, Node*& head) {
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

    // hash function: sum the ordinal values of the characters of the variable multiplied by their position in the string
    int Hash(const std::string& key) const {
        int hash = 0;
        for (int i = 0; i < key.size(); i++) {
            hash += (key[i] * (i + 1));
        }
        return hash % TABLE_SIZE;
    }

    // adds a node using chaining as collision resolution
    void add(std::string key, int value, int scope) {
        int index = Hash(key);
        Node*& head = table[index];

        // insert new node in sorted order
        Node* newNode = new Node(key, value, scope);
        Node* prev = FindPrevious(key, head);

        if (prev == nullptr) {
            newNode->next = head;
            head = newNode;
        }
        else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    // finds and returns the value for a given key
    int Lookup(std::string key, int scope) const {
        int index = Hash(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key && current->scope <= scope) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // finds and updates the value for a given key
    void Update(std::string key, int value, int scope) const {
        int index = Hash(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key && current->scope <= scope) {
                current->value = value;
            }
            current = current->next;
        }

    }
};

int main() {
    HashTable table;
    std::string key, fileLine, unit, temp;
    int value, exponent;
    int scope = 0;
    std::fstream borgFile;
    borgFile.open("input.txt"); // edit to name of .txt input file
    
    
    if (borgFile.is_open()) {
        while (borgFile) {
            std::getline(borgFile, fileLine);
            //std::cout << fileLine << std::endl;
            if (fileLine.empty()) {
                continue;
            }
            else {
                // use a stringstream to cycle through each word/number in the input
                std::stringstream stream;
                stream.str(fileLine);
                // cycle through each individual word/number of the string and print them on their own lines
                stream >> unit;

                if (unit == "START") {
                    scope++;
                }
                else if (unit == "FINISH") {
                    scope--;
                }
                else if (unit == "COM") {
                    continue;
                }
                else if (unit == "VAR") {
                    // add variable
                    stream >> unit; // grab var name from stream
                    key = unit;
                    stream >> unit; // pull out =
                    stream >> unit; // grab int value from stream
                    value = std::stoi(unit);
                    table.add(key, value, scope);
                }
                else if (unit == "PRINT") {
                    // lookup and print variable, check scope
                    // [VAR] IS UNDEFINED if not there
                    // nested option for arithmetic with value
                    stream >> unit; // pull var name from stream
                    key = unit;
                    if (stream.rdbuf()->in_avail() == 0) {
                        value = table.Lookup(key, scope);
                        if (value == -1) {
                            std::cout << key << " IS UNDEFINED" << std::endl;
                        }
                        else {
                            std::cout << key << " IS " << value << std::endl;
                        }
                    }
                    else {
                        stream >> unit; // pull operator from stream
                        if (unit == "+") {
                            value = table.Lookup(key, scope);
                            if (value == -1) {
                                std::cout << key << " IS UNDEFINED" << std::endl;
                            }
                            else {
                                stream >> unit; // pull value for arithmetic operation
                                std::cout << key << " + " << unit << " IS " << (value + std::stoi(unit)) << std::endl;
                            }
                        }
                        else if (unit == "-") {
                            value = table.Lookup(key, scope);
                            if (value == -1) {
                                std::cout << key << " IS UNDEFINED" << std::endl;
                            }
                            else {
                                stream >> unit; // pull value for arithmetic operation
                                std::cout << key << " - " << unit << " IS " << (value - std::stoi(unit)) << std::endl;
                            }
                        }
                        else if (unit == "*") {
                            value = table.Lookup(key, scope);
                            if (value == -1) {
                                std::cout << key << " IS UNDEFINED" << std::endl;
                            }
                            else {
                                stream >> unit; // pull value for arithmetic operation
                                std::cout << key << " * " << unit << " IS " << (value * std::stoi(unit)) << std::endl;
                            }
                        }
                        else if (unit == "/") {
                            value = table.Lookup(key, scope);
                            if (value == -1) {
                                std::cout << key << " IS UNDEFINED" << std::endl;
                            }
                            else {
                                stream >> unit; // pull value for arithmetic operation
                                if (unit == "0") {
                                    std::cout << "DIVISION BY ZERO ERROR" << std::endl;
                                }
                                else {
                                    std::cout << key << " / " << unit << " IS " << (value / std::stoi(unit)) << std::endl;
                                }
                                
                            }
                        }
                        else if (unit == "%") {
                            value = table.Lookup(key, scope);
                            if (value == -1) {
                                std::cout << key << " IS UNDEFINED" << std::endl;
                            }
                            else {
                                stream >> unit; // pull value for arithmetic operation
                                std::cout << key << " % " << unit << " IS " << (value % std::stoi(unit)) << std::endl;
                            }
                        }
                        else if (unit == "^") {
                            value = table.Lookup(key, scope);
                            if (value == -1) {
                                std::cout << key << " IS UNDEFINED" << std::endl;
                            }
                            else {
                                stream >> unit; // pull value for arithmetic operation
                                exponent = std::stoi(unit);
                                std::cout << key << " ^ " << unit << " IS " << pow(value, exponent) << std::endl;
                                
                            }
                        }
                    }
                    
                }
                else {
                    key = unit;
                    stream >> unit;
                    if (unit == "=") {
                        // lookup key, reassign value
                        value = table.Lookup(key, scope);
                        if (value == -1) {
                            std::cout << key << " IS UNDEFINED" << std::endl;
                        }
                        else {
                            stream >> unit; // pull value to update with
                            value = std::stoi(unit);
                            table.Update(key, value, scope);
                        }
                    }
                    else if (unit == "++") {
                        // lookup key, increment value
                        value = table.Lookup(key, scope);
                        if (value == -1) {
                            std::cout << key << " IS UNDEFINED" << std::endl;
                        }
                        else {
                            value++;
                            table.Update(key, value, scope);
                        }
                    }
                    else if (unit == "--") {
                        // lookup key, decrement value
                        value = table.Lookup(key, scope);
                        if (value == -1) {
                            std::cout << key << " IS UNDEFINED" << std::endl;
                        }
                        else {
                            value--;
                            table.Update(key, value, scope);
                        }
                    }
                }
            }
            
        }
    }
    else {
        std::cout << "Could not open file" << std::endl;
    }

    return 0;
}
