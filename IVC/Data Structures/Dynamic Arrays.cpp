/* Kyle Wood - Dynamic Arrays List - 8/19/24 */

#include <iostream>

int main()
{
    // prompt user for size and create array of user size
    int size;
    int input;
    std::cout << "Enter a size for your array: ";
    std::cin >> size;
    int* myArray = new int[size];

    // prompt user for values to put into array
    // ends if all values entered or -1 entered
    for (int i = 0; i < size; i++) {
        std::cout << "Enter number " << i + 1 << " of " << size << " for the array: ";
        std::cin >> input;
        if (input == -1) {
            std::cout << "You have entered -1, terminating program.";
            return 0;
        }
        else {
            myArray[i] = input;
        }
    }

    // print array
    std::cout << "The values of your array are: ";
    for (int i = 0; i < size; i++) {
        std::cout << myArray[i] << " ";
    }

    delete[] myArray;
    return 0;
}


