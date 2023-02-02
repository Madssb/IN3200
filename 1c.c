#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h> //INT_MAX lives here


int *initialize_matrix_random_elements_row_first(int rows,int cols)
{
for(index1=0; index1 < rows; index1++)
    {
        for(index2=0; index2 < cols; index2++)
        {
            matrix[index1][index2] = rand() % 100;
        }
    }
    return matrix_array;
}

int *initialize_matrix_random_elements_col_first(int rows,int cols)
{
for(index2=0; index2 < col; index2++)
    {
        for(index1=0; index1 < row; index1++)
        {
            matrix[index1][index2] = rand() % 100;
        }
    }
    return matrix_array;
}
int main()
{
    int rows = 5;
    int cols = 7;
    int* matrix1 = initialize_matrix_random_elements_row_first(rows,cols);
    int* matrix2 = initialize_matrix_random_elements_col_first(rows,cols);


}