#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i, score1, score2;
    int check_char(string word);
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    score1 = check_char(word1);
    score2 = check_char(word2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int check_char(string word)
{
    int i, sum = 0;
    for (i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 32;
        }
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'L' ||
            word[i] == 'N' || word[i] == 'O' || word[i] == 'R' || word[i] == 'S' ||
            word[i] == 'T' || word[i] == 'U')
        {
            sum += 1;
        }
        if (word[i] == 'D' || word[i] == 'G')
        {
            sum += 2;
        }
        if (word[i] == 'B' || word[i] == 'C' || word[i] == 'M' || word[i] == 'P')
        {
            sum += 3;
        }
        if (word[i] == 'F' || word[i] == 'H' || word[i] == 'V' || word[i] == 'W' || word[i] == 'Y')
        {
            sum += 4;
        }
        if (word[i] == 'K')
        {
            sum += 5;
        }
        if (word[i] == 'J' || word[i] == 'X')
        {
            sum += 8;
        }
        if (word[i] == 'Q' || word[i] == 'Z')
        {
            sum += 10;
        }
    }
    return sum;
}
