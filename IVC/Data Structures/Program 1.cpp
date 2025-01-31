/* Kyle Wood - Program 1 - 8/26/24 */

/*
For this assignment, you are to write a program, which will calculate the results of Reverse Polish expressions that are provided by the user.

You must use a linked list to maintain the stack for this program (array implementations of the stack will not receive full credit).

You must handle the following situations (errors):
Too many operators (+ - / *)
Too many operands (doubles)
Division by zero

The program will take in a Polish expression that separates the operators and operands by a single space, and terminates the expression with an equals sign.

The program will continue to take and evaluate expressions until the user enters a zero (0) on a line by itself followed by a new line.

Your sample output should show the handling of all the error conditions as well as make use of all of the operators.

Sample IO: (note: formatting of output isn’t a critical issue)
Input Output
10 15 + = 25
10 15 - = -5
2.5 3.5 + = 6 (or 6.0)
10 0 / = Error: Division by zero
10 20 * / = Error: Too many operators
12 20 30 / = Error: Too many operands
-10 -30 - = 20
100 10 50 25 / * - -2 / = -40
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

class Node {
public:
    std::string data;
    Node* next;

    // make optional parameter
    Node(std::string input = "", Node* ptr = 0) {
        data = input;
        next = ptr;
    }
};

class NumNode {
public:
    double numData;
    NumNode* next;

    // make optional parameter
    NumNode(double num = 0, NumNode* ptr = 0) {
        numData = num;
        next = ptr;
    }
};

class List {
private:
    Node* top;
    NumNode* numTop;
    int count = 0;
    int numCount = 0;

public:
    List() {
        top = 0;
        numTop = 0;
    }

    int GetCount() {
        return count;
    }

    int GetNumCount() {
        return numCount;
    }

    void Push(std::string input) {
        //std::cout << "Adding string '" << input << "' to the top of the expression stack." << std::endl;
        Node* pushNode = new Node(input);

        // check if the Stack is empty
        // if yes, establish new node as the beginning of the stack
        if (IsEmpty()) {
            top = pushNode;
        }
        // if the stack is not empty, the new node is made the top and points to the previous top node
        else {
            pushNode->next = top;
            top = pushNode;
        }

        // increment counter to indicate number of nodes on stack
        count++;
    }

    void PushNum(double num) {
        //std::cout << "Adding number '" << num << "' to the top of the number stack." << std::endl;
        NumNode* pushNode = new NumNode(num);

        // check if the Stack is empty
        // if yes, establish new node as the beginning of the stack
        if (IsNumEmpty()) {
            numTop = pushNode;
        }
        // if the stack is not empty, the new node is made the top and points to the previous top node
        else {
            pushNode->next = numTop;
            numTop = pushNode;
        }

        // increment counter to indicate number of nodes on stack
        numCount++;
    }

    std::string Pop() {
        // if the stack is empty, output an error
        if (IsEmpty()) {
            return "Error! Cannot pop more values - stack is empty.";
        }
        else {
            // grab expression from top node for return value
            std::string expression = top->data;
            // keep tab on current top node to be deleted
            Node* temp;
            temp = top;
            // shift next node down to be new top
            top = top->next;
            // decrement counter to indicate number of nodes on stack
            count--;
            // "pop" or delete the old top node;
            delete temp;
            // end with returning the data of the popped node
            return expression;
        }
    }

    double PopNum() {
        // if the stack is empty, output an error
        if (IsNumEmpty()) {
            std::cout << "Error: num stack is empty" << std::endl;
            return -1;
        }
        else {
            // grab num from top node for return value
            double num = numTop->numData;
            // keep tab on current top node to be deleted
            NumNode* temp;
            temp = numTop;
            // shift next node down to be new top
            numTop = numTop->next;
            // decrement counter to indicate number of nodes on stack
            numCount--;
            // "pop" or delete the old top node
            delete temp;
            // end with returning the data of the popped node
            return num;
        }
    }

    bool IsEmpty() {
        if (top == 0) {
            return true;
        }
        return false;
    }
    
    bool IsNumEmpty() {
        if (numTop == 0) {
            return true;
        }
        return false;
    }

    // the following two output methods were used for unit testing
    void outputData() {
        // indicate how many nodes are currently on the expression stack
        std::cout << "The stack currently contains " << count << " node(s)." << std::endl;
        // if the expression stack contains nodes, output their data
        if (top != 0) {
            std::cout << "The stack expressions from top to bottom are: " << std::endl;
            for (Node* printNode = top; printNode != 0; printNode = printNode->next) {
                std::cout << "'" << printNode->data << "'" << std::endl;
            }
            std::cout << std::endl;
        }

    }

    void OutputNumData() {
        // indicate how many nodes are currently on the number stack
        std::cout << "The stack currently contains " << numCount << " node(s)." << std::endl;
        // if the number stack contains nodes, output their data
        if (numTop != 0) {
            std::cout << "The stack numbers from top to bottom are: " << std::endl;
            for (NumNode* printNode = numTop; printNode != 0; printNode = printNode->next) {
                std::cout << "'" << printNode->numData << "'" << std::endl;
            }
            std::cout << std::endl << std::endl;
        }

    }

    ~List() {
        for (Node* ptr; top != 0; ) {
            ptr = top->next;
            delete top;
            top = ptr;
        }
        for (NumNode* ptr; numTop != 0; ) {
            ptr = numTop->next;
            delete numTop;
            numTop = ptr;
        }
    }
};

bool IsOperator(char c) {
    switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

double PolishMath(double num1, double num2, char op) {
    // determine which operation to carry out based on operator character
    switch (op) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        return -1;
    }
}

int main()
{
    // create a stack to hold Polish expressions entered by the user through the console terminal
    List expressionStack;
    std::string userInput;
    std::cout << "Please enter Polish expressions for analysis ending with an '='" << std::endl;
    std::cout << "Enter 0 on its own line to finish." << std::endl;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, userInput);
    // allow user to terminate entering expressions by inputting only 0 on the line
    while (userInput != "0") {
        expressionStack.Push(userInput);
        std::cout << "Enter an expression: ";
        std::getline(std::cin, userInput);
    }

    // if user terminated without entering any expressions, print notice that they have done so
    if (expressionStack.GetCount() == 0) {
        std::cout << "You have terminated without entering any expressions. Goodbye!" << std::endl;
    }
    else {
        std::cout << "The results of your Polish expressions are: " << std::endl;
    }

    while (expressionStack.GetCount() != 0) {
        // create a new stack to hold numbers from the expression as we iterate through
        List numStack;
        std::string expression, unit; // unit used by string stream to cycle through individual parts of the expression
        int error = 0; // track if an error was encountered to evaluate if we end this loop or finish with the expression results
        double num1, num2, result, answer; // number variables to perform the arithmetic and store results

        // pull an expression from the stack of inputted expressions
        expression = expressionStack.Pop();
        // use a stringstream to cycle through each word/number in the input
        std::stringstream stream;
        stream.str(expression);
        // cycle through each individual word/number of the string and print them on their own lines
        stream >> unit;
        while (unit != "=") {
            // check if string entry is a number (extra logic for negative numbers)
            // if yes, add number to number stack
            if (isdigit(unit[0]) || (unit[0] == '-' && isdigit(unit[1]))) {
                double num = std::stod(unit);
                numStack.PushNum(num);
            }
            // if an operator in encountered, attempt to evaluate the expression
            else if (IsOperator(unit[0])) {
                // check if their are enough operands to perform an operation
                if (numStack.GetNumCount() <= 1) {
                    std::cout << expression << " Error: Too many operators." << std::endl;
                    error++;
                }
                else {
                    // pop the top 2 numbers on the number stack for math operation
                    num2 = numStack.PopNum();
                    num1 = numStack.PopNum();
                    // error handling for dividing by zero
                    if (num2 == 0 && unit[0] == '/') {
                        std::cout << expression << " Error: Divide by zero." << std::endl;
                        error++;
                    }
                    else {
                        result = PolishMath(num1, num2, unit[0]); // perform the operation
                        numStack.PushNum(result); // add result to the stack
                    }
                    
                }
            }
            // move to the next item in the string stream
            stream >> unit;
        }
        // number stack should only end up with 1 item, being the final result
        // if more numbers are still present, there were too many operands for the expression
        if (numStack.GetNumCount() > 1) {
            std::cout << expression << " Error: Too many operands." << std::endl;
        }
        // if an error was encountered, move on to next expression
        else if (error > 0) {
            continue;
        }
        // if no errors encountered, print expression with the evaluated answer
        else {
            answer = numStack.PopNum();
            std::cout << expression << " " << answer << std::endl;
        }
    }

    return 0; //exit the program with no errors
}


