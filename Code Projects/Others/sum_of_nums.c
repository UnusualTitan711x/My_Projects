#include <stdio.h>

int main(void)
{
    int nums[] = {8,1,4,0,3,5,9,2,6,7};

    int n = (sizeof(nums)/sizeof(int));

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n;j++)
        {
            if((nums[i] + nums[j]) == 10)
            {
                printf("The sum of %i and %i is 10\n", nums[i], nums[j]);
            }
        }
    }
}