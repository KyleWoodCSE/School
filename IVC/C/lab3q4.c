/**************************************************/
/*Lab 3 Question 4                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 04/04/23                                  */
/*This Program calculates a salesperson's pay     */
/*                                                */
/**************************************************/

#include<stdio.h>

// function prototype
double get_sales();
double get_advanced_pay();
double determine_comm_rate(double c_sales);

int main()
{
	//Declaration
    double sales, advanced_pay, comm_rate, pay;

	// Call functions
    sales = get_sales();
    advanced_pay = get_advanced_pay();
    comm_rate = determine_comm_rate(sales);

	//Processing/Calculations
    pay = sales * comm_rate - advanced_pay;

	//Output
    printf("The pay is $%.2f", pay);

    if(pay<0)
    {
        printf("\nThe salesperson must reimburse the company.");
    }

	return 0;
}

double get_sales()
{
    double inputSales;
    printf("Enter the monthly sales: ");
    scanf("%lf", &inputSales);
    return inputSales;
}

double get_advanced_pay()
{
    double inputAdv;
    printf("Enter the amount of advanced pay, or enter 0 if no advanced pay was given.\n");
    printf("Advanced pay: ");
    scanf("%lf", &inputAdv);
    return inputAdv;
}

double determine_comm_rate(double c_sales)
{
    double rate;
    if (c_sales < 10000.00)
    {
        rate = 0.10;
    }
    else if (c_sales >= 10000.00 && c_sales <= 14999.99)
    {
        rate = 0.12;
    }
    else if (c_sales >= 15000.00 && c_sales <= 17999.99)
    {
        rate = 0.14;
    }
    else if (c_sales >= 18000.00 && c_sales <= 21999.99)
    {
        rate = 0.16;
    }
    else
    {
        rate = 0.18;
    }
    return rate;
}

/*
Test run 1
Enter the monthly sales: 14550.00
Enter the amount of advanced pay, or enter 0 if no advanced pay was given.
Advanced pay: 1000.00
The pay is $746.00

Test run 2
Enter the monthly sales: 9500
Enter the amount of advanced pay, or enter 0 if no advanced pay was given.
Advanced pay: 0
The pay is $950.00

Test run 3
Enter the monthly sales: 12000.00
Enter the amount of advanced pay, or enter 0 if no advanced pay was given.
Advanced pay: 2000.00
The pay is $-560.00
The salesperson must reimburse the company.

Test run 4
Enter the monthly sales: 54321.99
Enter the amount of advanced pay, or enter 0 if no advanced pay was given.
Advanced pay: 1234.00
The pay is $8543.96

Test run 5
Enter the monthly sales: 1532.00
Enter the amount of advanced pay, or enter 0 if no advanced pay was given.
Advanced pay: 59731.68
The pay is $-59578.48
The salesperson must reimburse the company.

*/

