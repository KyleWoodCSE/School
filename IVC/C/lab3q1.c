/**************************************************/
/*Lab 3 Question 1                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 04/04/23                                  */
/*This Program creates two functions that print   */
/*two different hard coded values for "birds" int */
/**************************************************/

#include<stdio.h>

void Texas();
void California();

int main()
{
    Texas();
    California();

	return 0;
}

void Texas()
{
    int birds = 5000;
    printf("Texas has %d birds\n", birds);
}

void California()
{
    int birds = 8000;
    printf("California has %d birds\n", birds);
}

/*
Test run 1

Texas has 5000 birds
California has 8000 birds

*/

