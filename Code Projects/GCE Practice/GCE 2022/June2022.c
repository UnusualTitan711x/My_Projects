#include <stdio.h>
#include <math.h>

// Functions
void intitialise(int tab[], int n);
int verifyprime(int x);
void setzero(int tab[], int n, int y);
void doDisplay(int tab[], int n);

int main()
{
    int tab[100], n, rootN;

    printf("Enter a upper limit for prime numbers: ");
    scanf("%d", &n);

    // finds and rounds the square root of n to the nearest int
    rootN = round(sqrt(n));
    
    intitialise(tab, n); // Initialising whole array from 1 to n
    tab[0] = 0; // Setting 1 to 0

    for(int i = 0; i < rootN; i++)
    {
        if(tab[i] == 0) continue; // skip to the next step of the element found is zero

        if(verifyprime(tab[i])) setzero(tab, n, tab[i]); // Verify for prime numbers and set their multiples to zero
    }

    // Final printing of results
    printf("\nThe prime numbers between 1 and %i are:\n", n);
    doDisplay(tab, n);
    
}

void intitialise(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = i + 1;
    }
}

int verifyprime(int x)
{
    int count = 0;

    for(int i = 1; i <= x; i++)
    {
        // Checking of a number divides x without remainder and count the number of factors found
        if((x % i) == 0) count++;
        if(count > 2) return 0; // if greater than 2, it means the number is not prime and return 0 (false)
    }

    return 1; // Else return 1 (true)
}

void setzero(int tab[], int n, int y)
{
    for (int i = 0; i < n; i++)
    {
        if(tab[i] > y && (tab[i] % y) == 0) // Setting all multiples of y to 0
            tab[i] = 0;
    }
    
}

void doDisplay(int tab[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(tab[i] != 0) 
        {
            if(tab[i] > 2) printf(", "); // Just for looks
            
            printf("%i", tab[i]);
        }
    }
}

// Code by Djiomou Arthur