#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encryptStr(char *str, int key);

int main(int argc, string argv[])
{
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

    int key = atoi(strKey);
    string plaintext = get_string("plaintext:  ");

    // Encrypt the plaintext
    char *ciphertext = encryptStr(plaintext, key);

    // Output the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    // Free allocated memory
    free(ciphertext);
    return 0;
}

char *encryptStr(char *str, int key)
{
    // Normalize the key to avoid unnecessary large shifts
    key = key % 26;

    // Allocate memory for ciphertext
    int length = strlen(str);
    char *ciphertext = malloc(length + 1); // +1 for null terminator
    if (ciphertext == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit if malloc fails
    }

    // Encrypt the string
    for (int i = 0; i < length; i++)
    {
        char newChar = str[i];

        if (isupper(newChar))
        {
            newChar = (newChar - 'A' + key) % 26 + 'A';
        }
        else if (islower(newChar))
        {
            newChar = (newChar - 'a' + key) % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        ciphertext[i] = newChar;
    }

    ciphertext[length] = '\0'; // Null-terminate the ciphertext
    return ciphertext;
}
