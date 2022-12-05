#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int N;
int cnt1 = 0;
int cnt2 = 0;
int cnt = 0;
int map[100][100];

#define PATHWAY  0// 지나갈 수 있는 길
#define WALL 1 // 벽
#define BLOCKED 2 // 돌아오면서 막은 길
#define PATH 3 //지나가면서 표시한 길

bool findMapPath(int x,int y)
{
    if (x<0 || y<0 || x>=N|| y>=N || map[x][y] != PATHWAY)
    {
        return false;
    }
    else if(x == N-1 && y == N-1)//도착지점이면.
    {
        //cnt1++;
        map[x][y] = PATH;
        return  true;
    }
    else//도착지점이 아니고 미로 안이라면.
    {
        map[x][y] = PATH;//갈수있는 통로라고 찍어줘        
        if(findMapPath(x+1,y))//오른쪽
        {
            return true;
        }
        else
        {
            if(findMapPath(x+1, y) || findMapPath(x, y+1) || findMapPath(x-1, y) || findMapPath(x, y-1))
                {
                    cnt1++;
                    return true;
                }
                map[x][y] = BLOCKED;
                return false;
        }

        if(findMapPath(x,y+1))//하
        {
            return true;
        }
        else
        {
            if(findMapPath(x+1, y) || findMapPath(x, y+1) || findMapPath(x-1, y) || findMapPath(x, y-1))
                {
                    cnt2++;
                    return true;
                }
                map[x][y] = BLOCKED;
                return false;
        }
    }
}

int main(void)
{
    int way;
    scanf("%d",&N);

    
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }

    if(findMapPath(0,0))
    {
        if(cnt1 > cnt2)
        {
            printf("%d",cnt1);
            printf("%d",cnt2);
        }
        else
        {
            printf("%d",cnt1);
            printf("%d",cnt2);
        }
    }
    else
    {
        printf("NO PATH");
    }
    
    
    return 0;
}