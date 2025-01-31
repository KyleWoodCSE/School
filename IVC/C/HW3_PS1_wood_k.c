/***************************************************************************/
/*Name :  Kyle Wood                                                        */
/*Student ID :     1272942                                                 */
/*Homework 3 Program Set 1                                                 */
/*Date :   04/04/2023                                                      */
/*This program calculates salary raises for employees.                     */
/*                                                                         */
/***************************************************************************/

#include <stdio.h>

//Function prototypes
double load(char *name);
double calcRate(double c_salary);
double calcRaise(double c_salary, double c_rate);
double calcNewSalary(double c_salary, double c_raise);
void calcTotalSalaries(double c_salary, double c_raise, double c_newSalary, double *totalSalary, double *totalRaise, double *totalNewSalary);
void salaryOutput(char *name, double c_salary, double c_rate, double c_raise, double c_newSalary);
void totalOutput(double c_totalSalary, double c_totalRaise, double c_totalNewSalary);


int main()
{
    //Declaration
    int numEmployees;
    char name[20];
    double salary, rate, raise;
    double newSalary;
    double totalSalary, totalRaise, totalNewSalary;

    // ??? codes for main() see items 3a. to h. in Program Set 1 instructions
    printf("How many employees : ");
    scanf("%d", &numEmployees);
    getchar();
    for (int i = 0; i < numEmployees; i++)
    {
        if(i == 0)
        {
            totalSalary = 0.0;
            totalRaise = 0.0;
            totalNewSalary = 0.0;
        }

        salary = load(name);
        rate = calcRate(salary);
        raise = calcRaise(salary, rate);
        newSalary = calcNewSalary(salary, raise);
        calcTotalSalaries(salary, raise, newSalary, &totalSalary, &totalRaise, &totalNewSalary);
        salaryOutput(name, salary, rate, raise, newSalary);
    }

    totalOutput(totalSalary, totalRaise, totalNewSalary);

    return 0;
}


//load() let's user input the employee's name and current salary
//and return the name and salary to main()
double load(char *name)
{
    double c_salary;
    printf("\nEnter the Employee's name: ");
	gets(name);
    printf("Enter salary : ");
    scanf("%lf", &c_salary);
    getchar();
    return c_salary;
}


//calcRate() finds the rate for the salary and returns rate to main()
double calcRate(double c_salary)
{
    double c_rate;

    if (c_salary >= 0 && c_salary < 30000)
    {
        c_rate = 0.07;
    }
    else if (c_salary >= 30000 && c_salary <= 40000)
    {
        c_rate = 0.055;
    }
    else if (c_salary > 40000)
    {
        c_rate = 0.04;
    }

    return c_rate;
}


//calcRaise() calculates the raise and returns raise
double calcRaise(double c_salary, double c_rate)
{
    double c_raise;
    c_raise = c_salary * c_rate;
    return c_raise;
}


//calcNewSalary() calculates the new salary and returns the new salary
double calcNewSalary(double c_salary, double c_raise)
{
    double c_newSalary = c_salary + c_raise;
    return c_newSalary;
}


//calcTotalSalaries() calculates the total for the salary, raise, and new salary
//and pass the total salary, total raise, total new salary back to calling function
void calcTotalSalaries(double c_salary, double c_raise, double c_newSalary, double *totalSalary, double *totalRaise, double *totalNewSalary)
{
    *totalSalary += c_salary;
    *totalRaise += c_raise;
    *totalNewSalary += c_newSalary;
}


//salaryOutput() prints the name, salary, rate, raise, and new salary
void salaryOutput(char *name, double c_salary, double c_rate, double c_raise, double c_newSalary)
{
    double printRate = c_rate * 100.0;
	printf("\nEmployee's Name    :%20s\n", name);
	printf("Salary             :%20.2lf\n", c_salary);
	printf("Rate               :%19.1lf%%\n", printRate);
	printf("Raise              :%20.2lf\n", c_raise);
	printf("New Salary         :%20.2lf\n\n", c_newSalary);
}


//totalOutput() prints the total salary, total raise, and total new salary
void totalOutput(double c_totalSalary, double c_totalRaise, double c_totalNewSalary)
{
	printf("Total Salary       :%20.2lf\n", c_totalSalary);
	printf("Total Raise        :%20.2lf\n", c_totalRaise);
	printf("Total New Salary   :%20.2lf\n", c_totalNewSalary);
}

/*
Test run

How many employees : 6

Enter the Employee's name: Daisy Yellow
Enter salary : 25000.00

Employee's Name    :        Daisy Yellow
Salary             :            25000.00
Rate               :                7.0%
Raise              :             1750.00
New Salary         :            26750.00


Enter the Employee's name: Rose Red
Enter salary : 30000.00

Employee's Name    :            Rose Red
Salary             :            30000.00
Rate               :                5.5%
Raise              :             1650.00
New Salary         :            31650.00


Enter the Employee's name: Periwinkle Pink
Enter salary : 35000.00

Employee's Name    :     Periwinkle Pink
Salary             :            35000.00
Rate               :                5.5%
Raise              :             1925.00
New Salary         :            36925.00


Enter the Employee's name: Merigold Orange
Enter salary : 40000.00

Employee's Name    :     Merigold Orange
Salary             :            40000.00
Rate               :                5.5%
Raise              :             2200.00
New Salary         :            42200.00


Enter the Employee's name: Iris Blue
Enter salary : 40001.00

Employee's Name    :           Iris Blue
Salary             :            40001.00
Rate               :                4.0%
Raise              :             1600.04
New Salary         :            41601.04


Enter the Employee's name: Lilacs Purple
Enter salary : 45000.00

Employee's Name    :       Lilacs Purple
Salary             :            45000.00
Rate               :                4.0%
Raise              :             1800.00
New Salary         :            46800.00

Total Salary       :           215001.00
Total Raise        :            10925.04
Total New Salary   :           225926.04

*/
