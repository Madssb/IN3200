#include <stdlib.h>
#include <stdio.h>
/*
 * Scipt initializez three-dimensional array, such that array[i][j][k] = i*y*z+j*z+k, where (x,y,z) are the dimensions,
 * And allocated applying a one-dimensional underlying contiguous storage.
 */


double * allocate_3d_array(size_t x, size_t y,size_t z)
{
    double * array = malloc(x*y*z*sizeof(double))
    for(size_t i=0; i<x;i++)
    {
        for(size_t j=0; j<y; j++)
        {
            for(size_t k=0; k<z; k++)
            {
                
            }
        }
    }
} 



int main()
{
    size_t x = 10;
    size_t y = 10;
    size_t z = 10;

    return 0;
}