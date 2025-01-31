#include <iostream>
#include <iomanip>

struct userAccount {
    // struct to store user info
    std::string username;
    std::string nationality;
    int age;
    float accountBalance;
};

int main(){
    // create array to store users
    struct userAccount accts[20];
    
    // initialize variables to store user data
    std::string username;
    std::string nationality;
    int age;
    float accountBalance;
    int count = 0;
    float balanceSum = 0.0;
    float highestBalance = 0.0;
    int userFromSweden = 0;
    int countBelow21 = 0;
    std::string below21 = "No";

    // prompt the user for action
    std::cout << "Please enter information to database in the format of <username> <nationality> <age> <accountBalance>, separated each user by a newline: " << std::endl;

    // take user input to fill array of users
    while (std::cin >> username >> nationality >> age >> accountBalance) {
        userAccount user;
        user.username = username;
        user.nationality = nationality;
        user.age = age;
        user.accountBalance = accountBalance;
        accts[count] = user;
        
        // increment index and add to total balance sum
        count++;
        balanceSum+=accountBalance;

        // check is user is from Sweden or under 21
        if (nationality == "Swedish") {
            userFromSweden++;
        }
        if (age < 21) {
            countBelow21++;
        }
    }

    // update if there are users below 21
    if (countBelow21 > 0) {
        below21 = "Yes";
    }

    // find highest balance amongst users in array
    for (int i=0; i < count; i++) {
        // find highest balance amongst users
        if (accts[i].accountBalance > highestBalance) {
            highestBalance = accts[i].accountBalance;
        }
    }

    // output questions and answers
    std::cout << "Q: What is the highest account balance amongst all the users?" << std::endl;
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "A: $" << highestBalance << std::endl;
    std::cout << "Q: What's the sum of account balance of all users?" << std::endl;
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "A: $" << balanceSum << std::endl;
    std::cout << "Q: How many users come from Sweden?" << std::endl;
    std::cout << "A: " << userFromSweden << std::endl;
    std::cout << "Q: Do we have any user younger than 21?" << std::endl;
    std::cout << "A: " << below21 << std::endl;

    return 0;
}