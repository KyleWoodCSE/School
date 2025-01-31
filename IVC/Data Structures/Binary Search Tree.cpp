/* Kyle Wood - Binary Search Tree Lab - 9/9/24 */

/*
Instructions:
Create a node class/struct
-Data field
-2 self referential pointers

Create a BST class/struct
-Node field
Methods:
Add (data)
-Adds the data to the tree in sorted order.
Print()
-Prints all the nodes using inorder traversal
*/

#include <iostream>

class Node {
public:
    int data;              
    Node* left;            
    Node* right;           
    // constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // function to insert data into the tree
    Node* AddRecursive(Node* node, int data) {
        // create a new node if at the end of the path
        if (node == nullptr) {
            return new Node(data);  
        }
        // if data of new node is smaller, put in left subtree - if larger insert into right subtree
        if (data < node->data) {
            node->left = AddRecursive(node->left, data);  
        }
        else {
            node->right = AddRecursive(node->right, data);  
        }

        return node;
    }

    // function used for inorder traversal
    void PrintInOrder(Node* node) const {
        if (node == nullptr) {
            return;
        }

        PrintInOrder(node->left);  // visit left subtree
        std::cout << node->data << " ";  // print node data
        PrintInOrder(node->right);  // visit right subtree
    }

public:
    // constructor
    BST() {
        root = nullptr;
    }

    // public method to add data
    void Add(int data) {
        root = AddRecursive(root, data);
    }

    // method to print nodes using inorder traversal
    void Print() const {
        PrintInOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;

    // add nodes to the BST
    int input;
    std::string cont = "y";
    while (cont == "y" || cont == "Y") {
        std::cout << "Enter a number to add to the array-based Binary Tree: ";
        std::cin >> input;
        tree.Add(input);
        std::cout << "Enter another number? (y/n): ";
        std::cin >> cont;
    }

    // print the BST using inorder traversal
    tree.Print();

    return 0;
}
