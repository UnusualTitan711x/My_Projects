#include <stdio.h>

// Global Variables
int TOP, BOTTOM, LEFT, RIGHT, N, Z;

// Functions
void FillRowForward(int A[][N], int top, int left, int right);
void FillRowBackward(int A[][N], int bottom, int left, int right);
void FillColumnDownward(int A[][N], int top, int bottom, int right);
void FillColumnUpward(int A[][N], int top, int bottom, int left);
void SpiralOrder(int A[][N]);

void PrintRowForward(int A[][N], int top, int left, int right);
void PrintRowBackward(int A[][N], int bottom, int left, int right);
void PrintColumnDownward(int A[][N], int top, int bottom, int right);
void PrintColumnUpward(int A[][N], int top, int bottom, int left);
void PrintSpiralOrder(int A[][N]);

void PrintArray(int A[][N]);

int main(void)
{
    do{
        printf("Enter an integer greater than Zero: ");
        scanf("%d", &N);
    } while (N <= 0);

    int A[N][N];
   
    printf("Array arranged in a spiral order: \n\n");
    SpiralOrder(A);
    PrintArray(A);

    printf("\nSpiral order: \n");
    
    PrintSpiralOrder(A);
}

void SpiralOrder(int A[][N])
{
    Z = 1;
    TOP = 0;
    BOTTOM = N-1;
    LEFT = 0;
    RIGHT = N-1;

    while (Z <= N*N)
    {
        FillRowForward(A, TOP, LEFT, RIGHT);
        TOP++;
        FillColumnDownward(A, TOP, BOTTOM, RIGHT);
        RIGHT--;
        FillRowBackward(A, BOTTOM, LEFT, RIGHT);
        BOTTOM--;
        FillColumnUpward(A, TOP, BOTTOM, LEFT);
        LEFT++;
    }
    
}

void FillRowForward(int A[][N], int top, int left, int right)
{
    for(int i = left; i <= right; i++)
    {
        A[top][i] = Z;
        Z++;
    }
}

void FillRowBackward(int A[][N], int bottom, int left, int right)
{
    for(int i = right; i >= left; i--)
    {
        A[bottom][i] = Z;
        Z++;
    }
}

void FillColumnDownward(int A[][N], int top, int bottom, int right)
{
    for (int i = top; i <= bottom; i++)
    {
        A[i][right] = Z;
        Z++;
    }
    
}

void FillColumnUpward(int A[][N], int top, int bottom, int left)
{
    for (int i = bottom; i >= top; i--)
    {
        A[i][left] = Z;
        Z++;
    }
    
}

void PrintSpiralOrder(int A[][N])
{
    Z = 1;
    TOP = 0;
    BOTTOM = N-1;
    LEFT = 0;
    RIGHT = N-1;

    while (Z <= N*N)
    {
        PrintRowForward(A, TOP, LEFT, RIGHT);
        TOP++;
        PrintColumnDownward(A, TOP, BOTTOM, RIGHT);
        RIGHT--;
        PrintRowBackward(A, BOTTOM, LEFT, RIGHT);
        BOTTOM--;
        PrintColumnUpward(A, TOP, BOTTOM, LEFT);
        LEFT++;
    }
    
}

void PrintRowForward(int A[][N], int top, int left, int right)
{
    for(int i = left; i <= right; i++)
    {
        printf("%d\t", A[top][i]);
        Z++;
    }

    printf("\n");
}

void PrintRowBackward(int A[][N], int bottom, int left, int right)
{
    for(int i = right; i >= left; i--)
    {
        printf("%d\t", A[bottom][i]);
        Z++;
    }

    printf("\n");
}

void PrintColumnDownward(int A[][N], int top, int bottom, int right)
{
    for (int i = top; i <= bottom; i++)
    {
        printf("%d\t", A[i][right]);
        Z++;
    }

    printf("\n");
    
}

void PrintColumnUpward(int A[][N], int top, int bottom, int left)
{
    for (int i = bottom; i >= top; i--)
    {
        printf("%d\t", A[i][left]);
        Z++;
    }

    printf("\n");
    
}

void PrintArray(int A[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%i\t", A[i][j]);
        }
        printf("\n");
    }
}