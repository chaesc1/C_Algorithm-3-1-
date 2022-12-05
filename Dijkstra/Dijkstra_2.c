#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>

#define INF 98762343

int N,M; //N = node , M = 간선
int Map[1002][1002];
int dest[1002];
int isVisted[1002];
int start,end;

void input()
{
    scanf("%d %d",&N,&M);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Map[i][j] = INF;
        }
        dest[i] = INF;
        isVisted[i] = 0;
    }
    
    for (int i = 1; i <= M; i++)
    {
        int u,v,w;

        scanf("%d %d %d",&u,&v,&w);
        if(Map[u][v] > w)
            Map[u][v] = w;
    }
    scanf("%d",&start);
    scanf("%d",&end);
}

void Dijkstra()
{
    int min;
    int v=0;
    dest[start] = 0;
    for (int i = 1; i <= N; i++)
    {
        min = INF;
        for (int j = 1; j <= N; j++)
        {
            if(isVisted[j]==0 && min > dest[j])
            {
                min = dest[j];
            }
            v=j;
        }
    }
    isVisted[v] = 1;
    for (int j = 1; j <= N; j++)
    {
        if(dest[j] > dest[v]+Map[v][j] && Map[v][j] != min)
        {
            dest[j] = dest[v] + Map[v][j];
        }
    }
    
}

void output()   
{
    printf("%d",dest[end]);
}
int main(void)
{
    input();
    Dijkstra();
    output();

    return 0;
}