#include <cs50.h>
#include <stdio.h>

int collatz(int n, int i)
{
    if (n == 1)
    {
        if (i == 0)
        {
            return 1;
        }
        else
        {
            return i;
        }
    }
    else if (n % 2 == 0)
    {
        return collatz(n/2, i+1);
    }
    else
    {
        return collatz(3*n+1, i+1);
    }
}

int main(void)
{
    int n = get_int("n = ");
    int i = collatz(n, 0);
    printf("%i\n", i);
}
