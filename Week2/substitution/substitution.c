#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encryptChar(char c, char *key, bool isCapital);

int main(int argc, string argv[])
{
    // Check for the correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Initialize key
    char *keyMap = argv[1];

    // Validate that the key lenght is 26
    if (strlen(keyMap) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Validate that the key contains only an alphabetic chars

    for (int i = 0; i < strlen(keyMap); i++)
    {
        if (!isalpha(keyMap[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

    // AND that all chars are unique
        int x = tolower(keyMap[i]) - 'a';
        int arr[26];
        arr[x]++;

        if (arr[x] > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext:  ");
    int length = strlen(plaintext);

    // Allocate memory for ciphertext
    string ciphertext = malloc(length + 1); // +1 for null terminator
    if (ciphertext == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Encrypt the plaintext
    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            bool isCap = isupper(plaintext[i]);
            ciphertext[i] = encryptChar(plaintext[i], keyMap, isCap);
        }
        else
        {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters remain unchanged
        }
    }

    ciphertext[length] = '\0'; // Null-terminate the ciphertext

    // Output the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    // Free allocated memory
    free(ciphertext);
    return 0;
}

char encryptChar(char c, char *key, bool isCapital)
{
    if (isCapital)
    {
        // return mapped capital char
        c -= 'A'; // find index of letter [0 - 25];
        return toupper(key[(int) c]);
    }
    else
    {
        // return mapped low char
        c -= 'a'; // find index of letter [0 - 25];
        return tolower(key[(int) c]);
    }
}
