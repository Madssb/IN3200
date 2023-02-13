#include <limits.h> //INT_MAX lives here
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

double double_pseudo_rng()
{
    double rand_double = (double)rand()/(double)INT_MAX;
    if(rand() & 1)
    {
        rand_double *= -1;
    }
    rand_double *= rand();
    return rand_double
}

int main()
{
    srand((unsigned int)time(NULL)); // seed the random number generator to known value
    double rand_double = (double)rand()/(double)INT_MAX;
    if(rand() & 1)
    {
        rand_double *= -1;
    }
    rand_double *= rand();
    printf("random double generated: %f\n",rand_double);

    return 0;
}