#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Text: ");
    int i;
    float L, l = 0, S, s = 0, W = 0, index = 0.00, grade = 1;
    for (i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            l++;
        }
        else if (text[i] == ' ')
        {
            W++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }
    }
    L = (l * 100.00) / (W + 1);
    S = (s * 100.00) / (W + 1);
    index = 0.0588 * L - 0.296 * S - 15.8;
    printf("%f %f %f\n, %f\n", l, W, S, index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index > 10.5)
    {
        printf("Grade 16+\n");
        return 0;
    }
    i = 2;
    while (index < i - 0.5 || index >= i + 0.5)
    {
        i++;
    }
    printf("Grade %i\n", i);
    return 0;
}
