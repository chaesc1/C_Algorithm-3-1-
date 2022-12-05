#include <stdio.h>
#include <stdlib.h> //rand()함수 라이브러리
#include <time.h>
#include <stdbool.h>
    //배경설정
  int N;
int map[0][0];
//bool istrue = true;
//bool isfalse = false;
    
    const int PATHWAY = 0; // 지나갈 수 있는 길
    const int WALL = 1; // 벽
    int BOMB = 2;//폭탄
    const int BLOCKED = 3; // 돌아오면서 막은 길
    const int PATH = 4; //지나가면서 표시한 길
 
//함수 지정
bool findMapPath(int x, int y,int cnt) {
    
    if(x<0 || y<0 || x>=N || y>=N) {//시작
        return false;
    }
    else if(map[x][y] == WALL)
    {
        return false;
    }
    else if(x == N-1 && y == N-1) {//도착지점이라면.
            map[x][y] = PATH;
            return true;
    }
    else 
    {
        if(map[x][y] == 2)//2일떄
        {
            printf("BOMB\n");
            cnt--;
             if(cnt < 0)
                {
                    return false;
                }
                map[x][y] = PATH;
                    if(findMapPath(x+1, y,cnt) || findMapPath(x, y+1,cnt)
                                    || findMapPath(x-1, y,cnt) || findMapPath(x, y-1,cnt)) //동-북 서 남 순서 탐색
                    {
                        return true;
                    }
                    map[x][y] = BLOCKED;
                    return false;
        }
        else
        {
            printf("PATHWAY\n");
            map[x][y] = PATH;
            if(findMapPath(x+1, y,cnt) || findMapPath(x, y+1,cnt)
                || findMapPath(x-1, y,cnt) || findMapPath(x, y-1,cnt)) //동-북 서 남 순서 탐색
            {
                return true;
            }
            map[x][y] = BLOCKED;
        return false;
        }
    }
}
//main
int main() {
    int liveCnt = 0;
    //Q. 0,0 지점부터 7,7까지 갈 수 있는 길은 존재할까?
    srand(time(NULL));
    
    printf("input N\n");
    scanf("%d",&N);
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            map[i][j] = rand()%3;
           // map[0][0] = 0;
            printf("%d ",map[i][j]);
            if ((j+1)%N==0) {
                printf("\n");
            }
        }
    }
    printf("목숨개수 : ");
    scanf("%d",&liveCnt);
    printf("미로를 지날 수 있습니까?\n");
    if(findMapPath(0,0,liveCnt)) printf("네!");
    else printf("아니오!");
  return 0;
}
