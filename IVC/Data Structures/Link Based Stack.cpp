/* Kyle Wood - Link Based Stack - 8/19/24 */

/*
Instructions:
Create a class/struct for a node.
Create a class/struct for a list.

Members:
Top - a node that tracks the top of the stack
Count - indicates how many items are on the stack.

Methods:
Push O(1)
- Accepts a number and adds to the top of the stack.
Pop O(1)
- Returns a number from the top of the stack.
- If the stack is empty, emit an error indicating the stack is empty.
IsEmpty
- Returns a boolean indicating if the stack is empty.

Create and exercise a stack object in main.
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // make ptr optional parameter
    Node(int num1, Node* ptr = 0) {
        data = num1;
        next = ptr;
    }
};

class List {
private:
    Node* top;
    int count = 0;

public:
    List() {
        top = 0;
    }

    void Push(int num1) {
        
        std::cout << "Adding " << num1 << " to the top of the stack." << std::endl;
        Node* pushNode = new Node(num1);
        
        // check if the Stack is empty
        // if yes, establish new node as the beginning of the stack
        if (IsEmpty()) {
            top = pushNode;
        }
        // if the stack is not empty, the new node is made the top and points to the previous top node
        else {
            pushNode->next = top;
            top = pushNode;
        }
                
        // increment counter to indicate number of nodes on stack
        count++;
    }

    int Pop() {
        // if the stack is empty, output an error
        if (IsEmpty()) {
            std::cout << "Error! Stack is empty. Error code: ";
            return 404;
        }
        else {
            // grab int from top node for return value
            int poppedNum = top->data;
            // keep tab on current top node to be deleted
            Node* temp;
            temp = top;
            // shift next node down to be new top
            top = top->next;
            // decrement counter to indicate number of nodes on stack
            count--;
            // "pop" or delete the old top node;
            delete temp;
            // end with returning the data of the popped node
            return poppedNum;
        }
        
        
    }

    bool IsEmpty() {
        if (top == 0) {
            return true;
        }
        return false;
    }

    void outputData() {
        // indicate how many nodes are currently on the stack
        std::cout << "The stack currently contains " << count << " node(s)." << std::endl;
        // if the stack contains nodes, output their data
        if (top != 0) {
            std::cout << "The stack numbers from top to bottom are: ";
            for (Node* printNode = top; printNode != 0; printNode = printNode->next) {
                std::cout << printNode->data << " ";
            }
            std::cout << std::endl << std::endl;
        }
        
    }
};

int main()
{
    // initialize link based stack and print to show we start off empty
    List stack;
    stack.outputData();
    std::cout << std::endl;
    // push and pop values to show implementation
    stack.Push(20);
    stack.outputData();
    stack.Push(4);
    stack.outputData();
    std::cout << "Popping " << stack.Pop() << " from the stack." << std::endl;
    stack.outputData();
    std::cout << "Popping " << stack.Pop() << " from the stack." << std::endl;
    stack.outputData();
    std::cout << std::endl;

    // pop without value to show error message
    std::cout << "Testing pop function on empty stack to produce error message: " << std::endl;
    std::cout << stack.Pop() << std::endl;
    std::cout << std::endl;

    // final push and pop to show error didn't interrupt program
    stack.Push(69);
    stack.outputData();
    std::cout << "Popping " << stack.Pop() << " from the stack." << std::endl;
    stack.outputData();

    return 0;
}


