/* Kyle Wood - IO - 8/22/24 */

/*
Instructions:
Read a sentence from the console.
Break the sentence into words using the space character as a delimiter.
Iterate over each word, if the word is a numeric value then print its value doubled, otherwise print out the word, with each output on its own line.

Sample Run:
Sentence: Hello world, there are 3.5 items.

Output:
Hello
world,
there
are
7
items.
*/

#include <iostream>
#include <string>
#include <sstream>

int main()
{
    // get user input from the console
    std::string userInput;
    std::string word;
    std::cout << "Please enter a sentence: ";
    getline(std::cin, userInput);
    // use a stringstream to cycle through each word/number in the input
    std::stringstream stream;
    stream.str(userInput);
    // cycle through each individual word/number of the string and print them on their own lines
    while (stream >> word) {
        // check if string entry is a number
        // if yes, doulbe the number before printing
        if (isdigit(word[0])) {
            double num = std::stod(word);
            num = num * 2;
            std::cout << num << std::endl;
        }
        else {
            std::cout << word << std::endl;
        }
    }

    return 0;
}


