#include <stdio.h>

int n,m;
int result[1000];
int check[1000];

void backtracking(int depth,int nomulti)
{
    int i;

    if(m == depth)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ",result[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            if(check[i] == 0 && nomulti < i)
            {
                result[depth] = i;
                check[i] = 1;
                backtracking(depth+1,i);
                check[i] = 0;
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