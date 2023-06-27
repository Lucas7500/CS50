#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char *string;

int main(int argc, string argv[])
{
    // Define conditions where the program can't run
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Create the alphabet(where key letters will be storaged)
    char alphabet[26];

    // Fill the alphabet with the key letters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            alphabet[i] = argv[1][i];
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    // Check if some letter of the alphabet is repeated
    for (int k = 0; k < 27; k++)
    {
        for (int f = k + 1; f < 27; f++)
        {
            if (alphabet[k] == alphabet[f])
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
    }

    // get the plaintext from the user
    string plaintext;
    printf("plaintext: ");
    scanf("%[^\n]%*c", plaintext);

    // replace the letters of the plaintext with the key letters
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (plaintext[j] >= 65 && plaintext[j] <= 90) // Case where plaintext letter is uppercase
        {
            plaintext[j] = toupper(alphabet[plaintext[j] - 65]);
        }
        else if (plaintext[j] >= 97 && plaintext[j] <= 122) // Case where plaintext letter is lowercase
        {
            plaintext[j] = tolower(alphabet[plaintext[j] - 97]);
        }
    }

    // Define the ciphertext variable that storage the encrypted plaintext
    string ciphertext = plaintext;

    printf("ciphertext: %s\n", ciphertext);
}