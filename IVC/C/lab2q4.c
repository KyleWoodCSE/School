/**************************************************/
/*Lab 2 Question 4                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program use switch statement to determine  */
/*if the character is a vowel or not              */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    char userInput;

	//Data/input
    printf("Enter a character : ");
    scanf("%c", &userInput);

	//Processing/Calculations + Output
    switch(userInput)
    {
        case 'a': case 'e': case 'i': case 'o': case 'u': printf("%c is a vowel", userInput);
            break;
        case 'A': case 'E': case 'I': case 'O': case 'U': printf("%c is a vowel", userInput);
            break;
        default: printf("%c is not a vowel", userInput);
    }

	return 0;
}

/*
Test run 1
Enter a character : b
b is not a vowel

Test run 2
Enter a character : B
B is not a vowel

Test run 3
Enter a character : e
e is a vowel

Test run 4
Enter a character : I
I is a vowel

Test run 5
Enter a character : K
K is not a vowel

Test run 6
Enter a character : o
o is a vowel
*/

