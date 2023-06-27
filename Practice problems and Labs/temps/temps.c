// Practice working with structs
// Practice applying sorting algorithms

#include <stdio.h>

typedef char *string;

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // create temporary values for cities and temperature
    string temp_city;
    int temp_temp;

    for (int i = 0; i < NUM_CITIES; i++)
    {
        // compare the value with all of the others
        for (int j = i + 1; j < NUM_CITIES; j++)
        {
            // Considering its in descending order, check if there are temperatures greater than the first city in left to right
            if (temps[i].temp < temps[j].temp)
            {
                // If the condition is true, swap the cities and its respective temperature
                temp_city = temps[j].city;
                temp_temp = temps[j].temp;

                temps[j].city = temps[i].city;
                temps[j].temp = temps[i].temp;

                temps[i].city = temp_city;
                temps[i].temp = temp_temp;
            }
            // If the temperatures are equal, prioritize the city in alphabetical order
            else if (temps[i].temp == temps[j].temp && temps[i].city[0] > temps[j].city[0])
            {
                temp_city = temps[j].city;
                temp_temp = temps[j].temp;

                temps[j].city = temps[i].city;
                temps[j].temp = temps[i].temp;

                temps[i].city = temp_city;
                temps[i].temp = temp_temp;
            }
        }
    }
}