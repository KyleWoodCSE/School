/**************************************************/
/*Lab 2 Question 3                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program check if number is positive,       */
/*negative, or zero                               */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int num;

	//Data/input
    printf("Enter any number: ");
    scanf("%d", &num);

	//Processing/Calculations + Output
    if(num == 0)
    {
        printf("The number is equal to zero");
    }
    else if(num > 0)
    {
        printf("The number is positive");
    }
    else
    {
        printf("The number is negative");
    }

	return 0;
}

/*
Test run 1
Enter any number: 0
The number is equal to zero

Test run 2
Enter any number: 15
The number is positive

Test run 3
Enter any number: -25
The number is negative

Test run 4
Enter any number: 71588
The number is positive

Test run 5
Enter any number: -51691
The number is negative

Test run 6
Enter any number: 66642069
The number is positive
*/

