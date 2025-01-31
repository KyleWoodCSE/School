/* Kyle Wood - Linear Search Double - 8/25/24 */

#include <iostream>

int searchArray(int* array, int size, int num) {
    // check if input number is in array
    // if yes, increment counter. If counter reaches 2, return index of second instance
    // if no, return -1
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            count++;
        }
        if (count == 2) {
            return i;
        }
    }
    return -1;
}

int FindLast(int numbers[], int size, int key) {
    // initialize value to -1 to use as error handling if the key is not present in the array
    int result = -1;
    // iterate through array from first index 
    for (int i = 0; i < size; i++) {
        // if the key number is found, update the index value
        if (numbers[i] == key) {
            result = i;
        }
    }
    return result;
}

int main()
{
    // intitialize array and variables
    int userNum, result;
    const int size = 10;
    int array[size] = { 99, 11, 69, 33, 22, 55, 88, 77, 0, 69 };
    // get user input to search array with
    std::cout << "Enter a number between 0-100 to see if it's in the array twice: ";
    std::cin >> userNum;
    result = searchArray(array, size, userNum);
    // display results of the search
    if (result == -1) {
        std::cout << "Sorry, your number was not found twice in the array." << std::endl;
    }
    else {
        std::cout << "Congrats! Your number " << userNum << " was found in the array a second time at index " << result << "." << std::endl;
    }

    result = FindLast(array, size, userNum);
    if (result == -1) {
        std::cout << "Sorry, your number was not found in the array." << std::endl;
    }
    else {
        std::cout << "Your number " << userNum << " was found in the array a for the final time at index " << result << "." << std::endl;
    }

    return 0;
}


