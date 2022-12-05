#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[],int n) 
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    
}
int main(void)
{
    return 0;
}