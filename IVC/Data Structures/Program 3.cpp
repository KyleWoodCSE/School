/*Kyle Wood - Program 3 - 9/23/24 */

/*
Program Specification:

Build a binary search tree, using links (not an array) for 15 records. The data in these records will hold names and their associated weights. Read the data from the screen.

Required functionality (Each # should be separate methods):

Build the tree from the unique set of names (names are the key value) and their associated weights.
Execute a preorder traversal
Execute an inorder traversal
Execute a postorder traversal
Find and print the height of the tree using recursion, do not add a height variable to the tree structure, the algorithm stack should hold this.
Determine the number of leaves and print the result (remember a leaf has no children).
Implement search functionality that will search for a name and indicate the weight for that individual if they exist in the structure, otherwise stating no match exists.
Determine the lowest weight contained in the tree.
Find the first name in alphabetical order (this should not go through every node, unless the tree happens to be a linked list).
*/

#include <iostream>
#include <string>
#include <limits>

// struct for BST node
struct TreeNode {
    std::string name;
    double weight;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string n, double w) : name(n), weight(w), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // insert node into BST according to name value
    void InsertNode(TreeNode*& node, const std::string& name, double weight) {
        if (node == nullptr) {
            node = new TreeNode(name, weight);
        }
        else if (name < node->name) {
            InsertNode(node->left, name, weight);
        }
        else if (name > node->name) {
            InsertNode(node->right, name, weight);
        }
        // duplicate values break BST logic, put statement to inform of duplicate value
        else {
            std::cout << name << " already exists! Skipping insertion." << std::endl;
        }
    }

    // method for preorder traversal
    void Preorder(TreeNode* node) const {
        if (node) {
            std::cout << node->name << " (" << node->weight << ")" << std::endl;
            Preorder(node->left);
            Preorder(node->right);
        }
    }

    // method for inorder traversal
    void Inorder(TreeNode* node) const {
        if (node) {
            Inorder(node->left);
            std::cout << node->name << " (" << node->weight << ")" << std::endl;
            Inorder(node->right);
        }
    }

    // method for postorder traversal
    void Postorder(TreeNode* node) const {
        if (node) {
            Postorder(node->left);
            Postorder(node->right);
            std::cout << node->name << " (" << node->weight << ")" << std::endl;
        }
    }

    // determine height of tree
    int TreeHeight(TreeNode* node) const {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = TreeHeight(node->left);
        int rightHeight = TreeHeight(node->right);
        return 1 + std::max(leftHeight, rightHeight); // add 1 to offset the -1 returned from reaching nullptr at end of branch
    }

    // method counting number of leaves in BST
    int CountLeaves(TreeNode* node) const {
        if (node == nullptr) {
            return 0;
        }
        // leaves have no child nodes, so return 1 if inspected node yields nullptr on both left and right ptrs
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        else {
            return CountLeaves(node->left) + CountLeaves(node->right);
        }
    }

    // method to search for given name
    TreeNode* SearchName(TreeNode* node, const std::string& name) const {
        if (node == nullptr || node->name == name) {
            return node; // return either nullptr or the matched name, logic for both cases handled in public root method
        }
        // search left if name value is lower than current node, otherwise search right for larger value
        if (name < node->name) {
            return SearchName(node->left, name);
        }
        else {
            return SearchName(node->right, name);
        }
    }

    // method to find minimum weight value in BST
    double FindMinWeight(TreeNode* node) const {
        if (node == nullptr) {
            return std::numeric_limits<double>::max(); // sets the value as the absolute highest value to make sure whatever real value is compared to it during the BST traversal is guaranteed to be lower
        }
        else {
            return std::min(node->weight, std::min(FindMinWeight(node->left), FindMinWeight(node->right)));
        }
        
    }

    // smallest name value of BST will be left most node since it is sorted by name (which may be root) so traverse until at left most point and return that node
    TreeNode* FindMinName(TreeNode* node) const {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void InsertNode(const std::string& name, double weight) {
        InsertNode(root, name, weight);
    }

    void Preorder() const {
        Preorder(root);
    }

    void Inorder() const {
        Inorder(root);
    }

    void Postorder() const {
        Postorder(root);
    }

    int TreeHeight() const {
        return TreeHeight(root);
    }

    int CountLeaves() const {
        return CountLeaves(root);
    }

    void SearchName(const std::string& name) const {
        TreeNode* result = SearchName(root, name);
        if (result != nullptr) {
            std::cout << "Found: " << result->name << " (" << result->weight << ")" << std::endl;
        }
        else {
            std::cout << "No match for '" << name << "'." << std::endl;
        }
    }

    double FindMinWeight() const {
        return FindMinWeight(root);
    }

    std::string FindFirstAlphabetically() const {
        TreeNode* minNode = FindMinName(root);
        return minNode ? minNode->name : "Tree is empty"; // if minNode is not null, return name else inform user that BST is currently empty
    }
};

int main() {
    BinarySearchTree bst;

    // get names and weights from user to add to BST
    for (int i = 0; i < 15; ++i) {
        std::string name;
        double weight;
        std::cout << "Enter a name to add to the tree: ";
        std::cin >> name;
        std::cout << "Enter " << name <<"'s weight: ";
        std::cin >> weight;
        bst.InsertNode(name, weight);
    }

    // print out BST data using different traversal methods
    std::cout << "\nData in BST using preorder traversal:\n";
    bst.Preorder();
    std::cout << "\nData in BST using inorder traversal:\n";
    bst.Inorder();
    std::cout << "\nData in BST using postorder traversal:\n";
    bst.Postorder();

    // indicate height of tree (note, tree height is one less than number of levels in longest branch)
    std::cout << "\nHeight of the BST: " << bst.TreeHeight() << std::endl;
    // indicate number of leaves in BST (nodes that have nullptr in both left and right ptrs)
    std::cout << "Number of leaves in BST: " << bst.CountLeaves() << std::endl;

    // prompt user for a name to search for in BST and indicate if found
    std::string searchName;
    std::cout << "\nEnter a name to search in the BST: ";
    std::cin >> searchName;
    bst.SearchName(searchName);

    // print lowest weight found in BST
    std::cout << "\nThe lowest weight in the tree: " << bst.FindMinWeight() << std::endl;
    // print the name that comes first in the alphabet (has lowest string value)
    std::cout << "\nThe first name alphabetically in the BST: " << bst.FindFirstAlphabetically() << std::endl;

    return 0;
}
