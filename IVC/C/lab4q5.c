/**************************************************/
/*Lab 4 Question 5                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 05/07/23                                  */
/*This Program counts the number of words in a    */
/*string                                          */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    char userInput[30];
    int wordCount = 1;
    int i = 0;

	//Data/input
    printf("Enter the sentence : ");
    gets(userInput);

	//Processing/Calculations
    while(userInput[i] != '\0')
    {
        if(userInput[i] == ' ')
        {
            wordCount++;
        }
        i++;
    }

	//Output
    printf("The total count of words is : %d\n", wordCount);

	return 0;
}

/*
Test run 1
Enter the sentence : How are you
The total count of words is : 3

Test run 2
Enter the sentence : I love tacos al pastor
The total count of words is : 5

Test run 3
Enter the sentence : Will I ever get my degree?
The total count of words is : 6


*/

