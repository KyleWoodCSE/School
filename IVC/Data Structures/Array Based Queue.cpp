/* Kyle Wood - Array Based Queue - 8/22/24 */

/*
Instructions:
Create a class/struct.

Members:
MaxSize const = 10
Define an array that holds 10 items.
Count - indicates how many items are on the queue.
Front - where the front of the queue is in the array. 
Back - Where the end of the queue is in the array. 


Methods:
En-queue O(1)
- Accepts a number and adds to the end of the queue.
- If the queue is full emit an error indicating full.
De-queue O(1)
- Returns a number from the front of the queue.
- If the queueis empty, emit an error indicating the queueis empty.
IsEmpty
- Returns a boolean indicating if the queue is empty.
*Note that the front and back can wrap around the end of the array over time.
*/

#include <iostream>

class Queue {
private:
    const int MaxSize = 10;
    int front, back, count;
    int queueArray[10] = {};

public:
    Queue() {
        front = back = count = 0;
    }

    void EnQueue(int num) {
        // check if queue is full before adding a value
        if (count == MaxSize) {
            std::cout << "The Queue is full, please remove a number if you would like to add another." << std::endl << std::endl;
        }
        else {
            std::cout << "Adding " << num << " to the queue." << std::endl;
            queueArray[back] = num;
            // modulo allows for index to wrap around in circular fashion
            back = (back + 1) % MaxSize;
            count++;
            std::cout << "The queue currently holds " << count << " value(s)." << std::endl;
        }
    }

    int DeQueue() {
        // check if queue is empty before dequeueing value
        if (IsEmpty()) {
            std::cout << "The Queue is empty, please add a number first if you would like to remove a number. Error number ";
            return 404;
            std::cout << std::endl << std::endl;
        }
        else {
            // maintain return value index before incrementing the front index to next in line for queue
            int temp = front;
            // determine index value in circular logic to loop back to first index after passing max index number
            front = (front + 1) % MaxSize;
            count--;
            return queueArray[temp];
        }        
    }

    bool IsEmpty() {
        if (count == 0) {
            return true;
        }
        return false;
    }

    void printCount() {
        std::cout << "The queue currently holds " << count << " value(s)." << std::endl; 
    }
};

int main()
{
    // initialize queue
    Queue queue;
    std::cout << "Implementing an array based queue." << std::endl << std::endl;
    
    //test error for dequeue on empty queue
    std::cout << "Testing error for dequeue attempt on empty queue:" << std::endl;
    std::cout << queue.DeQueue() << std::endl << std::endl;
    
    // add values to the queue
    queue.EnQueue(1);
    queue.EnQueue(2);
    queue.EnQueue(3);
    queue.EnQueue(4);
    queue.EnQueue(5);
    queue.EnQueue(6);
    queue.EnQueue(7);
    queue.EnQueue(8);
    queue.EnQueue(9);
    queue.EnQueue(10);
    std::cout << std::endl;

    // test error for adding to full queue
    std::cout << "Testing error for adding to a full queue:" << std::endl;
    queue.EnQueue(11);

    // remove values from the queue
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    queue.printCount();
    std::cout << "Removing " << queue.DeQueue() << " from the queue." << std::endl;
    std::cout << std::endl;
    queue.printCount();
}

