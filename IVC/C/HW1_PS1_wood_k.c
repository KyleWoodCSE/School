/**************************************************/
/*Name: Kyle Wood                                 */
/*Student ID: 1272942                             */
/*Homework 1 Program Set 1                        */
/*Date: Jan 30, 2023                              */
/*This program takes user's initials and money &  */
/*performs calculations for total dollars & cents */
/**************************************************/

#include<stdio.h>

int main()
{
    // Declaration - declare character variables for the user initials and integer variables for the money
    char first, middle, last;
    int quarters, dimes, nickels, pennies, total, dollars, cents;

    // Input / Data - receive user's initials and coin holdings, greet user with reformatted initials
    printf("Enter your initials, first, middle, and last: ");
    scanf("%c%c%c", &first, &middle, &last);
    printf("Hello %c.%c.%c., let's see what your coins are worth.\n", first, middle, last);
    printf("Enter number of quarters: ");
    scanf("%d", &quarters);
    printf("Enter number of dimes: ");
    scanf("%d", &dimes);
    printf("Enter number of nickels: ");
    scanf("%d", &nickels);
    printf("Enter number of pennies: ");
    scanf("%d", &pennies);

    // Calculation processing - convert all coins into single cents value and calculate dollars/remaining cents from total
    total = (quarters*25) + (dimes*10) + (nickels*5) + pennies;
    dollars = total/100;
    cents = total%100;

    //Output - display coins entered by user and results of calculations
    printf("\nNumber of quarters is %d.\n", quarters);
    printf("Number of dimes is %d.\n", dimes);
    printf("Number of nickels is %d.\n", nickels);
    printf("Number of pennies is %d.\n", pennies);
    printf("Your coins are worth %d dollars and %d cents.", dollars, cents);

    return 0;
}

/*
Test Run 1 output:
Enter your initials, first, middle, and last: JTK
Hello J.T.K., let's see what your coins are worth.
Enter number of quarters: 4
Enter number of dimes: 0
Enter number of nickels: 0
Enter number of pennies: 0

Number of quarters is 4.
Number of dimes is 0.
Number of nickels is 0.
Number of pennies is 0.
Your coins are worth 1 dollars and 0 cents.

Test Run 2 output:
Enter your initials, first, middle, and last: RHT
Hello R.H.T., let's see what your coins are worth.
Enter number of quarters: 0
Enter number of dimes: 10
Enter number of nickels: 0
Enter number of pennies: 0

Number of quarters is 0.
Number of dimes is 10.
Number of nickels is 0.
Number of pennies is 0.
Your coins are worth 1 dollars and 0 cents.

Test Run 3 output:
Enter your initials, first, middle, and last: KTW
Hello K.T.W., let's see what your coins are worth.
Enter number of quarters: 8
Enter number of dimes: 9
Enter number of nickels: 7
Enter number of pennies: 4

Number of quarters is 8.
Number of dimes is 9.
Number of nickels is 7.
Number of pennies is 4.
Your coins are worth 3 dollars and 29 cents.

Test Run 4 output:
Enter your initials, first, middle, and last: CRS
Hello C.R.S., let's see what your coins are worth.
Enter number of quarters: 24
Enter number of dimes: 15
Enter number of nickels: 28
Enter number of pennies: 4

Number of quarters is 24.
Number of dimes is 15.
Number of nickels is 28.
Number of pennies is 4.
Your coins are worth 8 dollars and 94 cents.

Test Run 5 output:
Enter your initials, first, middle, and last: DSW
Hello D.S.W., let's see what your coins are worth.
Enter number of quarters: 526
Enter number of dimes: 749
Enter number of nickels: 69
Enter number of pennies: 420

Number of quarters is 526.
Number of dimes is 749.
Number of nickels is 69.
Number of pennies is 420.
Your coins are worth 214 dollars and 5 cents.
*/
