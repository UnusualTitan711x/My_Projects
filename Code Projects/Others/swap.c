#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Input value for A: ");
    scanf("%i", &a);

    printf("Input value for B: ");
    scanf("%i", &b);

    printf("Initially, A is %i and B is %i\n", a, b);

    a = a + b;

    b = a - b;

    a = a - b; 

    printf("Now, A is %i and B is %i\n", a, b);

}