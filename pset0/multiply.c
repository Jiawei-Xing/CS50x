#include <cs50.h>
#include <stdio.h>

float multiply(float a, float b);

int main(void)
{
    float a = get_float("a: ");
    float b = get_float("b: ");
    printf("%f\n", multiply(a, b));
}

float multiply(float a, float b)
{
    return a * b;
}