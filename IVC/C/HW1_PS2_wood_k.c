/**************************************************/
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Homework 1 Program Set 2                        */
/*Date: 02/11/23                                  */
/*This Program takes company info and stock prices*/
/*from user and calculates costs/profits          */
/*                                                */
/**************************************************/

#include<stdio.h>

void main()
{
	//Declaration
    char company[12];
    int shares;
    float buyPrice, currentPrice, fees, initialCost, currentCost, firstProfit, secondProfit, thirdProfit, fourthProfit, fifthProfit, totalProfit;

	//Data/input
	printf("*********************************\n");
	printf("             Stock 1             \n");
	printf("*********************************\n");
    printf("Enter stock name ");
    gets(company);
    printf("Enter number of shares ");
    scanf("%d", &shares);
    printf("Enter the buy price, current price, fees ");
    scanf("%f %f %f", &buyPrice, &currentPrice, &fees);

	//Processing/Calculations
    initialCost = shares * buyPrice;
    currentCost = shares * currentPrice;
    firstProfit = currentCost - initialCost - fees;

	//Output
    printf("\nThe Stock name is    : %s\n", company);
    printf("The number of shares : %11d\n", shares);
    printf("The buy price is     : $%10.2f\n%", buyPrice);
    printf("The current price is : $%10.2f\n%", currentPrice);
    printf("The fees are         : $%10.2f\n%", fees);
    printf("\nThe initial cost is  : $%10.2f\n", initialCost);
    printf("The current cost is  : $%10.2f\n", currentCost);
    printf("The profit is        : $%10.2f\n", firstProfit);

    //Data/input
    getchar();
	printf("\n*********************************\n");
	printf("             Stock 2             \n");
	printf("*********************************\n");
    printf("Enter stock name ");
    gets(company);
    printf("Enter number of shares ");
    scanf("%d", &shares);
    printf("Enter the buy price, current price, fees ");
    scanf("%f %f %f", &buyPrice, &currentPrice, &fees);

	//Processing/Calculations
    initialCost = shares * buyPrice;
    currentCost = shares * currentPrice;
    secondProfit = currentCost - initialCost - fees;

	//Output
    printf("\nThe Stock name is    : %s\n", company);
    printf("The number of shares : %11d\n", shares);
    printf("The buy price is     : $%10.2f\n%", buyPrice);
    printf("The current price is : $%10.2f\n%", currentPrice);
    printf("The fees are         : $%10.2f\n%", fees);
    printf("\nThe initial cost is  : $%10.2f\n", initialCost);
    printf("The current cost is  : $%10.2f\n", currentCost);
    printf("The profit is        : $%10.2f\n", secondProfit);

    //Data/input
    getchar();
	printf("\n*********************************\n");
	printf("             Stock 3             \n");
	printf("*********************************\n");
    printf("Enter stock name ");
    gets(company);
    printf("Enter number of shares ");
    scanf("%d", &shares);
    printf("Enter the buy price, current price, fees ");
    scanf("%f %f %f", &buyPrice, &currentPrice, &fees);

	//Processing/Calculations
    initialCost = shares * buyPrice;
    currentCost = shares * currentPrice;
    thirdProfit = currentCost - initialCost - fees;

	//Output
    printf("\nThe Stock name is    : %s\n", company);
    printf("The number of shares : %11d\n", shares);
    printf("The buy price is     : $%10.2f\n%", buyPrice);
    printf("The current price is : $%10.2f\n%", currentPrice);
    printf("The fees are         : $%10.2f\n%", fees);
    printf("\nThe initial cost is  : $%10.2f\n", initialCost);
    printf("The current cost is  : $%10.2f\n", currentCost);
    printf("The profit is        : $%10.2f\n", thirdProfit);

    //Data/input
    getchar();
	printf("\n*********************************\n");
	printf("             Stock 4             \n");
	printf("*********************************\n");
    printf("Enter stock name ");
    gets(company);
    printf("Enter number of shares ");
    scanf("%d", &shares);
    printf("Enter the buy price, current price, fees ");
    scanf("%f %f %f", &buyPrice, &currentPrice, &fees);

	//Processing/Calculations
    initialCost = shares * buyPrice;
    currentCost = shares * currentPrice;
    fourthProfit = currentCost - initialCost - fees;

	//Output
    printf("\nThe Stock name is    : %s\n", company);
    printf("The number of shares : %11d\n", shares);
    printf("The buy price is     : $%10.2f\n%", buyPrice);
    printf("The current price is : $%10.2f\n%", currentPrice);
    printf("The fees are         : $%10.2f\n%", fees);
    printf("\nThe initial cost is  : $%10.2f\n", initialCost);
    printf("The current cost is  : $%10.2f\n", currentCost);
    printf("The profit is        : $%10.2f\n", fourthProfit);

    //Data/input
    getchar();
	printf("\n*********************************\n");
	printf("             Stock 5             \n");
	printf("*********************************\n");
    printf("Enter stock name ");
    gets(company);
    printf("Enter number of shares ");
    scanf("%d", &shares);
    printf("Enter the buy price, current price, fees ");
    scanf("%f %f %f", &buyPrice, &currentPrice, &fees);

	//Processing/Calculations
    initialCost = shares * buyPrice;
    currentCost = shares * currentPrice;
    fifthProfit = currentCost - initialCost - fees;
    totalProfit = firstProfit + secondProfit + thirdProfit + fourthProfit + fifthProfit;

	//Output
    printf("\nThe Stock name is    : %s\n", company);
    printf("The number of shares : %11d\n", shares);
    printf("The buy price is     : $%10.2f\n%", buyPrice);
    printf("The current price is : $%10.2f\n%", currentPrice);
    printf("The fees are         : $%10.2f\n%", fees);
    printf("\nThe initial cost is  : $%10.2f\n", initialCost);
    printf("The current cost is  : $%10.2f\n", currentCost);
    printf("The profit is        : $%10.2f\n", fifthProfit);
    printf("\nThe total profit for the 5 stocks is : $%10.2f", totalProfit);

    return 0;
}

