#include <cs50.h>
#include <math.h>
#include <stdio.h>

int     main(void)
{
    int     cents;
    float   money;
    int     i;

    do
    {
        money = get_float("How much change is owed? ");
    }
    while (money <= 0);

    cents = round(money * 100);

    i = 0;
    for (; cents >= 25; i++)
    {
        cents -= 25;
    }
    for (; cents >= 10; i++)
    {
        cents -= 10;
    }
    for (; cents >= 5; i++)
    {
        cents -= 5;
    }
    for (; cents >= 1; i++)
    {
        cents -= 1;
    }
    printf("%i\n", i);
}