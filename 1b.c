#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> //INFINITY lives here
/*
 * Author: Mads S. Balto
 * Date: 04/02/23
 * Description:
 * this script initializes a 1D array, with a length specified at runtime with pseudo-random integers randing from 0 to 100. It evaluates this array,
 * finding the largest, and the smallest elements respectively. 
 */

/**
 * @brief Finds the largest element within a provided one-dimensional array.
 * 
 * @param array Pointer to one-dimensional array consisting of floats.
 * @param array_size Amount of floats contained within provided array. If array_size exceeds actual array size, non-allocated memory will be attempted accessed. If provided array size falls short of actual array size, the largest element may not be found. 
 * @return Largest float found within provided array. if empty array is provided, returns negative infinity.
 */
double find_max_array_element(double *array, size_t array_size)
{
    double largest_element = -INFINITY;
    for(size_t index = 0; index < array_size; index++)
    {
        if (array[index] > largest_element)
        {
            largest_element = array[index];
        }
    }
    return largest_element;
}
/**
 * @brief Finds the smallest element within a provided one-dimensional array.
 * 
 * @param array Pointer to one-dimensional array consisting of floats.
 * @param array_size Amount of floating point values contained within provided array. If array_size exceeds actual array size, non-allocated memory will be attempted accessed. If array_size falls short of actual array size, the smallest element may not be found. 
 * @return Smallest float foudn within provided array. If empty array is provided, returns infinity
 */
double find_min_array_element(double *array, size_t array_size)
{
    double smallest_element = INFINITY;
    for(size_t index = 0; index < array_size; index++)
    {
        if (array[index] < smallest_element)    
        {
            smallest_element = array[index];
        }
    }
    return smallest_element;
}
/**
 * @brief generates a pseudo-random double, based on calls to a pseudo RNG method for integers. 
 * 
 * @return double of pseudo-random nature. May not be uniformly distributed. 
 */
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
/**
 * @brief Initializes one-dimensional array of fixed length with pseudo-random-like doubles.
 * 
 * @param array_size Amount of floating point values contained within provided array.
 * @return Pointer to array consisting of pseudo-random-like doubles.
 */
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
/**
 * @brief prints the elements of a provided one-dimensional array to the terminal. 
 * 
 * @param array Pointer to one-dimensional array with double elements.
 * @param array_size expected amount of elements stored in array. if array_size exceeds actual array size, dereferences an invalid pointer. If array_size falls short of actual array size, function does not print all elements of array.
 */
void print_array_contents(double *array,size_t array_size)
{
    for (size_t index = 0; index < array_size; index++)
    {
        printf("%f\n", array[index]);
    }
    printf("\n");
}
/**
 * @brief requires user to specify a positive integer at runtime, and returns specified value if it is positive.
 * 
 * @return size_t quantity. if input is string, or a float, undefined behavior may occur.
 */
size_t pick_positive_number()
{
    int array_size_input;
    printf("Define the size of the array (unsigned integer required):");
    if((scanf("%d",&array_size_input) ==1) && (array_size_input > 0))
    {
        printf("Succesful input! input will be converted to unsigned integeger: %zu\n",(size_t)array_size_input);
        return (size_t)array_size_input;
    }
    else
    {
        printf("Unsuccesful input! You provided: %d, which is negative.\n",array_size_input);
        exit(1);
    }
}

int main()
{
    size_t array_size = pick_positive_number();
    double *array = initialize_array_random_elements(array_size);
    print_array_contents(array,array_size);
    double max_element = find_max_array_element(array,array_size);
    double min_element = find_min_array_element(array,array_size);
    printf("max element: %f, min element: %f. \n",max_element,min_element);
    free(array);
    return 0;
}