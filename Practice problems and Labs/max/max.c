// Practice writing a function to find a max value

#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        printf("Number of elements: ");
        scanf("%d", &n);
    } while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int temp_value;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] < array[j])
            {
                temp_value = array[j];
                array[j] = array[i];
                array[i] = temp_value;
            }
        }
    }

    return array[0];
}
