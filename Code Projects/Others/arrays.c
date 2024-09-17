#include <stdio.h>

void PrintArray(int arr[]);
int SumOfElements(int arr[]);
float AverageOfElements(int arr[]);
void CountDuplicates(int arr[]);
int IsElement(int arr[], int elt);
void Frequency(int arr[]);
void PrintUniqueElements(int arr[]);
void SortAscending(int arr[]);
void SortDescending(int arr[]);
void CopyArray(int arr1[], int arr2[]);

int main()
{
    int nums[] = {4, 9, 3, 1, 4, 8, 5, 7};
    int s = sizeof(nums);

    PrintArray(nums);
    PrintUniqueElements(nums);

    SortAscending(nums);
    PrintArray(nums);

    SortDescending(nums);
    PrintArray(nums);

    //CountDuplicates(nums);
    //Frequency(nums);
}

void PrintArray(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int SumOfElements(int arr[])
{
    int sum = 0;

    for(int i = 0; i < 8; i++)
    {
        sum += arr[i];  //sum = sum + arr[i]
    }

    return sum;
}

float AverageOfElements(int arr[])
{
    float average = (float) SumOfElements(arr) / 8;
    return average;
}

void CountDuplicates(int arr[])
{
    for(int i = 0; i < 8; i++)
    {
        int count = 0;

        for(int j = i+1; j < 8; j++)
        {
            if(arr[i] == arr[j]) count++;
        }

        if(count > 0) printf("%d is duplicated %d time(s).\n", arr[i], count);
    }
}

int IsElement(int arr[], int elt)
{
    for(int i = 0; i < 8; i++)
    {
        if(arr[i] == elt) return 1;
    }

    return 0;
}

void Frequency(int arr[])
{
    for(int i = 0; i < 8; i++)
    {
        int count = 1;

        for(int j = i+1; j < 8; j++)
        {
            if(arr[i] == arr[j]) count++;
        }

        printf("Frequency of %d: %d.\n", arr[i], count);
    }
}

void PrintUniqueElements(int arr[])
{
    int arr_copy[8];
    CopyArray(arr, arr_copy);

    for(int i = 0; i < 8; i++)
    {
        for(int j = i+1; j < 8; j++)
        {
            if(arr_copy[i] == arr_copy[j]) 
            {
                arr_copy[i] = 0;
                arr_copy[j] = 0;
            }
        }

        if(arr_copy[i] != 0) printf("%d ", arr_copy[i]);
    }

    printf("\n");
}

void SortAscending(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        int min = arr[i]; // Initialise minimum number to be the first element

        for(int j = i+1; j < 8; j++)
        {
            if(arr[j] < arr[i]) // If a number less than the min, swap positions with the first element
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

void SortDescending(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        int max = arr[i]; // Initialise minimum number to be the first element

        for(int j = i+1; j < 8; j++)
        {
            if(arr[j] > arr[i]) // If a number less than the min, swap positions with the first element
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

void CopyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < 8; i++)
    {
        arr2[i] = arr1[i];
    }
    
}


/*

<data_type> (name)[<size>];

int numbers[50];
int numbers[] = {25, 22, 33, 26};

char name[20][25];

for(<initialisation>; <condition>; <increment>)
{

}

for(i = 0; i < 5; i++)
{
    printf(" %d", numbers[i]);
}

while(<condition>)
{
    //Do something
}

int s = 0;

while(s == 0)
{
    b = b+2;
}


do
{
    b= b + 2;
}while(s == 0);


int Sum(int a, int b)
{
    return <something>;
}


void Sum()
{

}

#include<stdlib.h>
#include<time.h>

srand(time(0));
int N = (rand() % 50);
int numbers[50];

printf("%d ". numbers[N]);


*/