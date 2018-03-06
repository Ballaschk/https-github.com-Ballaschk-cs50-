#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    do
    {
        printf("Enter the amount: ");
        n = get_float();
    }
    while (n < 0);
    n *= 100;
    n = round(n);
    int c = 0;

    while (n >= 25)
    {
        n -= 25;
        c++;
    }
    while (n >= 10)
    {
        n -= 10;
        c++;
    }
    while (n >= 5)
    {
        n -= 5;
        c++;
    }
    while (n >= 1)
    {
        n -= 1;
        c++;
    }
    printf("%d\n", c);
}