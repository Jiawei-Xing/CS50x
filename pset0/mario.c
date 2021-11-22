#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //input positive integers
    int n;
    do
    {
        n = get_int("Width: ");
    }
    while (n < 1);
    
    //print out ?s
    for (int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}