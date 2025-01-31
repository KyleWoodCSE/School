/**************************************************/
/*Lab 2 Question 1                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program determines if user input char is a */
/*vowel                                           */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    char userInput;

	//Data/input
	printf("Enter any character: ");
    scanf("%c", &userInput);

	//Processing/Calculations
	//Output
	// both sections combined here, comparison is done then output is produced
    if(userInput=='a' || userInput == 'e' || userInput == 'i' || userInput == 'o' || userInput == 'u')
    {
        printf("%c is a vowel", userInput);
    }
    else if(userInput=='A' || userInput == 'E' || userInput == 'I' || userInput == 'O' || userInput == 'U')
    {
        printf("%c is a vowel", userInput);
    }
    else
    {
        printf("%c is not a vowel", userInput);
    }

	return 0;
}

/*
Test run 1
Enter any character: h
h is not a vowel

Test run 2
Enter any character: i
i is a vowel

Test run 3
Enter any character: K
K is not a vowel

Test run 4
Enter any character: U
U is a vowel

Test run 5
Enter any character: d
d is not a vowel
*/

