/* Kyle Wood - Traversals Lab - 9/16/24 */

/*
Instructions:
Extend the array based tree lab by adding these methods.

(Remember 2i + 1 & 2i + 2)
 
Preorder(int)
-Recursive method that prints all the nodes in a VLR pattern.
Inorder(int)
-Recursive method that prints all the nodes in a LVR pattern.
Postorder(int)
-Recursive method that prints all the nodes in a LRV pattern.
*/

#include <iostream>
#include <vector>

class BinaryTree {
private:
    std::vector<int> data;  // Data array
    int count;              // Count of elements in the tree

    // Recursive helper for preorder traversal (VLR: Visit Left Right)
    void preorder(int index) const {
        if (index >= count || index >= data.size()) return;

        // Visit (Print the current node)
        std::cout << data[index] << " ";

        // Left (2*i + 1)
        preorder(2 * index + 1);

        // Right (2*i + 2)
        preorder(2 * index + 2);
    }

    // Recursive helper for inorder traversal (LVR: Left Visit Right)
    void inorder(int index) const {
        if (index >= count || index >= data.size()) return;

        // Left (2*i + 1)
        inorder(2 * index + 1);

        // Visit (Print the current node)
        std::cout << data[index] << " ";

        // Right (2*i + 2)
        inorder(2 * index + 2);
    }

    // Recursive helper for postorder traversal (LRV: Left Right Visit)
    void postorder(int index) const {
        if (index >= count || index >= data.size()) return;

        // Left (2*i + 1)
        postorder(2 * index + 1);

        // Right (2*i + 2)
        postorder(2 * index + 2);

        // Visit (Print the current node)
        std::cout << data[index] << " ";
    }

public:
    // Constructor
    BinaryTree(int size) : count(0) {
        data.resize(size);
    }

    // Add method
    void add(int value) {
        if (count < data.size()) {
            data[count] = value;
            ++count;
        }
        else {
            std::cout << "Binary tree is full, cannot add more elements.\n";
        }
    }

    // Public method to start preorder traversal
    void printPreorder() const {
        std::cout << "Preorder traversal (VLR): ";
        preorder(0);  // Start from the root (index 0)
        std::cout << std::endl;
    }

    // Public method to start inorder traversal
    void printInorder() const {
        std::cout << "Inorder traversal (LVR): ";
        inorder(0);  // Start from the root (index 0)
        std::cout << std::endl;
    }

    // Public method to start postorder traversal
    void printPostorder() const {
        std::cout << "Postorder traversal (LRV): ";
        postorder(0);  // Start from the root (index 0)
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree(7);  // Create a binary tree that can hold 7 elements

    // Add elements to the binary tree
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(6);
    tree.add(7);

    // Print the tree in preorder (VLR) traversal
    tree.printPreorder();

    // Print the tree in inorder (LVR) traversal
    tree.printInorder();

    // Print

