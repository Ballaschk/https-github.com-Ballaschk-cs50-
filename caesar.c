#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //if there are no two arguments the program will print error
    if (argc != 2)
    {
        printf("error!\n");
        return 1;
    }
    //if there are two arguments the program will print plaintext: and the user can give input
    printf("plaintext: ");
    string p = get_string();

    // atoi converts the string into a integer
    int k = atoi(argv[1]);
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))
            {
                char c = (((p[i] + k) - 'A') % 26) + 'A';
                printf("%c", c);
            }
            else
            {
                char c = (((p[i] + k) - 'a') % 26) + 'a';
                printf("%c", c);
            }
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}
