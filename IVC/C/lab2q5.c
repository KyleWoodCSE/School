/**************************************************/
/*Lab 2 Question 5                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program states whether entered number is   */
/*or odd. If not between 1-10, state out of range */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int num;

	//Data/input
    printf("Enter a number between 1 to 10 : ");
    scanf("%d", &num);

	//Processing/Calculations + Output
	switch(num)
	{
        case 1: case 3: case 5: case 7: case 9: printf("You entered %d. That is an odd number.", num);
            break;
        case 2: case 4: case 6: case 8: case 10: printf("You entered %d. That is an even number.", num);
            break;
        default: printf("Number entered is outside the range.");
	}

	return 0;
}

/*
Test run 1
Enter a number between 1 to 10 : 5
You entered 5. That is an odd number.

Test run 2
Enter a number between 1 to 10 : 12
Number entered is outside the range.

Test run 3
Enter a number between 1 to 10 : 8
You entered 8. That is an even number.

Test run 4
Enter a number between 1 to 10 : -6789
Number entered is outside the range.

Test run 5
Enter a number between 1 to 10 : 9
You entered 9. That is an odd number.

Test run 6
Enter a number between 1 to 10 : 2
You entered 2. That is an even number.
*/

