#include <stdio.h>
#include <stdlib.h> //rand()함수 라이브러리
#include <time.h>

int countNum(int arr[],int inputK,int index)
{
    if(index >= 0)
    {
        if(arr[index-1] < inputK)
        {
            return 1+countNum(arr,inputK,index-1);
        }
        else
        {
            return countNum(arr,inputK,index-1);
        }
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int array[1000];
    int inputnum;
    int inputK;
    int cnt = 0;
    srand(time(NULL));

    scanf("%d",&inputnum);

    for (int i = 0; i < inputnum; i++)
    {
        //array[i]=rand()%inputnum+1;
        //printf("%d ",array[i]);
        scanf("%1d",&array[i]);
    }
    scanf("%d",&inputK);   
    cnt = countNum(array,inputK,inputnum);
    printf("\n");
    printf("%d",cnt);

    return 0;
}
