#include <stdio.h>  
#include <stdlib.h> //rand()함수 라이브러리
#include <time.h>

#define PATH 0
#define WALL 1
#define BOMB 2
#define VISTED 3

int N,K;
int maze[0][0];

int findPath(int x,int y,int liveCnt)
{
    if(x<0 || y<0 || x>=N || y>=N || maze[x][y] == WALL)
    {
        return -1;
    }
    else if(x >= N-1 && y >= N-1)//탈출구
    {
        maze[x][y] = PATH;
        return 1;
    }
    else
    {
        if(maze[x][y]==BOMB)
            {
                liveCnt--;
            }
            if(liveCnt < 0)
            {
                return -1;
            }
        maze[x][y] = PATH;
        if(findPath(x-1,y,liveCnt) || findPath(x+1,y,liveCnt) || findPath(x,y-1,liveCnt) || findPath(x,y+1,liveCnt))
        {
            return 1;
        }
        
        maze[x][y] = VISTED;
        return -1;
    }
}
int main(void)
{
    
    scanf("%d",&N);

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            maze[i][j]= rand()%3;
            printf("%d ",maze[i][j]);
            if((j+1)%N==0)
            {
                printf("\n");
            }
        }
        
    }
    
    scanf("%d",&K);//
    

    if(findPath(0,0,K) == 1)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}