/**************************************************/
/*Lab 4 Question 2                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 05/07/23                                  */
/*This Program finds the second largest number in */
/*an array of integers                            */
/**************************************************/

#include<stdio.h>

int get_size();
void read_array(int arr[], int c_arraySize);
void display_array(int arr[], int c_arraySize);
void print_large(int arr[], int c_arraySize);

int main()
{
	// declaration/process values
    int arraySize;
    arraySize = get_size();
    int arr[arraySize];
    printf("\n");
    read_array(arr, arraySize);

    // output
    printf("\nThe numbers you entered are: ");
    display_array(arr, arraySize);
    print_large(arr, arraySize);

	return 0;
}


int get_size()
{
    int size;
    printf("Enter the desired size of the array: ");
    scanf("%d", &size);
    return size;
}


void read_array(int arr[], int c_arraySize)
{
    int num;
    for(int i = 0; i < c_arraySize; i++)
    {
        getchar();
        printf("Enter the number: ");
        scanf("%d", &num);
        arr[i] = num;
    }
}


void display_array(int arr[], int c_arraySize)
{
    for(int i = 0; i < c_arraySize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void print_large(int arr[], int c_arraySize)
{
    int large = arr[0];
    int secondLarge = arr[1];

    for(int i = 0; i < c_arraySize-1; i++)
    {
        if(large < arr[i+1])
        {
            secondLarge = large;
            large = arr[i+1];
        }
    }

    for(int i = 0; i < c_arraySize-1; i++)
    {
        if((secondLarge < arr[i+1]) && (arr[i+1] < large))
        {
            secondLarge = arr[i+1];
        }
    }

    printf("The largest of these numbers is: %d\n", large);
    printf("The second largest of these numbers is: %d\n", secondLarge);
}

/*
Test run 1
Enter the desired size of the array: 6

Enter the number: 10
Enter the number: 35
Enter the number: 60
Enter the number: 34
Enter the number: 20
Enter the number: 46

The numbers you entered are: 10 35 60 34 20 46
The largest of these numbers is: 60
The second largest of these numbers is: 46

Test run 2
Enter the desired size of the array: 5

Enter the number: 420
Enter the number: 69
Enter the number: 15
Enter the number: 32
Enter the number: 16

The numbers you entered are: 420 69 15 32 16
The largest of these numbers is: 420
The second largest of these numbers is: 69

Test run 3
Enter the desired size of the array: 8

Enter the number: 1
Enter the number: 2
Enter the number: 3
Enter the number: 4
Enter the number: 5
Enter the number: 6
Enter the number: 7
Enter the number: 8

The numbers you entered are: 1 2 3 4 5 6 7 8
The largest of these numbers is: 8
The second largest of these numbers is: 7


*/

