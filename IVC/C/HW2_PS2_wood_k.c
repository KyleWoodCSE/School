/**************************************************/
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Homework 2 Program Set 2                        */
/*Date: 03/11/23                                  */
/*This Program computes salary raises for user    */
/*input salaries, terminate at -1, print totals   */
/**************************************************/

#include<stdio.h>

int main()
{
	//Declaration
    int input;
    float sal, rate, raise, newSal, totSal, totRaise, totNewSal;
    totSal = totRaise = totNewSal = 0.0;

	//Data/input
    printf("                      Salary         Rate    Raise     New Salary\n");
    printf("-----------------------------------------------------------------\n");
    printf("Salary : ");
    scanf("%d", &input);

	//Processing/Calculations + Output
    while(input != -1)
    {
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
        printf("Salary : ");
        scanf("%d", &input);
    }

	//Final Output
    printf("-----------------------------------------------------------------\n");
    printf("Total               %10.2f            %10.2f %10.2f\n", totSal, totRaise, totNewSal);

	return 0;
}

/*
Test run 1
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
Salary : -1
-----------------------------------------------------------------
Total                130000.00               7525.00  137525.00

Test run 2
                      Salary         Rate    Raise     New Salary
-----------------------------------------------------------------
Salary : -1
-----------------------------------------------------------------
Total                     0.00                  0.00       0.00

Test run 3
                      Salary         Rate    Raise     New Salary
-----------------------------------------------------------------
Salary : 15
                         15.00       7.00       1.05      16.05
Salary : 30001
                      30001.00       5.50    1650.06   31651.05
Salary : 151515
                     151515.00       4.00    6060.60  157575.59
Salary : -1
-----------------------------------------------------------------
Total                181531.00               7711.71  189242.70

Test run 4
                      Salary         Rate    Raise     New Salary
-----------------------------------------------------------------
Salary : 5000
                       5000.00       7.00     350.00    5350.00
Salary : 32100
                      32100.00       5.50    1765.50   33865.50
Salary : 43210
                      43210.00       4.00    1728.40   44938.40
Salary : 12345
                      12345.00       7.00     864.15   13209.15
Salary : 34567
                      34567.00       5.50    1901.19   36468.18
Salary : 45678
                      45678.00       4.00    1827.12   47505.12
Salary : -1
-----------------------------------------------------------------
Total                172900.00               8436.35  181336.36

Test run 5
                      Salary         Rate    Raise     New Salary
-----------------------------------------------------------------
Salary : 500500
                     500500.00       4.00   20020.00  520520.00
Salary : 1973
                       1973.00       7.00     138.11    2111.11
Salary : 51628
                      51628.00       4.00    2065.12   53693.12
Salary : 36791
                      36791.00       5.50    2023.51   38814.50
Salary : 258963
                     258963.00       4.00   10358.52  269321.53
Salary : 741258
                     741258.00       4.00   29650.32  770908.31
Salary : -1
-----------------------------------------------------------------
Total               1591113.00              64255.58 1655368.50
*/
