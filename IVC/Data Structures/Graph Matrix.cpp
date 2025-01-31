/* Kyle Wood - Graph Matrix - 9/30/24 */

/*
Instructions:
Create a matrix based graph representation.

It will need to support the following operations.
Ask the user how many points there are.
Ask the user to label those points, ie "A", "B", "C"...
Define the matrix as a square matrix based on the number of points, also keep an array of the labels.
Repeatedly ask the user to define edges between two points. Add these edges to the matrix.
Have a list method that will list out all of the edges in the graph.
Sample Graph Lab Flow:

How many vertices? 6
What is the label for vertex 1? A
What is the label for vertex 2? B
What is the label for vertex 3? C
What is the label for vertex 4? D
What is the label for vertex 5? E
What is the label for vertex 6? F

Define an edge by listing a pair of vertices, i.e. "A B", or -1 to stop.
A B
Added Edge A->B
B A
Added Edge B->A
-1

Your edges are: AB, BA
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Graph {
private:
    int** adjMatrix;             // adjacency matrix using jagged array as directed by professor
    std::string* labels;              // array of string labels
    int numVertices;             // number of vertices - defined by user through console input

public:
    // constructor
    // initialize the graph with user defined number of vertices
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int* [numVertices]; // create an array of pointers for rows

        // create the columns for each row
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0; // initialize matrix with 0s, 
            }
        }

        labels = new std::string[numVertices]; // allocate array for labels
    }

    // destructor
    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i]; // delete each row individually
        }
        delete[] adjMatrix;         // delete the array of row pointers
        delete[] labels;            // delete the labels array
    }

    // set the label for a vertex
    void setLabel(int vertex, const std::string& label) {
        labels[vertex] = label;
    }

    // add an edge between two vertices using their labels
    void addEdge(const std::string& label1, const std::string& label2) {
        int idx1 = getIndex(label1);
        int idx2 = getIndex(label2);
        if (idx1 != -1 && idx2 != -1) {
            adjMatrix[idx1][idx2] = 1;  // mark the edge in the matrix
            std::cout << "Added Edge " << label1 << "->" << label2 << std::endl;
        }
        else {
            std::cout << "Invalid edge definition!" << std::endl;
        }
    }

    // get index of a vertex given its label
    int getIndex(const std::string& label) {
        for (int i = 0; i < numVertices; i++) {
            if (labels[i] == label) {
                return i;
            }
        }
        return -1; // return -1 if label not found
    }

    // list all edges in the graph
    void listEdges() {
        std::cout << "Your edges are: ";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    std::cout << labels[i] << labels[j] << " ";
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int numVertices;
    std::cout << "How many vertices? ";
    std::cin >> numVertices;

    Graph graph(numVertices);

    // get labels for vertices from user
    for (int i = 0; i < numVertices; i++) {
        std::string label;
        std::cout << "What is the label for vertex " << i + 1 << "? ";
        std::cin >> label;
        graph.setLabel(i, label);
    }

    // repeatedly ask for edges until user inputs -1
    std::string vertex1, vertex2;
    while (true) {
        std::cout << "Define an edge by listing a pair of vertices, i.e. \"A B\", or -1 to stop: ";
        std::cin >> vertex1;
        if (vertex1 == "-1") break;
        std::cin >> vertex2;
        graph.addEdge(vertex1, vertex2);
    }

    // list all edges
    graph.listEdges();

    // exit program
    return 0;
}
