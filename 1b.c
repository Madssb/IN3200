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

/**
 * @brief Finds the largest element within a provided 1D array.
 * @param array Pointer to one-dimensional array, consisting of (unsigned) integers. In current implementation, function is not tested to handle signed integers.
 * @param array_size Amount of elements contained within provided array.
 * @return The largest integer found within provided array. 
 */
double find_max_array_element(double *array, size_t array_size)
{
    double largest_element = 0.;
    for(size_t index = 0; index < array_size; index++)
    {
        if (array[index] > largest_element)
        {
            largest_element = array[index];
        }
    }
    return largest_element;
}

double find_min_array_element(double *array, size_t array_size)
{
    double smallest_element = (double)INT_MAX;
    for(size_t index = 0; index < array_size; index++)
    {
        if (array[index] < smallest_element)
        {
            smallest_element = array[index];
        }
    }
    return smallest_element;
}

double double_pseudo_rng()
{
    double rand_double = (double)rand()/(double)RAND_MAX;
    if(rand() & 1)
    {
        rand_double *= -1;
    }
    rand_double *= rand();
    return rand_double;
}
double * initialize_array_random_elements(size_t array_size)
{
    srand((unsigned int)time(NULL)); // seed the random number generator to known value
    //int array[array_size];
    double *array;
    array = malloc(array_size * sizeof(double));
    for(size_t index= 0; index<array_size; index++)
    {
        array[index] = double_pseudo_rng();
    }
    return array;
}

void print_array_contents(double *array,size_t array_size)
{
    for (size_t index = 0; index < array_size; index++)
    {
        printf("%f ", array[index]);
    }
    printf("\n");
}


int main()
{
    int array_size_input;
    printf("Define the size of the array (unsigned integer required):");
    if((scanf("%d",&array_size_input) ==1) && (array_size_input > 0))
    {
        printf("Succesful input!\n");
    }
    else
    {
        printf("Unsuccesful input! You provided: %d\n",array_size_input);
        return 0;
    }
    size_t array_size = (size_t)array_size_input;
    double *array = initialize_array_random_elements(array_size);
    print_array_contents(array,array_size);
    double max_element = find_max_array_element(array,array_size);
    double min_element = find_min_array_element(array,array_size);
    printf("max element: %f, min element: %f. \n",max_element,min_element);
    return 0;
}