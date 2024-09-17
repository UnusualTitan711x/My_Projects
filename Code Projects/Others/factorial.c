#include <stdio.h>

int factorial(int n);

int main(void)
{
    int n;

    for(int i = 0; i < 10; i++)
    {
        printf("Enter a number to calculate the factorial: ");
        scanf("%i", &n);

        printf("%i! = %i\n", n, factorial(n));
    }

    
}

int factorial(int n)
{
    if(n == 0) return 1;
    /*
    // Using Recursion
    int m = n;

    m *= factorial(n - 1);

    return m;
    */

   // Using For loop
   int p = 1;
   for(int i = 1; i <= n; i++)
   {
        p *= i;
   }

   return p;
}