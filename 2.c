#include <stdio.h>
#include <stdlib.h>
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
    //double temperatures = malloc()

    char time[5];
    int temperature;
    for(int line=0; line<lines; line++)
    {
        err = fscanf(file,"%5s %d",&time,&temperature);
             
        printf("time: %5s, tempereature: %d.\n",time,temperature);
    }
    // int a;
    // char string1[20];
    // char string2[20];
    // err = fscanf(file, "%20s %4s %d", &string1, &string2, &a);
    // printf("%s %s %d\n",string1,string2,a);
    // err = fscanf(file, "%5s %4s %d", &string1, &string2, &a);
    // printf("%s %s %d\n",string1,string2,a);



    return 0;
}