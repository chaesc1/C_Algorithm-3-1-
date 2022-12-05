#include <stdio.h>
#include <stdlib.h> //rand()함수 라이브러리
#include <time.h>
int N;
int maze[0][0];

#define PATHWAY 0 
#define WALL 1
#define BOMB 2
#define BLOCKED 3
#define PATH 4

int findmaze(int x,int y,int cnt)
{
    if(x<0 || y<0 || x>=N || y>=N)
    {
        return 0;
    }
    else if(maze[x][y] != PATHWAY || maze[x][y] != BOMB)//첫 시작이 1,3일경우
    {
        return 0;
    }
    else if(x==N-1 && y==N-1)
    {
        maze[x][y] = PATH;
        return 1;
    }
    else if(maze[x][y] == BOMB)
        {
            cnt--;
            if(cnt < 0)
            {
                return 0;
            }
            else
            {
                 maze[x][y] = PATH;
                if(findmaze(x-1,y,cnt)||findmaze(x,y+1,cnt)||findmaze(x+1,y,cnt)||findmaze(x,y-1,cnt))
                {
                    return 1;
                }
            
                maze[x][y] = BLOCKED;
                return 0;
            }
        }
    else
    {
        maze[x][y] = PATH;
            if(findmaze(x-1,y,cnt)||findmaze(x,y+1,cnt)||findmaze(x+1,y,cnt)||findmaze(x,y-1,cnt))
            {
                return 1;
            }
            
                maze[x][y] = BLOCKED;
                return 0;
    }
}
int main(void)
{
    int liveCnt;
    scanf("%d",&N);

srand(time(NULL));
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            maze[i][j] = rand()%3;
           // map[0][0] = 0;
            printf("%d ",maze[i][j]);
            if ((j+1)%N==0) {
                printf("\n");
            }
        }
    }
    printf("목숨개수 : ");
    scanf("%d",&liveCnt);//최대로 맞을수있는 폭탄수 

    printf("미로를 지날 수 있습니까?\n");

    if(findmaze(0,0,liveCnt)) printf("YES");
    else printf("NO");

    return 0;
}