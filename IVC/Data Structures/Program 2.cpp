/* Kyle Wood - Program 2 - 9/16/24 */

/*
Program Specification:
1. Read data for names and weights for 15 people from the console where there is a name on a line followed by a weight on the next line, like below.
2. Your program will build a list for the data maintained in ascending order based on both name and weight via a doubly linked list.
3. This dll will use one pointer to keep weights in sorted order, and use the other link to keep names on sorted order.
4. You need to build the list as you go maintaining this ordering, so at any time a print method was called it would print the related field in order. (This means nodes are added to the list in sorted order, elements are not added to the list followed by a sort called on the list.)

For example after 3 elements are added for (Name – Weight):
Michael – 275, Tom – 150, Abe – 200.

Output:
Names & weights sorted(ascending) by name. : Abe – 200, Michael – 275, Tom - 150
Names & weights sorted(ascending) by weight. : Tom – 150, Abe – 200, Michael - 275

Grading:
Well-Formatted Correct Output: 10%
Correct Algorithm/Design: 80%
Good self documenting / commented code &
Readability (This should be easy points) 10%
*/

#include <iostream>
#include <string>

// node class to store name, weight, and two pointers for sorting by name and by weight
struct Node {
    std::string name;
    int weight;
    Node* nextName;
    Node* prevName;
    Node* nextWeight;
    Node* prevWeight;

    Node(std::string name, int weight) {
        this->name = name;
        this->weight = weight;
        nextName = prevName = nextWeight = prevWeight = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* headName;   // Head of the list sorted by name
    Node* tailName;   // Tail of the list sorted by name
    Node* headWeight; // Head of the list sorted by weight
    Node* tailWeight; // Tail of the list sorted by weight

public:
    DoublyLinkedList() : headName(nullptr), tailName(nullptr), headWeight(nullptr), tailWeight(nullptr) {}

    // Insert a new node maintaining both sorted orders
    void Insert(std::string name, int weight) {
        Node* newNode = new Node(name, weight);

        // insert in name order
        InsertByName(newNode);

        // insert in weight order
        InsertByWeight(newNode);
    }

    // insert by name in alphabetical order
    void InsertByName(Node* newNode) {
        // if no head exists or new value is less than current head, make new node the head
        if (!headName || newNode->name < headName->name) {
            newNode->nextName = headName;
            if (headName) {
                headName->prevName = newNode;
            }
            else {
                tailName = newNode; // this is the first node, so it's also the tail
            }
            headName = newNode;
        }
        else {
            // use iteration node to find correct place to insert
            Node* current = headName;
            while (current->nextName && current->nextName->name < newNode->name) {
                current = current->nextName;
            }
            newNode->nextName = current->nextName;
            if (current->nextName) {
                current->nextName->prevName = newNode;
            }
            else {
                tailName = newNode; // Inserted at the tail of the list
            }
            current->nextName = newNode;
            newNode->prevName = current;
        }
    }

    // insert by weight in ascending order
    void InsertByWeight(Node* newNode) {
        // if no head exists or new value is less than current head, make new node the head
        if (!headWeight || newNode->weight < headWeight->weight) {
            newNode->nextWeight = headWeight;
            if (headWeight) {
                headWeight->prevWeight = newNode;
            }
            else {
                tailWeight = newNode; // this is the first node, so it's also the tail
            }
            headWeight = newNode;
        }
        else {
            // use iteration node to find correct place to insert
            Node* current = headWeight;
            while (current->nextWeight && current->nextWeight->weight < newNode->weight) {
                current = current->nextWeight;
            }
            newNode->nextWeight = current->nextWeight;
            if (current->nextWeight) {
                current->nextWeight->prevWeight = newNode;
            }
            else {
                tailWeight = newNode; // Inserted at the tail of the list
            }
            current->nextWeight = newNode;
            newNode->prevWeight = current;
        }
    }

    // print the list sorted by name (from head to tail)
    void PrintByName() {
        Node* current = headName;
        std::cout << "Names & weights sorted by name (ascending): " << std::endl;
        while (current) {
            std::cout << current->name << " - " << current->weight;
            if (current->nextName) {
                std::cout << std::endl;
            }
            current = current->nextName;
        }
        std::cout << std::endl;
    }

    // print the list sorted by weight (from head to tail)
    void PrintByWeight() {
        Node* current = headWeight;
        std::cout << "Names & weights sorted by weight (ascending): " << std::endl;
        while (current) {
            std::cout << current->name << " - " << current->weight;
            if (current->nextWeight) {
                std::cout << std::endl;
            }
            current = current->nextWeight;
        }
        std::cout << std::endl;
    }

    // optional methods to print from tail to head:
    // print the list sorted by name (from tail to head)
    void PrintByNameReverse() {
        Node* current = tailName;
        std::cout << "Names & weights sorted by name (descending): " << std::endl;
        while (current) {
            std::cout << current->name << " - " << current->weight;
            if (current->prevName) {
                std::cout << std::endl;
            }
            current = current->prevName;
        }
        std::cout << std::endl;
    }

    // print the list sorted by weight (from tail to head)
    void PrintByWeightReverse() {
        Node* current = tailWeight;
        std::cout << "Names & weights sorted by weight (descending): " << std::endl;
        while (current) {
            std::cout << current->name << " - " << current->weight;
            if (current->prevWeight) {
                std::cout << std::endl;
            }
            current = current->prevWeight;
        }
        std::cout << std::endl;
    }
};

int main() {
    // create list and add values
    DoublyLinkedList list;
    std::string name;
    int weight;
    char cont = 'Y';
    while (cont == 'y' || cont == 'Y') {
        std::cout << "Enter a name and weight to add to the list" << std::endl;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Weight: ";
        std::cin >> weight;
        list.Insert(name, weight);

        std::cout << "Enter 'Y' to add another person, otherwise enter 'N': ";
        std::cin >> cont;
    }

    // print the lists sorted by name and weight separately
    list.PrintByName();
    list.PrintByWeight();

    // optionally, print the lists in reverse order
    list.PrintByNameReverse();
    list.PrintByWeightReverse();

    return 0;
}
