#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h> //INT_MAX lives here

/* 
 * Author: Mads S. Balto
 * Date: 04/02/23
 * This script implements, tracks, and compares the clock cycles required for two "schemes" for initializing a 2D array, corresponding to a m times n matrix. I refer to the schemes as
 * "common", and "uncommon". The common scheme iterates through columns per row, whereas the uncommon iterates through row per column. The intent is to see which scheme requires 
 * uses the least amount of clock cycles
 */


int **allocate_matrix(unsigned int rows, unsigned int cols)
{
    int ** matrix = malloc(rows*sizeof(int*));
    for(unsigned int row=0; row<rows; row++)
    {
        matrix[row] = malloc(cols*sizeof(int));
    }
    return matrix;
}

void free_matrix(int ** matrix, unsigned int rows)
{
    for(unsigned int row=0; row<rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}

void print_2_dim_matrix(int ** array, unsigned int rows, unsigned int cols)
{
    for(unsigned int row = 0; row < rows; row++)
    {
        for(unsigned int col = 0; col<cols; col++)
        {
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }
    
}

/*The most common way of initalizing a matrix*/
int **initialize_matrix_random_elements_row_first(unsigned int rows,unsigned int cols)
{
    int ** matrix = allocate_matrix(rows,cols);
    for(unsigned int row=0; row < rows; row++)
        {
            for(unsigned int col=0; col < cols; col++)
            {
                //matrix[row][col] = rand() % 100;
                matrix[row][col] = 4;
            }
        }
        return matrix;
}
/* the non-common way of initializing a matrix*/
int **initialize_matrix_random_elements_col_first(unsigned int rows,unsigned int cols)
{
    int ** matrix = allocate_matrix(rows,cols);
    for(unsigned int col=0; col < cols; col++)
        {
            for(unsigned int row=0; row < rows; row++)
            {
                //matrix[row][col] = rand() % 100;
                matrix[row][col] = 4;
            }
        }
        return matrix;
}
clock_t measure_clock_cycles(int** (*initialization_method)(unsigned int, unsigned int), unsigned int rows, unsigned int cols)
{
    clock_t start = clock();
    int ** matrix = (*initialization_method)(rows,cols);
    clock_t end = clock();
    free_matrix(matrix,rows);
    return end-start;
}


int main()
{
    unsigned int rows = 10000;
    unsigned int cols = 10000;
    int ** matrix1 = initialize_matrix_random_elements_row_first(rows,cols);
    int ** matrix2 = initialize_matrix_random_elements_col_first(rows,cols);
    // printf("matrix with common initialization:\n");
    // print_2_dim_matrix(matrix1,rows,cols);
    // printf("matrix with uncommon initialization:\n");
    // print_2_dim_matrix(matrix2,rows,cols);
    free_matrix(matrix1,rows);
    free_matrix(matrix2,rows);
    clock_t duration_common_initialization = measure_clock_cycles(initialize_matrix_random_elements_row_first,rows,cols);
    clock_t duration_uncommon_initalization = measure_clock_cycles(initialize_matrix_random_elements_col_first,rows,cols);   
    printf("clock cycles for common initialization scheme: %ld \n",duration_common_initialization);
    printf("clock cycles for uncommon initialization scheme: %ld \n",duration_uncommon_initalization);
    double speed_up = ((double)duration_uncommon_initalization - (double)duration_common_initialization) / (double)duration_uncommon_initalization;
    printf("the common initialization scheme was %f%% faster than the uncommon initialization scheme.\n",speed_up);
    return 0;
}   