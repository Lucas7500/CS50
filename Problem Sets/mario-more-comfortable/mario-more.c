#include <stdio.h>

int main(void)
{
    // Get the height from the user
    int height, column, row, spaces;
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    // make the pyramid
    // spaces = height - row - 1

    for (column = 0; column < height; column++)
    {
        for (spaces = 0; spaces < height - row - 1; spaces++)
        {
            printf(" ");
        }

        for (row = 0; row <= column; row++)
        {
            printf("#");
        }

        printf("  ");

        for (row = 0; row <= column; row++)
        {
            printf("#");
        }

        printf("\n");
    }
}