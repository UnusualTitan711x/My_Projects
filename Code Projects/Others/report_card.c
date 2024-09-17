#include <stdio.h>

int main()
{
    float S1[5], average, sumOfMarks = 0;
    int coeff[5], sumOfCoeffs = 0;
    char subjects[5][20];
    char name[25];

    printf("Enter your name: ");
    scanf("%s", name); 

    printf("Enter the names of the subjects and required information: \n");

    for(int i = 0; i < 5; i++)
    {
        printf("Subject %i: ", i+1);
        scanf("%s", subjects[i]);
        printf("Coefficient: ");
        scanf("%d", &coeff[i]);
        printf("Mark: ");
        scanf("%f", &S1[i]);

        printf("\n");

        sumOfCoeffs += coeff[i];
        sumOfMarks += S1[i] * coeff[i];
    }

    average = sumOfMarks / (float) sumOfCoeffs;
    
    printf("Here are your results\n");
    printf("Name: %s\n", name);

    printf("Subjects\tCoeff\tMark\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s\t%d\t%.2f\n", subjects[i], coeff[i], S1[i]);
    }

    printf("\nAverage: %.2f", average);
}