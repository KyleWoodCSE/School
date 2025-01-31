/**************************************************/
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Homework 2 Program Set 3                        */
/*Date: 03/11/23                                  */
/*This Program computes salary raises for user    */
/*input salaries, set iteration by user first     */
/*print totals                                    */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int i, iterations, input;
    float sal, rate, raise, newSal, totSal, totRaise, totNewSal;
    totSal = totRaise = totNewSal = 0.0;

	//Data/input
	printf("How many salaries do you want to enter? ");
	scanf("%d", &iterations);
    printf("\n                      Salary         Rate    Raise     New Salary\n");
    printf("-----------------------------------------------------------------\n");

	//Processing/Calculations + Output
    for(i = 0; i < iterations; i++)
    {
        printf("Salary : ");
        scanf("%d", &input);
        if(input > 0 && input < 30000)
        {
            sal = (float)input;
            rate = 7.00;
            raise = sal * 0.07;
            newSal = sal * 1.07;
        }
        else if(input >= 30000 && input <= 40000)
        {
            sal = (float)input;
            rate = 5.50;
            raise = sal * 0.055;
            newSal = sal * 1.055;
        }
        else if(input > 40000)
        {
            sal = (float)input;
            rate = 4.00;
            raise = sal * 0.04;
            newSal = sal * 1.04;
        }
        printf("                    %10.2f %10.2f %10.2f %10.2f\n", sal, rate, raise, newSal);
        totSal += sal;
        totRaise += raise;
        totNewSal += newSal;
    }

	//Final Output
    printf("-----------------------------------------------------------------\n");
    printf("Total               %10.2f            %10.2f %10.2f\n", totSal, totRaise, totNewSal);

	return 0;
}

/*
Test run 1
How many salaries do you want to enter? 4

                      Salary         Rate    Raise     New Salary
-----------------------------------------------------------------
Salary : 25000
                      25000.00       7.00    1750.00   26750.00
Salary : 30000
                      30000.00       5.50    1650.00   31650.00
Salary : 35000
                      35000.00       5.50    1925.00   36925.00
Salary : 40000
                      40000.00       5.50    2200.00   42200.00
-----------------------------------------------------------------
Total                130000.00               7525.00  137525.00

Test run 2
How many salaries do you want to enter? 5

                      Salary         Rate    Raise     New Salary
-----------------------------------------------------------------
Salary : 1515
                       1515.00       7.00     106.05    1621.05
Salary : 10987
                      10987.00       7.00     769.09   11756.09
Salary : 32100
                      32100.00       5.50    1765.50   33865.50
Salary : 43210
                      43210.00       4.00    1728.40   44938.40
Salary : 54321
                      54321.00       4.00    2172.84   56493.84
-----------------------------------------------------------------
Total                142133.00               6541.88  148674.88

Test run 3
How many salaries do you want to enter? 5

                      Salary         Rate    Raise     New Salary
-----------------------------------------------------------------
Salary : 123
                        123.00       7.00       8.61     131.61
Salary : 456789
                     456789.00       4.00   18271.56  475060.56
Salary : 37910
                      37910.00       5.50    2085.05   39995.05
Salary : 19735
                      19735.00       7.00    1381.45   21116.45
Salary : 15
                         15.00       7.00       1.05      16.05
-----------------------------------------------------------------
Total                514572.00              21747.72  536319.75

*/
