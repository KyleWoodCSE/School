/**************************************************/
/*Lab 1 Question 4                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 02/11/23                                  */
/*This Program calculates the diameter, area, and */
/*circumference of a circle from a user given     */
/*radius                                          */
/*                                                */
/**************************************************/

#include<stdio.h>

void main()
{
	//Declaration
	int num;
	float radius, diameter, area, circumference;
	const float PI = 3.14159;

	//Data/input
    printf("The radius of the circle is ");
    scanf("%d", &num);

	//Processing/Calculations
	radius = (float)num;
    diameter = 2.0 * radius;
    area = PI * (radius * radius);
    circumference = 2.0 * PI * radius;

	//Output
    printf("The diameter of the circle is %.5f\n", diameter);
    printf("The area of the circle is %.5f\n", area);
    printf("The circumference is %.5f\n", circumference);

	return 0;
}

/*
Test run 1
The radius of the circle is 5
The diameter of the circle is 10.00000
The area of the circle is 78.53975
The circumference is 31.41590

Test run 2
The radius of the circle is 15
The diameter of the circle is 30.00000
The area of the circle is 706.85779
The circumference is 94.24770

Test run 3
The radius of the circle is 9
The diameter of the circle is 18.00000
The area of the circle is 254.46880
The circumference is 56.54862
*/
