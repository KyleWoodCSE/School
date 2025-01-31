/**************************************************/
/*Lab 2 Question 2                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program determines if user input is lower  */
/*case letter, upper case letter, or digit        */
/*                                                */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
	char userInput;

	//Data/input
	printf("Enter any character: ");
	scanf("%c", &userInput);

	//Processing/Calculations + Output
    if(userInput >= 'a' && userInput <= 'z')
    {
        printf("Lowercase character was entered");
    }
    else if(userInput >= 'A' && userInput <= 'Z')
    {
        printf("Uppercase character was entered");
    }
    else
    {
        printf("A digit was entered");
    }

	return 0;
}

/*
Test run 1
Enter any character: C
Uppercase character was entered

Test run 2
Enter any character: b
Lowercase character was entered

Test run 3
Enter any character: 5
A digit was entered

Test run 4
Enter any character: K
Uppercase character was entered

Test run 5
Enter any character: 9
A digit was entered

Test run 6
Enter any character: g
Lowercase character was entered
*/

