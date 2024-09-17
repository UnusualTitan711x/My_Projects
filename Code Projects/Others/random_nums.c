#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sort(int numbers[]);
void PrintArray(int arr[]);

int main(void)
{
    int nums[10];

    srand(time(0)); // Generates random seed so as to get different random numbers after every execution of rand()

    printf("Array of unsorted numbers: ");
    for (int i = 0; i < 10; i++)
    {
        nums[i] = rand() % 21; // Random numbers between 0 and 20
    }

    PrintArray(nums);

    
    printf("\n\n");

    Sort(nums); // Sort the array in ascending order

    printf("Array of sorted numbers: ");
    PrintArray(nums);
    
}

// Function to sort the numbers int the array
// Using Selection Sort algorithm
void Sort(int numbers[])
{
    for (int i = 0; i < 10; i++)
    {
        int min = numbers[i]; // Initialise minimum number to be the first element

        for(int j = i+1; j < 10; j++)
        {
            if(numbers[j] < numbers[i]) // If a number less than the min, swap positions with the first element
            {
                int tmp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = tmp;
            }
        }
    }
}

void PrintArray(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%i", arr[i]);

        if(i != 9)
            printf(", ");
    }
}

// Code by Djiomou Arthur