/**************************************************/
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Homework 2 Program Set 1                        */
/*Date: 03/11/23                                  */
/*This Program allows user to select filing status*/
/*through a menu, takes income and calculates tax */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int menuChoice, userIncome;
    float taxesOwed = 0.0;
    const float lowRate = 0.15;
    const float medLowRate = 0.28;
    const float medRate = 0.31;
    const float medHighRate = 0.36;
    const float highRate = 0.396;

	//Data/input
    printf("************Menu****************\n");
    printf("1) Single\n");
    printf("2) Married Filing Jointly\n");
    printf("3) Married Filing Separately\n");
    printf("4) Head of Household\n");
    printf("5) Exit\n\n");
    printf("********************************\n\n");
    printf("Enter status: ");
    scanf("%d", &menuChoice);

	//Processing/Calculations + Output
    switch(menuChoice)
    {
        case 1:
            printf("Enter your taxable TI: $");
            scanf("%d", &userIncome);
            if(userIncome > 0 && userIncome <= 24000)
            {
                taxesOwed = lowRate * (float)userIncome;
            }
            else if(userIncome > 24000 && userIncome <= 58000)
            {
                taxesOwed = (medLowRate * ((float)userIncome - 24000)) + 3600.00;
            }
            else if(userIncome > 58000 && userIncome <= 121300)
            {
                taxesOwed = (medRate * ((float)userIncome - 58000)) + 13162.00;
            }
            else if(userIncome > 121300 && userIncome <= 263750)
            {
                taxesOwed = (medHighRate * ((float)userIncome - 121300)) + 32738.50;
            }
            else if(userIncome > 263750)
            {
                taxesOwed = (highRate * ((float)userIncome - 263750)) + 84020.50;
            }
            printf("The taxes owed are: $%.2f", taxesOwed);
            break;
        case 2:
            printf("Enter your taxable TI: $");
            scanf("%d", &userIncome);
            if(userIncome > 0 && userIncome <= 40100)
            {
                taxesOwed = lowRate * (float)userIncome;
            }
            else if(userIncome > 40100 && userIncome <= 96900)
            {
                taxesOwed = (medLowRate * ((float)userIncome - 40100)) + 6015.00;
            }
            else if(userIncome > 96900 && userIncome <= 147700)
            {
                taxesOwed = (medRate * ((float)userIncome - 96900)) + 21919.00;
            }
            else if(userIncome > 147700 && userIncome <= 263750)
            {
                taxesOwed = (medHighRate * ((float)userIncome - 147700)) + 37667.00;
            }
            else if(userIncome > 263750)
            {
                taxesOwed = (highRate * ((float)userIncome - 263750)) + 79445.00;
            }
            printf("The taxes owed are: $%.2f", taxesOwed);
            break;
        case 3:
            printf("Enter your taxable TI: $");
            scanf("%d", &userIncome);
            if(userIncome > 0 && userIncome <= 20050)
            {
                taxesOwed = lowRate * (float)userIncome;
            }
            else if(userIncome > 20050 && userIncome <= 48450)
            {
                taxesOwed = (medLowRate * ((float)userIncome - 20050)) + 3007.50;
            }
            else if(userIncome > 48450 && userIncome <= 73850)
            {
                taxesOwed = (medRate * ((float)userIncome - 48450)) + 10959.50;
            }
            else if(userIncome > 73850 && userIncome <= 131875)
            {
                taxesOwed = (medHighRate * ((float)userIncome - 73850)) + 18833.50;
            }
            else if(userIncome > 131875)
            {
                taxesOwed = (highRate * ((float)userIncome - 131875)) + 39722.50;
            }
            printf("The taxes owed are: $%.2f", taxesOwed);
            break;
        case 4:
            printf("Enter your taxable TI: $");
            scanf("%d", &userIncome);
            if(userIncome > 0 && userIncome <= 32150)
            {
                taxesOwed = lowRate * (float)userIncome;
            }
            else if(userIncome > 32150 && userIncome <= 83050)
            {
                taxesOwed = (medLowRate * ((float)userIncome - 32150)) + 4822.50;
            }
            else if(userIncome > 83050 && userIncome <= 134500)
            {
                taxesOwed = (medRate * ((float)userIncome - 83050)) + 19074.50;
            }
            else if(userIncome > 134500 && userIncome <= 263750)
            {
                taxesOwed = (medHighRate * ((float)userIncome - 134500)) + 35074.00;
            }
            else if(userIncome > 263750)
            {
                taxesOwed = (highRate * ((float)userIncome - 263750)) + 81554.00;
            }
            printf("The taxes owed are: $%.2f", taxesOwed);
            break;
        case 5:
            printf("Exit program...");
            break;
        default:
            printf("You entered a wrong status. Program Exit . . .");
    }

	return 0;
}

/*
Test run 1
************Menu****************
1) Single
2) Married Filing Jointly
3) Married Filing Separately
4) Head of Household
5) Exit

********************************

Enter status: 1
Enter your taxable TI: $50000
The taxes owed are: $10880.00

Test run 2
************Menu****************
1) Single
2) Married Filing Jointly
3) Married Filing Separately
4) Head of Household
5) Exit

********************************

Enter status: 5
Exit program...

Test run 3
************Menu****************
1) Single
2) Married Filing Jointly
3) Married Filing Separately
4) Head of Household
5) Exit

********************************

Enter status: a
You entered a wrong status. Program Exit . . .

Test run 4
************Menu****************
1) Single
2) Married Filing Jointly
3) Married Filing Separately
4) Head of Household
5) Exit

********************************

Enter status: 7
You entered a wrong status. Program Exit . . .

Test run 5
************Menu****************
1) Single
2) Married Filing Jointly
3) Married Filing Separately
4) Head of Household
5) Exit

********************************

Enter status: 2
Enter your taxable TI: $123456
The taxes owed are: $30151.36

Test run 6
************Menu****************
1) Single
2) Married Filing Jointly
3) Married Filing Separately
4) Head of Household
5) Exit

********************************

Enter status: 3
Enter your taxable TI: $76543
The taxes owed are: $19802.98

Test run 7
************Menu****************
1) Single
2) Married Filing Jointly
3) Married Filing Separately
4) Head of Household
5) Exit

********************************

Enter status: 4
Enter your taxable TI: $543210
The taxes owed are: $192220.16
*/
