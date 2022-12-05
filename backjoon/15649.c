#include <stdio.h>  

int N,M;
int result[1000];
int check[1000];

void backtracking(int depth)
{
    int i;
    
    if(depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ",result[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if(check[i] == 0)
            {
                result[depth] = i;
                check[i] = 1;
                backtracking(depth+1);
                check[i] = 0;
            }
        }
        
    }
}
int main(void)
{
    scanf("%d %d",&N,&M);
    backtracking(0);
    return 0;
}