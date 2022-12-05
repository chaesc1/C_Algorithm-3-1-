#include <stdio.h>
int map[100][100], cnt = 0;
int N;
void DFS(int x, int y)
{
    if (map[x][y] == 1)//벽으로
        {
            cnt++;
            return;
        }
 
    if (x >= N || y >= N || x < 0 || y < 0)
        return;
    else if (x == N && y == N)//도착지점
        cnt++;
    else
    {
        map[x][y] = 1;
 
        DFS(x, y - 1);//싱
        DFS(x, y + 1);//하
        DFS(x - 1, y);//좌
        DFS(x + 1, y);//우
 
        map[x][y] = 0;

    }
}
 
int main(void)
{
    scanf("%d",&N);
 
    int i,j ;
 
    for (j = 0; j <N; j++)
    {
        for (i = 0; i <N; i++)
            scanf("%1d", &map[i][j]);
    }
 
    DFS(0, 0);
 
    printf("%d\n", cnt);
 
    return 0;
}