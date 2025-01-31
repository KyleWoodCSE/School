/* Kyle Wood - Linked List - 8/23/24 */

/*
Objective:  Create a singly linked list of numbers based upon user input.

Program logic:
Ask for a number, add that number to the front of the list, print the list.
Repeat until they enter -1 for the number.
.
Sample Input: 10, 15, 5, 2, 4, -1
Output: 4, 2, 5, 15, 10
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

class List {
private:
    Node* front;

public:
    List() {
        front = 0;
    }

    void AddNumber(int num) {
        std::cout << "Adding " << num << " to the front of the linked list!" << std::endl;
        Node* addNode = new Node();
        addNode->data = num; // store the user's number in the new node
        addNode->next = front; // point the new node to the previous front
        front = addNode; // set the new node as the new front
    }

    void OutputList() {
        // if user did not add numbers before terminating, output empty message
        if (front == 0) {
            std::cout << "Your linked list is empty!" << std::endl;
        }
        // output the values of the list to the console starting at the front of the linked list
        else {
            Node* print = front;
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
    std::cout << "Creating linked list.\n";
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


