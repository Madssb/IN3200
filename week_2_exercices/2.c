#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//script visualizes how using memcpy is faster than copy initialization.


double * initialize_array(size_t array_size)
{
    double *array;
    array = malloc(array_size * sizeof(double));
    for(size_t index= 0; index<array_size; index++)
    {
        array[index] = 20.0;
    }
    return array;
}

int main()
{
    size_t array_size = 100000000;
    double *a = initialize_array(array_size);
    double *b;
    b = malloc(array_size * sizeof(double));
    clock_t pre_hand_copy = clock();
    for(size_t index = 0; index<array_size; index++)
    {
        b[index] = a[index];
    }
    clock_t post_hand_copy = clock();
    printf("copy operation loop required %ld clock cycles.\n",post_hand_copy-pre_hand_copy);
    double *c = malloc(array_size * sizeof(double));
    clock_t pre_memcpy = clock();
    memcpy(c,a,array_size*sizeof(double));
    clock_t post_memcpy = clock();
    printf("memcpy copy required %ld clock cycles.\n",post_memcpy-pre_memcpy);
    printf("control check: %lf %lf %lf\n",a[20],b[20],c[20]);
    free(a);
    free(b);
    free(c);
    return 0;
}