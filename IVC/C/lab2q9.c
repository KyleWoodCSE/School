/**************************************************/
/*Lab 2 Question 9                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program builds a triangle of numbers with a*/
/*base determined by user                         */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int i, triNums, base;

	//Data/input + Output
    printf("Enter base size of triangle for pattern : ");
    scanf("%d", &base);
    printf("\n");

	//Processing/Calculations
    for(i = 1; i <= base; i++)
    {
        triNums = 1;
        while(triNums <= i)
        {
            printf("%d", triNums);
            triNums++;
        }
        printf("\n");
    }

	return 0;
}

/*
Test run 1
Enter base size of triangle for pattern : 5

1
12
123
1234
12345

Test run 2
Enter base size of triangle for pattern : 15

1
12
123
1234
12345
123456
1234567
12345678
123456789
12345678910
1234567891011
123456789101112
12345678910111213
1234567891011121314
123456789101112131415

Test run 3
Enter base size of triangle for pattern : 8

1
12
123
1234
12345
123456
1234567
12345678

*/

