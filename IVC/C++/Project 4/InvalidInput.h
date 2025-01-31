// InvalidInput.h
//
// This is the declaration of the InvalidInput class,
// which has a message that is output when Exception is thrown

#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <iostream>
#include <string>

class InvalidInput {
    
    private:
        std::string message;

    public:
        // constructor
        InvalidInput(std::string input) {
            message = "Invalid input \"" + input + "\".\n\n";
        };
        // function to output invalid input to user
        void reason() {std::cout << message;}
};

#endif // INVALIDINPUT_H