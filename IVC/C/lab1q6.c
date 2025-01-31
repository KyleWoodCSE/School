/**************************************************/
/*Lab 1 Question 6                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 02/11/23                                  */
/*This Program asks user to enter dollar amount   */
/*and shows how to pay that amount with smallest  */
/*number of $20, $10, $5, $1 bills                */
/*                                                */
/**************************************************/

#include<stdio.h>

void main()
{
	//Declaration
    int totalMoney, twentyBill, tenBill, fiveBill, oneBill;

	//Data/input
    printf("Enter a dollar amount: ");
    scanf("%d", &totalMoney);

	//Processing/Calculations
    twentyBill = totalMoney / 20;
    tenBill = (totalMoney % 20) / 10;
    fiveBill = ((totalMoney % 20) % 10) / 5;
    oneBill = ((totalMoney % 20) % 10) % 5;

	//Output
    printf("\n$20 bills: %d\n", twentyBill);
    printf("$10 bills: %d\n", tenBill);
    printf("$ 5 bills: %d\n", fiveBill);
    printf("$ 1 bills: %d\n", oneBill);

	return 0;
}

/*
Test run 1
Enter a dollar amount: 93

$20 bills: 4
$10 bills: 1
$ 5 bills: 0
$ 1 bills: 3

Test run 2
Enter a dollar amount: 70991

$20 bills: 3549
$10 bills: 1
$ 5 bills: 0
$ 1 bills: 1

Test run 3
Enter a dollar amount: 50565

$20 bills: 2528
$10 bills: 0
$ 5 bills: 1
$ 1 bills: 0
*/
