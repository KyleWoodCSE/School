/**************************************************/
/*Lab 4 Question 7                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 05/07/23                                  */
/*This Program counts patterns in a string        */
/*                                                */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    char userInput[50];
    char pattern[10];
    int inputLength = 0;
    int patternLength = 0;
    int count = 0;
    int i = 0;

	//Data/input
    printf("Enter string : ");
    gets(userInput);
    printf("Enter the pattern : ");
    gets(pattern);

	//Processing/Calculations
    while(pattern[i] != '\0')
    {
        patternLength++;
        i++;
    }
    i = 0;
    while(userInput[i] != '\0')
    {
        inputLength++;
        i++;
    }

    for(i = 0; i <= (inputLength - patternLength); i++)
    {
        int j = 0;
        int k = i;
        while(userInput[k] == pattern[j])
        {
            j++;
            k++;
            if(j == patternLength)
            {
                count++;
            }
        }
    }

	//Output
    if(count == 0)
    {
        printf("\nPattern not found\n");
    }
    else
    {
        printf("\nPattern found %d times\n", count);
    }

	return 0;
}

/*
Test run 1
Enter string : She sells sea shells on the sea shore
Enter the pattern : sea

Pattern found 2 times

Test run 2
Enter string : dog go woof woof woof bark woof
Enter the pattern : woof

Pattern found 4 times

Test run 3
Enter string : Kyle eats tacos, tacos, tacos, tacos, and tacos
Enter the pattern : tacos

Pattern found 5 times


*/

