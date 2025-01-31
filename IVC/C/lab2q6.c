/**************************************************/
/*Lab 2 Question 6                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program takes numeric input from user until*/
/*-1 is entered. count number of positive,        */
/*and zero integers entered by user until -1      */
/*                                                */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int num, posCount, negCount, zeroCount;
    posCount = negCount = zeroCount = 0;

	//Data/input
    printf("Enter any number, -1 to quit : ");
    scanf("%d", &num);

	//Processing/Calculations
    while(num != -1)
    {
        if(num == 0)
        {
            zeroCount++;
        }
        else if(num > 0)
        {
            posCount++;
        }
        else if(num < -1)
        {
            negCount++;
        }
        printf("Enter any number, -1 to quit : ");
        scanf("%d", &num);
    }

	//Output
    printf("\nCount of positive numbers entered = %d\n", posCount);
    printf("Count of negative numbers entered = %d\n", negCount);
    printf("Count of zeros entered = %d", zeroCount);

	return 0;
}

/*
Test run 1
Enter any number, -1 to quit : -12
Enter any number, -1 to quit : 108
Enter any number, -1 to quit : -24
Enter any number, -1 to quit : 0
Enter any number, -1 to quit : -23
Enter any number, -1 to quit : -1

Count of positive numbers entered = 1
Count of negative numbers entered = 3
Count of zeros entered = 1

Test run 2
Enter any number, -1 to quit : -1

Count of positive numbers entered = 0
Count of negative numbers entered = 0
Count of zeros entered = 0

Test run 3
Enter any number, -1 to quit : 15
Enter any number, -1 to quit : 123456789
Enter any number, -1 to quit : -987654321
Enter any number, -1 to quit : 888
Enter any number, -1 to quit : -666
Enter any number, -1 to quit : 1313
Enter any number, -1 to quit : 7
Enter any number, -1 to quit : 420
Enter any number, -1 to quit : -69
Enter any number, -1 to quit : 0
Enter any number, -1 to quit : 10010010
Enter any number, -1 to quit : 0
Enter any number, -1 to quit : 0
Enter any number, -1 to quit : 9173
Enter any number, -1 to quit : 0
Enter any number, -1 to quit : -1

Count of positive numbers entered = 8
Count of negative numbers entered = 3
Count of zeros entered = 4

*/

