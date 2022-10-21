#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int         main(int argc, string argv[])
{
    int x;
    int y;
    int z;
    string plaintext;

    x = 0;
    if (argc == 2)
    {
        while (argv[1][x] != '\0')
        {
            if (argv[1][x] < '0' || argv[1][x] > '9')
            {
                printf("Usage: ./caesar key\n");
                return (1);
            }
            else
            {
                x++;
            }
        }
        plaintext = get_string("plaintext: ");
        y = atoi(argv[1]);
        z = 0;
        while (plaintext[z] != '\0')
        {
            if (plaintext[z] >= 'a' && plaintext[z] <= 'z')
            {
                plaintext[z] = (plaintext[z] - 96 + y) % 26 + 96;
            }
            if (plaintext[z] >= 'A' && plaintext[z] <= 'Z')
            {
                plaintext[z] = (plaintext[z] - 64 + y) % 26 + 64;
            }
            z++;
        }
        printf("ciphertext: %s\n", plaintext);
        return (0);
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
    return (1);
}
