/**************************************************/
/*Lab 1 Question 3                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 02/11/23                                  */
/*This Program takes user input for 5 digit number*/
/*and separates number into individual digits with*/
/*single space separation                         */
/*                                                */
/**************************************************/

#include<stdio.h>

void main()
{
	//Declaration
	int num, firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit;

	//Data/input
    printf("Enter a number: ");
    scanf("%d", &num);

	//Processing/Calculations
    firstDigit = num / 10000;
    secondDigit = (num / 1000) % 10;
    thirdDigit = ((num / 100) % 100 ) % 10;
    fourthDigit = (((num / 10) % 1000) % 100) % 10;
    fifthDigit = (((num % 10000) % 1000) % 100) %10;

	//Output
    printf("%d %d %d %d %d", firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit);

	return 0;
}

/*
Test run 1
Enter a number: 42139
4 2 1 3 9

Test run 2
Enter a number: 63541
6 3 5 4 1

Test run 3
Enter a number: 70991
7 0 9 9 1
*/
