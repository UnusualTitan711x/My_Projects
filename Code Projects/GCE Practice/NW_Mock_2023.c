#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Hash(int N);
void initStudInfo();
void studHash();
void studResultInfo(int A[2][5]);

int hash[5];
int Result[2][5];

struct studInfo
{
    int Sn;
    int average;
    int hashCode;
}studResult[5];


int main()
{
    printf("Results\n");
    initStudInfo();
    Hash(20);
    studHash();
    studResultInfo(Result);

    srand(time(0));

    printf("Sn: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", studResult[i].Sn);
    }
    printf("\n");

    printf("hashcode: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", Result[0][i]);
    }
    printf("\n");

    printf("average: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", Result[1][i]);
    }
    printf("\n");
    
}

void Hash(int N)
{
    int exist, r, counter = 0;
    while (counter < 5)
    {
        exist = 0;
        r = (rand()%N) + 11;

        if((r%2) != 0)
        {
            for (int i = 0; i < 5; i++)
            {
                if(r == hash[i]) 
                {
                    exist = 1;
                    break;
                }
            }
            
            if(exist == 0)
            {
                hash[counter] = r;
                counter++;
            }
        }
    }
    
}

void initStudInfo()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Enter student %i's Sn: ", i+1);
        scanf("%d", &studResult[i].Sn);
        printf("Enter student %i's average: ", i+1);
        scanf("%d", &studResult[i].average);
    }
    
}

void studHash()
{
    for (int i = 0; i < 5; i++)
    {
        studResult[i].hashCode = hash[i];
    } 
}

void studResultInfo(int A[2][5])
{
    for (int i = 0; i < 5; i++)
    {
        A[1][i] = studResult[i].average;
        A[0][i] = studResult[i].hashCode;
    }
    
}