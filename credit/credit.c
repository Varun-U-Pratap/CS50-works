#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i, j, n, sum = 0, card[20];
    long cardno, temp, temp1;
    do
    {
        cardno = get_long("Number: ");
        temp = cardno;
        n = 0;
        while (temp > 0)
        {
            temp = temp / 10;
            n++;
        }
    }
    while (cardno < 1);
    for (i = n; i >= 1; i--)
    {
        card[i] = cardno % 10;
        cardno /= 10;
    }
    temp = card[1];
    temp1 = card[2];
    for (i = n - 1; i >= 1; i -= 2)
    {
        card[i] *= 2;
        sum = sum + card[i] % 10;
        card[i] /= 10;
        sum = sum + card[i] % 10;
    }
    for (i = n; i >= 1; i -= 2)
    {
        sum = sum + card[i];
    }
    if (sum % 10 == 0)
    {
        if (n == 15 && temp == 3 && (temp1 == 4 || temp1 == 7))
        {
            printf("AMEX\n");
        }
        else if (n == 13 && temp == 4)
        {
            printf("VISA\n");
        }
        else if (n == 16 && temp == 4)
        {
            printf("VISA\n");
        }
        else if (n == 16 && temp == 5 && temp1 >= 1 && temp1 <= 5)
        {
            printf("MASTERCARD\n");
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
