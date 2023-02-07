#include <stdio.h>  
void str_input_func(char string[])
{
    printf("%.20s\n",string);
}
int main()
{
    str_input_func("yahah");
    return 0; 
}