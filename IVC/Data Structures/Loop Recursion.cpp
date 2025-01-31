/* Kyle Wood - Loop Recursion Lab - 8/26/24 */

/*
Instruction:
Create a method that uses a loop to calculate the summation.
}
*/

#include <iostream>

int Sum(int n) {
    if (n < 1) {
        return 0;
    }
    return Sum(n - 1) + n;
}

int main()
{
    int userInput;
    std::cout << "Enter a number for sum calculation: ";
    std::cin >> userInput;
    std::cout << "The result from your input is: " << Sum(userInput) << std::endl;

    return 0;
}

