/**************************************************/
/*Lab 4 Question 6                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 05/07/23                                  */
/*This Program replaces commas in a string with   */
/*semicolons                                      */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    char userInput[30];

	//Data/input
	printf("Enter the text : ");
    gets(userInput);

	//Processing/Calculations
    for(int i = 0; i < 30; i++)
    {
        if(userInput[i] == ',')
        {
            userInput[i] = ';';
        }
    }

	//Output
    printf("The copied text is : %s\n", userInput);

	return 0;
}

/*
Test run 1
Enter the text : Hello, how are you
The copied text is : Hello; how are you

Test run 2
Enter the text : Fido, a dog, loves bones
The copied text is : Fido; a dog; loves bones

Test run 3
Enter the text : I, really, love, tacos
The copied text is : I; really; love; tacos


*/

