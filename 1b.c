#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h> //INT_MAX lives here

/*
 * Author: Mads S. Balto
 * Date: 04/02/23
 * Description:
 * this script initializes a 1D array, with a length specified at runtime with pseudo-random integers randing from 0 to 100. It evaluates this array,
 * finding the largest, and the smallest elements respectively. 
 */


int find_max_array_element(int *array, int array_size)
{
    int largest_element = 0;
    for(int index = 0; index < array_size; index++)
    {
        if (array[index] > largest_element)
        {
            largest_element = array[index];
        }
    }
    return largest_element;
}


int find_min_array_element(int *array, int array_size)
{
    int smallest_element = INT_MAX;
    for(int index = 0; index < array_size; index++)
    {
        if (array[index] < smallest_element)
        {
            smallest_element = array[index];
        }
    }
    return smallest_element;
}


int * initialize_array_random_elements(int array_size)
{
    srand(time(NULL)); // seed the random number generator to known value
    //int array[array_size];
    int *array;
    array = malloc(array_size * sizeof(int));
    int bytesize_array = sizeof(array);
    printf("size of array: %d\n",bytesize_array);
    for(int index= 0; index<array_size; index++)
    {
        array[index] = rand() % 100;
    }
    return array;
}


void print_array_contents(int *array,int array_size)
{
    for (int index = 0; index < array_size; index++)
    {
        printf("%d ", array[index]);
    }
    printf("\n");
}


int main()
{
    srand(time(NULL)); // seed the random number generator to known value
    int array_size;
    printf("Define the size of the array:");
    scanf("%d",&array_size);
    int *array = initialize_array_random_elements(array_size);
    print_array_contents(array,array_size);
    int max_element = find_max_array_element(array,array_size);
    int min_element = find_min_array_element(array,array_size);
    printf("max element: %d, min element: %d. \n",max_element,min_element);
    return 0;
}