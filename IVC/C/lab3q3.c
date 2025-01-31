/**************************************************/
/*Lab 3 Question 3                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 04/04/23                                  */
/*This Program calculates triangle area based on  */
/*user defined dimensions and displays all data   */
/**************************************************/

#include<stdio.h>

void getData(int *, int *);
float trigArea(int c_length, int c_height);
void displayData(int c_length, int c_height, float c_area);

int main()
{
    // Declaration
    int length = 0;
    int height = 0;
    float area;

    // Data/Input
    getData(&length, &height);

    // Processing/Calculations
    area = trigArea(length, height);

    // Output
    displayData(length, height, area);

	return 0;
}

void getData(int *length, int *height)
{
    printf("Length of Triangle: ");
    scanf("%d", &(*length));
    getchar();
    printf("Perpendicular Height of Triangle: ");
    scanf("%d", &(*height));
    getchar();
}

float trigArea(int c_length, int c_height)
{
    float c_area;
    c_area = 0.5 * (float)c_length * (float)c_height;
    return c_area;
}

void displayData(int c_length, int c_height, float c_area)
{
    float fLength = (float)c_length;
    float fHeight = (float)c_height;

    printf("Triangle Length = %.2f\n", fLength);
    printf("Triangle Height = %.2f\n", fHeight);
    printf("Triangle Area = %.2f\n", c_area);
}

/*
Test run 1
Length of Triangle: 5
Perpendicular Height of Triangle: 5
Triangle Length = 5.00
Triangle Height = 5.00
Triangle Area = 12.50

Test run 2
Length of Triangle: 10
Perpendicular Height of Triangle: 8
Triangle Length = 10.00
Triangle Height = 8.00
Triangle Area = 40.00

Test run 3
Length of Triangle: 15
Perpendicular Height of Triangle: 29
Triangle Length = 15.00
Triangle Height = 29.00
Triangle Area = 217.50

*/

