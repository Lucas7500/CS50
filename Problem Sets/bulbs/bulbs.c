#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char *string;

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message;
    printf("Message: ");
    scanf("%[^\n]%*c", message);

    // Iterate through each character of the string
    for (int i = 0; i < strlen(message); i++)
    {
        int binary_numbers[] = {0, 0, 0, 0, 0, 0, 0, 0};

        // Convert the character into ASCII
        int decimal = message[i];

        // Convert the character into binary and put it in the reverse order of the array
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            binary_numbers[j] = decimal % 2;
            decimal /= 2;
        }

        // Print the binary in the order of the array
        for (int k = 0; k < 8; k++)
        {
            print_bulb(binary_numbers[k]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}