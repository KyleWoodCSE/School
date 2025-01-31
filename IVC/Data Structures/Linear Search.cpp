/* Kyle Wood - Linear Search - 8/22/24 */

/*
Instruction:
Search an un-ordered array an integers for a value, if the value is found return the index of its position in the array, if not found, return -1.
*/

#include <iostream>

int searchArray(int* array, int size, int num) {
    // check if input number is in array
    // if yes, return index where number is in array
    // if no, return -1
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            return i;
        }
    }
    return -1;
}

int Find(int numbers[], int size, int key, int occurence) {
    // create variable to count instances of searched value in array
    int count = 0;
    // iterate through the array to compare values to the given key and increment count for each instance
    for (int i = 0; i < size; i++) {
        if (numbers[i] == key) {
            count++;
            // if count reaches number of occurences desired, return the index of value in the array
            if (count == occurence) {
                return i;
            }
        }
        // return -1 for error handling
        else {
            return -1;
        }
    }
}

int main()
{
    // intitialize array and variables
    int userNum, result;
    const int size = 10;
    int array[size] = { 99, 11, 44, 33, 22, 55, 88, 77, 0, 69 };
    // get user input to search array with
    std::cout << "Enter a number between 0-100 to see if it's in the array: ";
    std::cin >> userNum;
    result = searchArray(array, size, userNum);
    // display results of the search
    if (result == -1) {
        std::cout << "Sorry, your number was not found in the array :(" << std::endl;
    }
    else {
        std::cout << "Congrats! Your number " << userNum << " was found in the array at index " << result << " :)" << std::endl;
    }
    
    return 0;
}


