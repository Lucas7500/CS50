#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef char *string;

int convert(string input);
int number = 0;
int main(void)
{
    string input;

    printf("Enter a positive integer: ");
    scanf("%[^\n]%*c", input);

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int count = strlen(input);
    int temporaryInt = 0;

    // recursive base case
    if (count == 0)
    {
        return number;
    }
    else
    {
        temporaryInt = input[count - 1] - '0';
        input[count - 1] = '\0';

        convert(input);

        number = number * 10 + temporaryInt;
        return number;
    }

    return number;
}