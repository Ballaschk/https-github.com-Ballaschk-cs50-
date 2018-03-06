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

    string k = argv[1];
    int key[strlen(k)];

    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isalpha(k[i]) == 0)
        {
            return 1;
        }
        if (isupper(k[i]))
        {
            key[i] = k[i] - 'A';
        }
        else
        {
            key[i] = k[i] - 'a';
        }
    }
    //if there are two arguments the program will print plaintext: and the user can give input
    printf("plaintext: ");
    string p = get_string();
    // atoi converts the string into a integer
    printf("ciphertext: ");

    int counter = 0;
    for (int j = 0, m = strlen(p); j < m; j++)
    {
        int h = key[counter];

        if (isupper(p[j]))
        {
            char c = (((p[j] + h) - 'A') % 26) + 'A';
            printf("%c", c);
            counter = (counter + 1) % strlen(k);
        }
        else if (islower(p[j]))
        {
            char c = (((p[j] + h) - 'a') % 26) + 'a';
            printf("%c", c);
            counter = (counter + 1) % strlen(k);
        }
        else
        {
            printf("%c", p[j]);
        }
    }

    printf("\n");

    return 0;
}
