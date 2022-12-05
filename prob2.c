#include <stdio.h>
#include <stdbool.h>
    //배경설정
int N;
int map[100][100];
    
    #define PATHWAY  0// 지나갈 수 있는 길
    #define WALL 1 // 벽
    #define BOMB 2//폭탄 밟으면 목숨 깎이고 4로 바뀌어야함 상수 처리 하면 안된다.
    #define BLOCKED 3 // 돌아오면서 막은 길
    #define PATH 4 //지나가면서 표시한 길
 
//함수 지정
bool findMapPath(int x, int y,int cnt) {
    if(x<0 || y<0 || x>=N || y>=N || cnt <0) {//시작
        return false;
    }
    else if(map[x][y] != PATHWAY && map[x][y] != BOMB)
    {
        return false;
    }
    else if(x == N-1 && y == N-1) {//도착지점이라면.
            if(map[x][y] == BOMB)
            {
                cnt--;
                if(cnt<0)
                {
                    return false;
                }
                else
                {
                    map[x][y] = PATH;
                return true;
                }
            }
            else
            {
                map[x][y] = PATH;
                return true;
            }
    }
    else
    {
        if(map[x][y] == BOMB)//폭탄 밟으면
        {
            cnt--;//카운트 줄고
            //printf("bombcnt = %d\n",bombcnt);
    
            
                map[x][y] = PATH;
                if(findMapPath(x+1, y,cnt) || findMapPath(x, y+1,cnt)
                    || findMapPath(x-1, y,cnt) || findMapPath(x, y-1,cnt)) //동-북 서 남 순서 탐색
                {
                    return true;
                }   
            
            map[x][y] = BLOCKED;
            return false;
        }
        map[x][y] = PATH;
        if(findMapPath(x+1, y,cnt) || findMapPath(x, y+1,cnt)
            || findMapPath(x-1, y,cnt) || findMapPath(x, y-1,cnt)) //동-북 서 남 순서 탐색
        {
            return true;
        }
    }
    map[x][y] = BLOCKED;
    return false;
}
//main
int main() {
    int liveCnt = 0;
    
    printf("input N\n");
    scanf("%d",&N);
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%1d",&map[i][j]);
        }
    }
    scanf("%d",&liveCnt);

    if(findMapPath(0,0,liveCnt)) printf("YES");
    else printf("NO");
  return 0;
}
