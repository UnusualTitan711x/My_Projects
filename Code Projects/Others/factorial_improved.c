#include <stdio.h>

unsigned long long int factorial(unsigned long long int n);

int main(void)
{
    unsigned long long int n;

    for(int i = 0; i < 10; i++)
    {
        printf("Enter a number to calculate the factorial: ");
        scanf("%llu", &n);

        printf("%llu! = %llu\n", n, factorial(n));
    }

    
}

unsigned long long int factorial(unsigned long long int n)
{
    
    //int m = n;
    if(n == 0) return 1;

    /*
    m *= factorial(n - 1);

    return m;
    */

   unsigned long long int p = 1;
   for(int i = 1; i <= n; i++)
   {
        p *= i;
   }

   return p;
}