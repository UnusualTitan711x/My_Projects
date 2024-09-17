#include <stdio.h>

int main()
{
    int mat1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int mat2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int mat3[3][3];


    // Output
    printf("Mat 1:\n");
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Mat 2:\n");
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("Result:\n");
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}