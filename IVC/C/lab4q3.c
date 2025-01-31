/**************************************************/
/*Lab 4 Question 3                                */
/*Name : Kyle Wood                                */
/*Student ID : 1272942                            */
/*Date: 05/07/23                                  */
/*This Program finds duplicates in an integer     */
/*array                                           */
/**************************************************/

#include<stdio.h>

int get_size();
void read_array(int arr[], int c_arraySize);
void display_array(int arr[], int c_arraySize);
void find_duplicate(int arr[], int c_arraySize);

int main()
{
	// declaration/process values
    int arraySize;
    arraySize = get_size();
    int arr[arraySize];
    read_array(arr, arraySize);

    // output
    display_array(arr, arraySize);
    find_duplicate(arr, arraySize);

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
        scanf("%d", &num);
        arr[i] = num;
    }
}


void display_array(int arr[], int c_arraySize)
{
    printf("\nThe numbers you entered are: ");
    for(int i = 0; i < c_arraySize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void find_duplicate(int arr[], int c_arraySize)
{
    int duplicate = 0;
    int indexFirst = 0;
    int indexSecond = 0;

    for(int i = 0; i < c_arraySize; i++)
    {
        for(int j = 0; j < c_arraySize; j++)
        {
            if((arr[i] == arr[j]) && (i != j))
            {
                duplicate = arr[i];
                indexFirst = j;
                indexSecond = i;
            }
        }
    }

    printf("Duplicate number %d found at location %d and %d\n", duplicate, indexFirst, indexSecond);
}

/*
Test run 1
Enter the desired size of the array: 6
1
2
3
3
4
5

The numbers you entered are: 1 2 3 3 4 5
Duplicate number 3 found at location 2 and 3

Test run 2
Enter the desired size of the array: 5
0
5
0
6
3

The numbers you entered are: 0 5 0 6 3
Duplicate number 0 found at location 0 and 2

Test run 3
Enter the desired size of the array: 8
9
8
7
15
5
4
3
15

The numbers you entered are: 9 8 7 15 5 4 3 15
Duplicate number 15 found at location 3 and 7


*/

