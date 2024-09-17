#include <stdio.h>

void Initialise(int *maxNoOfStars, int *NoOfSpaces, int *NoOfStars);
void OutputLeadingSpaces(int *NoOfSpaces);
void OutputLineOfStars( int *NoOfStars);
void Adjust(int *NoOfStars, int *NoOfSpaces, int *maxNoOfStars);
int k = 0;

int main()
{
    int n, spaces, stars;
    Initialise(&n, &spaces, &stars);
    printf("%i\n", n);

    for (int i = 0; i < n; i++)
    {
        OutputLeadingSpaces(&spaces);
        OutputLineOfStars(&stars);
        Adjust(&stars, &spaces, &n);
    }
    
    return 0;
}

void Initialise(int *maxNoOfStars, int *NoOfSpaces, int *NoOfStars)
{
    do
    {
        printf("Enter the max number of stars (base): ");
        scanf("%i", &(*maxNoOfStars));
    }while (*maxNoOfStars < 3);

    *NoOfSpaces = *maxNoOfStars - 1;
    *NoOfStars = 1;
}

void OutputLeadingSpaces(int *NoOfSpaces)
{
    // Code Here
    for (int i = 0; i < *NoOfSpaces; i++)
    {
        printf(" ");
    }
    
}

void OutputLineOfStars(int *NoOfStars)
{
    // Code here
    for (int i = 0; i < *NoOfStars; i++)
    {
        printf("*");
    }
    printf("\n");
    
}

void Adjust(int *NoOfStars, int *NoOfSpaces, int *maxNoOfStars)
{
    if(*NoOfStars >= *maxNoOfStars || k == 1)
    {
        k = 1;
        *NoOfStars -= 2;
        *NoOfSpaces += 1;
    }
    else
    {
        *NoOfStars += 2;
        *NoOfSpaces -= 1;
    }
    
}