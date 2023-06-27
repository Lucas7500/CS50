#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        printf("Start size of the population: ");
        scanf("%d", &startSize);
    } while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        printf("End size of the population: ");
        scanf("%d", &endSize);
    } while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int population = startSize;
    int years = 0;

    while (population < endSize)
    {
        int gain = (population / 3);
        int lose = (population / 4);
        population = population + gain - lose;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}