//Test run 1
/*
*********************************
             Stock 1
*********************************
Enter stock name IBM CORP
Enter number of shares 155
Enter the buy price, current price, fees 15.33 13.33 5.00

The Stock name is    : IBM CORP
The number of shares :         155
The buy price is     : $     15.33
The current price is : $     13.33
The fees are         : $      5.00

The initial cost is  : $   2376.15
The current cost is  : $   2066.15
The profit is        : $   -315.00

*********************************
             Stock 2
*********************************
Enter stock name ORACLE SYS
Enter number of shares 375
Enter the buy price, current price, fees 11.77 12.25 3.50

The Stock name is    : ORACLE SYS
The number of shares :         375
The buy price is     : $     11.77
The current price is : $     12.25
The fees are         : $      3.50

The initial cost is  : $   4413.75
The current cost is  : $   4593.75
The profit is        : $    176.50

*********************************
             Stock 3
*********************************
Enter stock name SUN MICRO
Enter number of shares 350
Enter the buy price, current price, fees 27.55 35.75 12.25

The Stock name is    : SUN MICRO
The number of shares :         350
The buy price is     : $     27.55
The current price is : $     35.75
The fees are         : $     12.25

The initial cost is  : $   9642.50
The current cost is  : $  12512.50
The profit is        : $   2857.75

*********************************
             Stock 4
*********************************
Enter stock name LINKSYS INC
Enter number of shares 85
Enter the buy price, current price, fees 25.35 23.34 6.00

The Stock name is    : LINKSYS INC
The number of shares :          85
The buy price is     : $     25.35
The current price is : $     23.34
The fees are         : $      6.00

The initial cost is  : $   2154.75
The current cost is  : $   1983.90
The profit is        : $   -176.85

*********************************
             Stock 5
*********************************
Enter stock name CISCO INC
Enter number of shares 50
Enter the buy price, current price, fees 45.36 50.86 1.50

The Stock name is    : CISCO INC
The number of shares :          50
The buy price is     : $     45.36
The current price is : $     50.86
The fees are         : $      1.50

The initial cost is  : $   2268.00
The current cost is  : $   2543.00
The profit is        : $    273.50

The total profit for the 5 stocks is : $   2815.90
*/
