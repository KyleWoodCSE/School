/**************************************************/
/*Lab 3 Question 2                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 04/04/23                                  */
/*This Program takes user input for principal,    */
/*rate, and years and returns calculated interest */
/**************************************************/

#include<stdio.h>

float show_interest(int c_principal, float c_rate, int c_period);

int main()
{
	//Declaration
    int principal, period;
    float rate;

	//Data/input
    printf("Please input the principal amount, rate and period(in years): ");
    scanf("%d %f %d", &principal, &rate, &period);

	//Processing/Calculations + Output
    printf("The simple interest will be $%.2f", show_interest(principal, rate, period));

	return 0;
}

float show_interest(int c_principal, float c_rate, int c_period)
{
    float interest = (float)c_principal * c_rate * (float)c_period;
    return interest;
}

/*
Test run 1
Please input the principal amount, rate and period(in years): 10000 .1 1
The simple interest will be $1000.00

Test run 2
Please input the principal amount, rate and period(in years): 15619 .13 5
The simple interest will be $10152.35

Test run 3
Please input the principal amount, rate and period(in years): 709091 .055 15
The simple interest will be $585000.06

*/

