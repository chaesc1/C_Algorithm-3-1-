#include <stdio.h>

#define NUM_OF_ARRAY 8
#define NUM_OF_COUNT 6

int main(void)
{
    int count[NUM_OF_COUNT] = {0};
    int array[NUM_OF_ARRAY] = {2,5,3,0,2,3,0,3};

    printf("원래 배열\n");
    for (int i = 0; i < NUM_OF_ARRAY; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    for (int  i = 0; i < NUM_OF_ARRAY; i++)
    {
        count[array[i]] += 1;
    }

    printf("카운트 수 0 1 2 3 4 5\n");
    for (int i = 0; i < NUM_OF_COUNT; i++)
    {
        printf("%d ",count[i]);
    }
    printf("\n");

    printf("Sorted Data\n");
    for (int i = 0; i < NUM_OF_COUNT; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            printf("%d ",i);
        }
    }
    
    
    
    
    return 0;
}