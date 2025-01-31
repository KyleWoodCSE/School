/* Kyle Wood - Array Based Binary Tree Lab - 8/16/24 */

/*
Instructions:
Create a binary tree class.

-Data array field (private)
-Count field
Add Function(data)
-The add method takes a data point, add it to the count position in the array then increases the count.
-Print Function 
Preorder(int)
-Recursive method that prints all the nodes in a VLR pattern.
(Remember 2i + 1 & 2i + 2)
*/

#include <iostream>

class BinaryTree {
private:
    // create a fixed size array to use for binary tree structure
    static const int MAX_SIZE = 100;  
    int data[MAX_SIZE];               
    int count; // variable to count number of elements in tree                  

public:
    BinaryTree() {
        count = 0; // initialize count with constructor
    }

    void Add(int value) {
        // add data to the array at count position and increment count
        if (count < MAX_SIZE) {
            data[count] = value;
            count++;
        }
        else {
            std::cout << "Binary Tree is full! Cannot add your number." << std::endl;
        }
    }

    // recursive function to print tree in VLR pattern
    void preorder(int index = 0) {
        if (index >= count) {
            return; // base case: if the index is out of bounds, return
        }

        // print the current node
        std::cout << data[index] << " ";

        // visit the left child (2i + 1)
        preorder(2 * index + 1);

        // visit the right child (2i + 2)
        preorder(2 * index + 2);
    }
};

int main() {
    BinaryTree tree;

    // add elements to the binary tree
    int input;
    std::string cont = "y";
    while (cont == "y" || cont == "Y") {
        std::cout << "Enter a number to add to the array-based Binary Tree: ";
        std::cin >> input;
        tree.Add(input);
        std::cout << "Enter another number? (y/n): ";
        std::cin >> cont;
    }
    // start preorder traversal from root at index 0
    std::cout << "Preorder traversal of the binary tree: ";
    tree.preorder();  
    std::cout << std::endl;

    return 0;
}