#include <stdio.h>
#include <stdlib.h>


char ** allocate_2d_char_array(size_t n_elements)
{
    char ** time_array;
    time_array = malloc(n_elements*sizeof(char*));
    for(size_t index =0; index<n_elements; index++)
    {
        time_array[index] = malloc(6*sizeof(char));
    }    
    return time_array;
}
/**
 * @brief deallocates memory currently occupied by a two-dimensional array of chars, i.e. array of strings.
 *
 * @param matrix two-dimensional char array to be deallocated.
 * @param rows amount of char arrays, i.e. amount of strings.
 */
void free_2d_char_array(char **matrix, size_t rows)
{
    for (size_t row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}
double find_highest_temperature(double * temperature_array, )



int main()
{
    FILE *file;
    int err;
    file = fopen("temperature.txt","r");
    if(file==NULL)
    {
        printf("Error opening a file\n");
        return 1;
    }
    size_t lines;
    err = fscanf(file,"%zu",&lines);
    if(err !=1)
    {
        printf("Error with fscanf()\n");
        return 1;
    }
    printf("amount of lines: %zu\n",lines);
    char ** time_array = allocate_2d_char_array(lines);
    float * temperatures;
    temperatures = malloc(lines*sizeof(float));
    for(size_t index=0; index<lines; index++)
    {
        err = fscanf(file,"%5s %f",time_array[index], &temperatures[index]);
        printf("time: %5s, temperature: %f\n",time_array[index],temperatures[index]);
    }
    free_2d_char_array(time_array,lines);
    return 0;
}