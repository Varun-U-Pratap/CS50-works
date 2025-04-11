#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    while (argc != 2)
    {
        printf("./substitution KEY\n");
        return 1;
    }
    string key = argv[1];
    string temp = key;
    int length = strlen(key), check[28];
    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        temp[i] = toupper(temp[i]);
        check[i] = temp[i];
        for (int j = 0; j < i; j++)
        {
            if (temp[i] == check[j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext:  ");
    int textlength = strlen(plaintext);
    int copy[textlength];
    for (int i = 0; i < textlength; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                for (int j = 'A'; j <= 'Z'; j++)
                {
                    if (plaintext[i] == j)
                    {
                        copy[i] = temp[(j - 65)];
                    }
                }
            }
            if (islower(plaintext[i]))
            {
                for (int j = 'a'; j <= 'z'; j++)
                {
                    if (plaintext[i] == j)
                    {
                        copy[i] = temp[(j - 97)];
                        copy[i] = tolower(copy[i]);
                    }
                }
            }
        }
        else
        {
            copy[i] = plaintext[i];
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < textlength; i++)
    {
        printf("%c", copy[i]);
    }
    printf("\n");
}
