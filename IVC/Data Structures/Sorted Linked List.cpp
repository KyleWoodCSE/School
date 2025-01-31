/* Kyle Wood - Sorted Linked List - 8/23/24 */

/*
Objective:  Create a sorted singly linked list of numbers based upon user input.

Program logic:
Ask for a number, add that number to the list in sorted position, print the list.
Repeat until they enter -1 for the number.
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class List {
private:
    Node *head;

public:
    List() {
        head = 0;
    }

    ~List() {
        for (Node* ptr; head != 0; ) {
            //std::cout << "Deleting node containing " << head->data << "." << std::endl; // print statement for testing
            ptr = head->next;
            delete head;
            head = ptr;
        }
    }

    void AddNumber(int num) {
        std::cout << "Adding " << num << " to the linked list." << std::endl;
        Node* addNode = new Node();
        addNode->data = num;
        // if the list is empty or the current head is already larger than input value, make new node the head
        if (head == 0 || head->data >= addNode->data) {
            addNode->next = head;
            head = addNode;
        }
        else {
            Node* current = head; // create node to cycle through data
            // iterate through linked list until either end is reached or larger value is found
            while (current->next != 0 && current->next->data < addNode->data) {
                current = current->next;
            }
            // set new node to where iteration node landed
            addNode->next = current->next;
            current->next = addNode;

        }
    }

    void OutputList() {
        // if user did not add numbers before terminating, output empty message
        if (head == 0) {
            std::cout << "Your linked list is empty!" << std::endl;
        }
        // output the values of the list to the console starting at the front of the linked list
        else {
            Node* print = head;
            std::cout << "The contents of your linked list from front to back are are: ";
            while (print) {
                std::cout << print->data << " ";
                print = print->next;
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    // initialize list and prompt user for numbers to add to list
    int userInput;
    List list;
    std::cout << "Creating sorted linked list.\n";
    std::cout << "Please enter numbers to enter to the list one at a time (enter -1 to end): ";
    std::cin >> userInput;
    // set loop to continually accept user input until terminated with -1
    while (userInput != -1) {
        list.AddNumber(userInput);
        std::cout << "Please enter another number (enter -1 to end): ";
        std::cin >> userInput;
    }
    std::cout << std::endl;
    // out the list for user on console
    list.OutputList();

    return 0;
}