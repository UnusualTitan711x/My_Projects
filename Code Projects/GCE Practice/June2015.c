#include <stdio.h>

float CalcNetAmt(int units);

int main()
{
    // Initializing arrays for the meters
    int R1[6], R2[6], R3[6];
    float R4[6]; // For net amount paid

    for (int i = 0; i < 6; i++)
    {
        // Get and check inputs
        do
        {
            printf("Enter the previous reading: ");
            scanf("%i", &R1[i]);
        } while (R1[i] < 0);
        
        do
        {
            printf("Enter the current reading: ");
            scanf("%i", &R2[i]);
        } while (R2[i] < 0 || R2[i] < R1[i]);
        
        printf("\n");

        // Units consumed = current - previous 
        R3[i] = R2[i] - R1[i];

        R4[i] = CalcNetAmt(R3[i]);
    }

    // Print tables
    printf("Previous Reading \tCurrent Reading \tUnits Consumed \t\tNet Amount Payable\n");

    for (int i = 0; i < 6; i++)
    {
        printf("\t%i\t\t\t%i\t\t\t%i\t\t\t%.2f\n", R1[i], R2[i], R3[i], R4[i]);
    }

    return 0;
}

// Calculate the net amount to pay
float CalcNetAmt(int UC)
{
    float NET, VAT, TUA;
    float RENT = 500;

    if(UC > 100) // Insustrial case
    {
        TUA = 100 * (float) UC;
    }
    else // Domestic case
    {
        TUA = 65 * (float) UC;
    }

    VAT = 0.018 * TUA;
    NET = TUA + VAT + RENT;

    return NET;
    
}

// By Arthur.