#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        printf("Number is between 0 and 23\n");
        n = get_int("Number: ");

    }
    while (n < 0 || n > 23);
// Print out this many rows
    for (int i = 0; i < n ; i++)
    {

// Print out this many spaces
        for (int m = 0; m < n - i - 1; m++)
        {
            printf("%s", " ");
        }
// Print out this many hashes
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        }
        printf("\n");
    }
     return 0;
}
