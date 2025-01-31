/**************************************************/
/*Lab 2 Question 7                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 03/05/23                                  */
/*This Program count the sum of numbers from user */
/*defined m top n                                 */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int n, m, sum;
    sum = 0;

	//Data/input
    printf("Enter the value of m : ");
    scanf("%d", &m);
    printf("Enter the value of n : ");
    scanf("%d", &n);

	//Processing/Calculations
    while(m <= n)
    {
        sum += m;
        m++;
    }

	//Output
    printf("Sum = %d", sum);

	return 0;
}

/*
Test run 1
Enter the value of m : 7
Enter the value of n : 11
Sum = 45

Test run 2
Enter the value of m : 516
Enter the value of n : 715
Sum = 123100

Test run 3
Enter the value of m : 1
Enter the value of n : 1000
Sum = 500500

*/

