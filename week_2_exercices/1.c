#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    int size = 1000000;
    clock_t start = clock();
    file = fopen("data.txt", "w");
    if (file == NULL)
    {
        printf("error opening file!\n");
        return 1;
    }
    for (size_t index = 0; index < size; index++)
    {
        fprintf(file, "128\n");
    }
    fclose(file);
    printf("clock cycles required to write ASCII file: %zu\n", clock() - start);




    start= clock();
    file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("error opening file!\n");
        return 1;
    }
    int *integers;
    integers = malloc(size * sizeof(int));
    for (size_t index = 0; index < size; index++)
    {
        fscanf(file, "%d", &integers[index]);
    }
    printf("integers array check, 128=%d\n", integers[20]);
    printf("Clock cycles required to read ASCII file: %zu\n", clock() - start);

    file = fopen("data.bin", "wb");
    start = clock();
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fwrite(integers, sizeof(int), size, file);
    printf("clock cycles required for write binary file: %zu\n",clock()-start);
    start = clock();
    int *integers_2;
    integers_2 = malloc(size * sizeof(int));
    file = fopen("data.bin", "rb");
    fread(integers_2, sizeof(int), size, file);
    free(integers);
    free(integers_2);
    printf("clock cycles required for read binary file: %zu\n",clock()-start);
    return 0;
}