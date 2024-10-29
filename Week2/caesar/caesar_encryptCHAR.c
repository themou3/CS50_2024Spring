#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encryptChar(char c, int key, bool isCapital);

int main(int argc, string argv[])
{
    // Check for the correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char *strKey = argv[1];

    // Validate that the key is a positive integer
    for (int i = 0; i < strlen(strKey); i++)
    {
        if (!isdigit(strKey[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(strKey) % 26; // Normalize the key

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
            ciphertext[i] = encryptChar(plaintext[i], key, isCap);
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

char encryptChar(char c, int key, bool isCapital)
{
    if (isCapital)
    {
        return (c - 'A' + key) % 26 + 'A'; // Return the new capital letter
    }
    else
    {
        return (c - 'a' + key) % 26 + 'a'; // Return the new lowercase letter
    }
}
