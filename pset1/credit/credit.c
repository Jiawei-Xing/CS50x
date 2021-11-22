#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt card number from user
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    //checksum
    int i = 1;
    int sum = 0;
    int multiply;
    for (long n = 10; num % (n / 10) != num; n *= 10)
    {
        if (i % 2 == 0)
        {
            multiply = ((num % n) / (n / 10)) * 2;
            if (multiply % 10 == multiply)
            {
                sum += multiply;
            }
            else
            {
                sum += (multiply % 10) + (multiply / 10);
            }
        }
        else
        {
            sum += (num % n)  / (n / 10);
        }
        i++;
    }

    //check card type
    if (sum % 10 > 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (i - 1 == 15)
        {
            if ((num / 10000000000000) == 34 || (num / 10000000000000) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (i - 1 == 16)
        {
            if ((num / 100000000000000) == 51 || (num / 100000000000000) == 52 || (num / 100000000000000) == 53
                || (num / 100000000000000) == 54 || (num / 100000000000000) == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (num / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (i - 1 == 13)
        {
            if (num / 1000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

}