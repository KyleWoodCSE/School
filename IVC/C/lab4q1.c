/**************************************************/
/*Lab 4 Question 1                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 05/06/23                                  */
/*This Program interchanges the largest and       */
/*smallest number in an array                     */
/**************************************************/

#include<stdio.h>

int get_size();
void read_array(int arr[], int c_arraySize);
void display_array(int arr[], int c_arraySize);
void swap_numbers(int arr[], int c_arraySize);

int main()
{
    // declaration/process values
    int arraySize;
    arraySize = get_size();
    int arr[arraySize];
    read_array(arr, arraySize);

    // output first iteration
    printf("\nThe elements of the array are:\n");
    display_array(arr, arraySize);

    // swap large and small and display new array
    swap_numbers(arr, arraySize);
    printf("\nThe elements of the array after the interchange are:\n");
    display_array(arr, arraySize);

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
        printf("Enter a number for position %d: ", i);
        scanf("%d", &num);
        arr[i] = num;
    }
}


void display_array(int arr[], int c_arraySize)
{
    for(int i = 0; i < c_arraySize; i++)
    {
        printf("arr[%d]=%d ", i, arr[i]);
    }
    printf("\n");
}


void swap_numbers(int arr[], int c_arraySize)
{
    int small = arr[0];
    int smallIndex = 0;
    int big = arr[0];
    int bigIndex = 0;

    for(int i = 0; i < c_arraySize-1; i++)
    {
        if(small > arr[i+1])
        {
            small = arr[i+1];
            smallIndex = i+1;
        }
        if(big < arr[i+1])
        {
            big = arr[i+1];
            bigIndex = i+1;
        }
    }

    arr[bigIndex] = small;
    arr[smallIndex] = big;
}

/*
Test run 1
Enter the desired size of the array: 5
Enter a number for position 0: 3
Enter a number for position 1: 6
Enter a number for position 2: 3
Enter a number for position 3: 7
Enter a number for position 4: 9

The elements of the array are:
arr[0]=3 arr[1]=6 arr[2]=3 arr[3]=7 arr[4]=9

The elements of the array after the interchange are:
arr[0]=9 arr[1]=6 arr[2]=3 arr[3]=7 arr[4]=3


Test run 2
Enter the desired size of the array: 6
Enter a number for position 0: 15
Enter a number for position 1: 2
Enter a number for position 2: 13
Enter a number for position 3: 4
Enter a number for position 4: 8
Enter a number for position 5: 1

The elements of the array are:
arr[0]=15 arr[1]=2 arr[2]=13 arr[3]=4 arr[4]=8 arr[5]=1

The elements of the array after the interchange are:
arr[0]=1 arr[1]=2 arr[2]=13 arr[3]=4 arr[4]=8 arr[5]=15

Test run 3
Enter the desired size of the array: 8
Enter a number for position 0: 156
Enter a number for position 1: 2
Enter a number for position 2: 55
Enter a number for position 3: 796
Enter a number for position 4: 1
Enter a number for position 5: 58
Enter a number for position 6: 0
Enter a number for position 7: 10

The elements of the array are:
arr[0]=156 arr[1]=2 arr[2]=55 arr[3]=796 arr[4]=1 arr[5]=58 arr[6]=0 arr[7]=10

The elements of the array after the interchange are:
arr[0]=156 arr[1]=2 arr[2]=55 arr[3]=0 arr[4]=1 arr[5]=58 arr[6]=796 arr[7]=10



*/

