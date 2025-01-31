/* Kyle Wood - Min Heap Lab - 9/23/24 */

/*
Instructions:
Create a heap class/struct

Fields:
-Array of data points
-Count
Methods:
Add(data)
-Adds the data to the tree in heap order.
Delete(void)
-Returns the data from the root, and replaces the value at the root with the smallest value in the tree.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    int* heap;     // Array to hold heap elements
    int capacity;  // Max size of the heap
    int count;     // Current number of elements in the heap

    // Helper function to heapify down (for maintaining min heap property on delete)
    void heapifyDown(int index) {
        while (index < count) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            // Find the smallest between parent and children
            if (leftChild < count && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < count && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            // If the smallest is not the parent, swap and continue heapifying
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

public:
    // Constructor to initialize the heap with a given capacity
    MinHeap(int size) : capacity(size), count(0) {
        heap = new int[capacity];  // Dynamically allocate array for the heap
    }

    // Destructor to free the allocated memory
    ~MinHeap() {
        delete[] heap;
    }

    // Add a new data point to the heap in order without maintaining the min heap property
    void Add(int data) {
        if (count == capacity) {
            throw overflow_error("Heap is full! Cannot add more elements.");
        }
        heap[count] = data;  // Simply add the data at the end of the array
        count++;
    }

    // Delete and return the root data (min value), and then maintain the min heap property
    int Delete() {
        if (count == 0) {
            throw underflow_error("Heap is empty! No elements to delete.");
        }

        int rootData = heap[0];
        heap[0] = heap[count - 1];  // Replace root with the last element
        count--;
        heapifyDown(0);  // Rebalance the heap by moving the root down
        return rootData;
    }

    // Get the count of elements in the heap
    int getCount() const {
        return count;
    }

    // Display the heap elements
    void displayHeap() const {
        cout << "Heap: ";
        for (int i = 0; i < count; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size = 10;  // Specify the size of the heap
    MinHeap heap(size);

    // Adding data points (in order, no heapifying)
    heap.Add(20);
    heap.Add(15);
    heap.Add(30);
    heap.Add(10);
    heap.Add(25);

    heap.displayHeap();  // Display the heap before deletion

    // Deleting the root element (heapify down to maintain min-heap property)
    cout << "Deleted root: " << heap.Delete() << endl;
    heap.displayHeap();  // Display the heap after deletion

    // Adding more data points
    heap.Add(5);
    heap.Add(17);

    heap.displayHeap();  // Display the heap after adding new elements

    cout << "Deleted root: " << heap.Delete() << endl;
    heap.displayHeap();  // Display the heap after second deletion

    return 0;
}
