#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include <limits.h> //INT_MAX lives here

/*
 * Author: Mads S. Balto
 * Date: 04/02/23
 * program compares the
 *
 */

/**
 * @brief Dyamically allocates memory for an two-dimensional array representing a (m x n) array
 *
 * @param rows amount of row elements  i.e. size of array holding nested arrays
 * @param cols amount of col elements i.e. size of nested arrays
 * @return double** Pointer to two-dimensional array, representing a (m x n) matrix
 */
double **allocate_matrix(size_t rows, size_t cols)
{
    double **matrix = malloc(rows * sizeof(double *));
    for (size_t row = 0; row < rows; row++)
    {
        matrix[row] = malloc(cols * sizeof(double));
    }
    return matrix;
}
/**
 * @brief deallocates memory currently occupied by a two-dimensional array
 *
 * @param matrix amount of row elements, i.e. size of array holding nested arrays
 * @param rows amount of col elements, i.e. size of nested arrays
 */
void free_matrix(double **matrix, size_t rows)
{
    for (size_t row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}
/**
 * @brief prints each and every element of a provided two-dimension array, representing a (m x n) matrix, according to current matrix displaying conventions.
 *
 * @param array two-dimensional array representing a (m x n) array.
 * @param rows amount of row elements, i.e. size of array holding nested array.
 * @param cols amount of col elements, i.e. size of nested arrays.
 */
void print_2_dim_matrix(double **array, size_t rows, size_t cols)
{
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            printf("%f ", array[row][col]);
        }
        printf("\n");
    }
}

/**
 * @brief initializes a two dimensional array, according to the most common scheme, i.e. initializing elements along the column, and incrementing the row.
 *
 * @param rows amount of row elements, i.e. size of array holding nested array.
 * @param cols amount of col elements, i.e. size of nested arrays.
 * @return double** two-dimensional array with pseudo-rng-like doubles
 */
double **initialize_matrix_random_elements_row_first(size_t rows, size_t cols)
{
    double **matrix = allocate_matrix(rows, cols);
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            // matrix[row][col] = rand() % 100;
            matrix[row][col] = 4.;
        }
    }
    return matrix;
}
/* the non-common way of initializing a matrix*/

/**
 * @brief Initializes a two-dimensional array, according to the uncommon scheme, i.e. initializing the elements along the row, and incrementing the column.
 *
 * @param rows amount of row elements, i.e. size of array holding nested array.
 * @param cols amount of col elements, i.e. size of nested arrays.
 * @return double** two-dimensional array with pseudo-rng-like doubles
 */
double **initialize_matrix_random_elements_col_first(size_t rows, size_t cols)
{
    double **matrix = allocate_matrix(rows, cols);
    for (size_t col = 0; col < cols; col++)
    {
        for (size_t row = 0; row < rows; row++)
        {
            // matrix[row][col] = rand() % 100;
            matrix[row][col] = 4.;
        }
    }
    return matrix;
}
/**
 * @brief Tracks the clock cycles required for initializing a two-dimensional array of specified size with doubles per initialization scheme.
 *
 * @param initialization_method Scheme used for initializing the two-dimensional array 
 * @param rows Amount of row elements, i.e. size of array holding nested array.
 * @param cols Amount of col elements, i.e. size of nested arrays.
 * @return clock_t Amount of clock cycles required for initializing two-dimensional array per the provided initialization scheme.
 */
clock_t measure_clock_cycles(double **(*initialization_method)(size_t, size_t), size_t rows, size_t cols)
{
    clock_t start = clock();
    double **matrix = (*initialization_method)(rows, cols);
    clock_t end = clock();
    free_matrix(matrix, rows);
    return end - start;
}

int main()
{
    srand((unsigned int)time(NULL)); // seed the random number generator to known value
    size_t rows = 10000;
    size_t cols = 10000;
    double **matrix1 = initialize_matrix_random_elements_row_first(rows, cols);
    double **matrix2 = initialize_matrix_random_elements_col_first(rows, cols);
    // printf("matrix with common initialization:\n");
    // print_2_dim_matrix(matrix1,rows,cols);
    // printf("matrix with uncommon initialization:\n");
    // print_2_dim_matrix(matrix2,rows,cols);
    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);
    clock_t duration_common_initialization = measure_clock_cycles(initialize_matrix_random_elements_row_first, rows, cols);
    clock_t duration_uncommon_initalization = measure_clock_cycles(initialize_matrix_random_elements_col_first, rows, cols);
    printf("clock cycles for common initialization scheme: %ld \n", duration_common_initialization);
    printf("clock cycles for uncommon initialization scheme: %ld \n", duration_uncommon_initalization);
    double speed_up = ((double)duration_uncommon_initalization - (double)duration_common_initialization) / (double)duration_uncommon_initalization;
    printf("the common initialization scheme was %f%% faster than the uncommon initialization scheme.\n", speed_up);
    return 0;
}