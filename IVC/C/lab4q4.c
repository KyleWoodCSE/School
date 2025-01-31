/**************************************************/
/*Lab 4 Question 4                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 05/07/23                                  */
/*This Program reads and prints text until * is   */
/*encountered                                     */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    char userInput[30];
    int i = 0;
    int count = 0;
    char c;

	//Data/input
    printf("Enter * to end\n");
    printf("Enter the text : ");


	//Processing/Calculations
    while((c = getchar()) != '*')
    {
        userInput[i] = c;
        count++;
        i++;
    }
    userInput[i] = '\0';

	//Output
	printf("The text is : %s", userInput);
    printf("\nThe count of the characters is : %d\n", count);


	return 0;
}

/*
Test run 1
Enter * to end
Enter the text : Hi there*
The text is : Hi there
The count of the characters is : 8

Test run 2
Enter * to end
Enter the text : Monkey butt*
The text is : Monkey butt
The count of the characters is : 11

Test run 3
Enter * to end
Enter the text : Two more weeks!*
The text is : Two more weeks!
The count of the characters is : 15


*/

