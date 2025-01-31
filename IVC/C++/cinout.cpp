#include <iostream>
#include <string>

int main(){
    std::string text = "This is a linesss";
    std::string output = "";
    int text_size = text.size(); //get length of string
    for (int i = 0; i<text_size; i++){
        if(text[i] != 's') { //string comparison
            output += text[i]; //append to string
        }
    }
    std::cout << output << std::endl;
    return 0;
}