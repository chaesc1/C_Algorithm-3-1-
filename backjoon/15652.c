#include <stdio.h>

int n,m;
int result[1000];


void backtracking(int depth,int cut)
{
    int i;

    if(depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ",result[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if(cut <= i)
            {
                result[depth] = i;
                backtracking(depth+1,i);
            }
        }
        
    }
}
int main(void)
{
    scanf("%d %d",&n,&m);
    backtracking(0,0);
    return 0;
}