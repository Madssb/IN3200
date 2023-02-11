#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char **allocate_str_array(size_t n_elements)
{
    char **time_array;
    time_array = malloc(n_elements * sizeof(char *));
    for (size_t index = 0; index < n_elements; index++)
    {
        time_array[index] = malloc(6 * sizeof(char));
    }
    return time_array;
}
/**
 * @brief deallocates memory currently occupied by a two-dimensional array of chars, i.e. array of strings.
 *
 * @param matrix two-dimensional char array to be deallocated.
 * @param rows amount of char arrays, i.e. amount of strings.
 */
void deallocate_str_array(char **matrix, size_t rows)
{
    for (size_t row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}
/**
 * @brief Finds the largest element within a provided one-dimensional array.
 *
 * @param array Pointer to one-dimensional array consisting of doubles.
 * @param array_size Number of doubles contained within provided array.
 * If array_size exceeds actual array size, non-allocated memory will be attempted to be accessed.
 * If provided array size falls short of actual array size, the largest element may not be found.
 * @return Largest double found within provided array. if empty array is provided, returns negative infinity.
 */
size_t find_max_array_element(double *array, size_t array_size)
{
    double largest_element = -INFINITY;
    size_t index_of_largest_element;
    for (size_t index = 0; index < array_size; index++)
    {
        if (array[index] > largest_element)
        {
            largest_element = array[index];
            index_of_largest_element = index;
        }
    }
    return index_of_largest_element;
}
/**
 * @brief Finds the smallest element within a provided one-dimensional array.
 *
 * @param array Pointer to one-dimensional array consisting of doubles.
 * @param array_size Number of doubles contained within provided array.
 * If array_size exceeds actual array size, non-allocated memory will be attempted accessed.
 * If array_size falls short of actual array size, the smallest element may not be found.
 * @return Smallest double foudn within provided array. If empty array is provided, returns infinity
 */
size_t find_min_array_element(double *array, size_t array_size)
{
    double smallest_element = INFINITY;
    size_t index_of_smallest_element;
    for (size_t index = 0; index < array_size; index++)
    {
        if (array[index] < smallest_element)
        {
            smallest_element = array[index];
            index_of_smallest_element = index;
        }
    }
    return index_of_smallest_element;
}
double compute_standard_deviation(double *array, size_t array_size)
{
    double elements_sum = 0;
    for(size_t index = 0; index<array_size; index++)
    {
        elements_sum += array[index];
    }
    double expected_value = elements_sum/(double)array_size;
    double second_sum = 0;
    for(size_t index = 0; index<array_size; index++)
    {

        second_sum += (array[index] - expected_value)*(array[index] - expected_value);
    }
    double standard_deviation = sqrt(second_sum/(double)array_size);
    return standard_deviation;
}

    int main()
{
    FILE *file;
    int err;
    file = fopen("temperature.txt", "r");
    if (file == NULL)
    {
        printf("Error opening a file\n");
        return 1;
    }
    size_t lines;
    err = fscanf(file, "%zu", &lines);
    if (err != 1)
    {
        printf("Error with fscanf()\n");
        return 1;
    }
    // printf("amount of lines: %zu\n", lines);
    char **time_array = allocate_str_array(lines);
    double *temperatures;
    temperatures = malloc(lines * sizeof(double));
    for (size_t index = 0; index < lines; index++)
    {
        err = fscanf(file, "%5s %lf", time_array[index], &temperatures[index]);
        // printf("time: %5s, temperature: %f\n", time_array[index], temperatures[index]);
    }
    size_t index_largest_temp = find_max_array_element(temperatures, lines);
    size_t index_smallest_temp = find_min_array_element(temperatures, lines);
    double standard_deviation = compute_standard_deviation(temperatures, lines);
    printf("The highest temperature was %.2lfC at %5s, and the lowest temperature was %.2lf at %5s.\n", temperatures[index_largest_temp], time_array[index_largest_temp], temperatures[index_smallest_temp], time_array[index_smallest_temp]);
    printf("The standard deviation of the data is %f.\n",standard_deviation);
    deallocate_str_array(time_array, lines);
    free(temperatures);
    return 0;
}