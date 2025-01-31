/**************************************************/
/*Lab 1 Question 2                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 02/11/23                                  */
/*This Program takes two integers from user and   */
/*calculates sum, product, difference, quotient,  */
/*and remainder of the two integers               */
/*                                                */
/**************************************************/

#include<stdio.h>

void main()
{
	//Declaration
	int num1, num2, sum, product, diff, quotient, remainder;

	//Data/input
    printf("Enter two numbers: ");
    scanf("%d%d",&num1, &num2);

	//Processing/Calculations
    sum = num1 + num2;
    product = num1 * num2;
    diff = num1 - num2;
    quotient = num1 / num2;
    remainder = num1 % num2;

	//Output
    printf("The sum is %d\n", sum);
    printf("The product is %d\n", product);
    printf("The difference is %d\n", diff);
    printf("The quotient is %d\n", quotient);
    printf("The remainder is %d\n", remainder);

	return 0;
}

/*
Test run 1
Enter two numbers: 20 5
The sum is 25
The product is 100
The difference is 15
The quotient is 4
The remainder is 0

Test run 2
Enter two numbers: 5 20
The sum is 25
The product is 100
The difference is -15
The quotient is 0
The remainder is 5

Test run 3
Enter two numbers: 15 42
The sum is 57
The product is 630
The difference is -27
The quotient is 0
The remainder is 15
*/
