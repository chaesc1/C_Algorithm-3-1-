#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int *col;

void printQueens()
{
    printf(" ");
    for (int i = 1; i <= n; i++)    
    {
        printf("(%d, %d)\n",i,col[i]);
    }
    exit(1);
}

int promising(int i)
{
    int k = 1;
    while(k<i)
    {
        if(col[i] == col[k] || abs(col[i] - col[k]) == abs(i-k))
        {
            return 0;
        }
        k++;
    }
    return 1;
}

void queens(int i)
{
    if(promising(i))
    {
        if(i == n)
        {
            printQueens();
            return;
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                col[i+1] = j;
                queens(i+1);
            } 
        }
    }
}
int main(void)
{
    printf("INPUT N : ");
    scanf("%d",&n);
    col = (int *)malloc(sizeof(int)*(n+1));
    queens(0);
    printf("No Solution");

    return 0;
}