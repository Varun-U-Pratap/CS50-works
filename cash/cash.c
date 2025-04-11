#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int nucoins = 0;
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    while (change >= 25)
    {
        change -= 25;
        nucoins++;
    }
    while (change >= 10)
    {
        change -= 10;
        nucoins++;
    }
    while (change >= 5)
    {
        change -= 5;
        nucoins++;
    }
    while (change >= 1)
    {
        change -= 1;
        nucoins++;
    }
    printf("%i\n", nucoins);
}
