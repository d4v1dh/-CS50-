#include <cs50.h>
#include <stdio.h>



int         main(void)
{
    int height;

    // check if height is between the values 1 and 8 exclusively
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int c = 0; c < height; c++)
    {
        for (int x = height - 1; x > c; x--)
        {
            printf(" ");
        }
        for (int i = 0; i <= c; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}