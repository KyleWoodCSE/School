/* Kyle Wood - Run Length Encoding - 04 Nov 2024 */

/* 
Prompt:
Build a run length encoding program.
Write a function that takes a string and returns the encoded string using run length encoding.
In main, prompt the user for a string.
Output the encoded string.
Output the compression rate.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// function to perform run length encoding
std::string runLengthEncode(const std::string& input) {
    std::stringstream encoded;
    int count = 1;

    for (int i = 1; i <= input.length(); i++) {
        // if char at index if different from preceding index or the end of the string is reached, append count and char into encoded string and reset count
        if (i == input.length() || input[i] != input[i - 1]) {
            encoded << count << input[i - 1];
            count = 1;
        }
        // increment count for multiples of char
        else {
            count++;
        }
    }

    return encoded.str();
}

// function to calculate compression rate: (1 - encoded/decoded) * 100%
double compressionRate(const std::string& original, const std::string& encoded) {
    return (1.0 - static_cast<double>(encoded.length()) / original.length()) * 100;
}

int main() {
    std::string input;
    std::cout << "Please enter a string to encode or -1 to exit: ";
    std::cin >> input;

    while (input != "-1") {
        std::string encoded = runLengthEncode(input);
        double rate = compressionRate(input, encoded);

        std::cout << "\"" << input << "\"" << " encoded becomes: " << encoded << std::endl;
        std::cout << "The compression rate for this encoding is: " << std::fixed << std::setprecision(2) << rate << "%" << std::endl;

        std::cout << "Please enter a string to encode or -1 to exit: ";
        std::cin >> input;
    } 
    
    std::cout << "Exiting, have a great day!" << std::endl;

    return 0;
}
