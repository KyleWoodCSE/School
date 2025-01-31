/**************************************************/
/*Lab 1 Question 5                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 02/11/23                                  */
/*This Program adds two fractions provided by user*/
/*                                                */
/**************************************************/

#include<stdio.h>

void main()
{
	//Declaration
	int num1, num2, num3, num4, denom, numer1, numer2, numerTotal;

	//Data/input
    printf("Enter First fraction : ");
    scanf("%d/%d", &num1, &num2);
    printf("Enter Second fraction : ");
    scanf("%d/%d", &num3, &num4);

	//Processing/Calculations
    denom = num2 * num4;
    numer1 = num1 * num4;
    numer2 = num3 * num2;
    numerTotal = numer1 + numer2;

	//Output
    printf("\nThe sum of the two fractions is %d/%d", numerTotal, denom);

	return 0;
}

/*
Test run 1
Enter First fraction : 5/6
Enter Second fraction : 3/4

The sum of the two fractions is 38/24

Test run 2
Enter First fraction : 7/9
Enter Second fraction : 5/5

The sum of the two fractions is 80/45

Test run 3
Enter First fraction : 7/15
Enter Second fraction : 5/16

The sum of the two fractions is 187/240
*/
