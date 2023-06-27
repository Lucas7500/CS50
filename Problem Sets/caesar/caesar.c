#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef char *string;

int main(int argc, string argv[])
{
    // If the user type something wrong, remind him how to use the program
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check that the input is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {

        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // get the plaintext
    string plaintext;
    printf("plaintext: ");
    scanf("%[^\n]%*c", plaintext);

    // define the key
    int key = atoi(argv[1]);

    // encrypt the message and return the ciphertext

    printf("Ciphertext: ");

    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] + key - 65) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] + key - 97) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }

    printf("\n");

    return 0;
}