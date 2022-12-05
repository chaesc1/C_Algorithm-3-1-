#include <stdio.h>  

const int BACKGROUND_PIXEL = 0; //흰색부분
const int IMAGE_PIXEL = 1; //회색부분
const int ALREADY_COUNTED = 2; //빨간색부분
const int N = 8;

int grid[8][8];

int countingCells(int x,int y)
{
    if(x<0 || y<0 || x>=N || y >=N)
        return 0;
    else if(grid[x][y] != IMAGE_PIXEL)
        return 0;
    else
    {
        grid[x][y] = ALREADY_COUNTED;
        return 1+countingCells(x-1,y+1)+countingCells(x,y+1)
                +countingCells(x+1,y+1)+countingCells(x-1,y)
                +countingCells(x+1,y)+countingCells(x-1,y-1)
                +countingCells(x,y-1)+countingCells(x+1,y-1);

    }
}
int main(void)
{
    int x,y;
    printf("맵입력\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    printf("시작 위치 입력 :");
    scanf("%d %d",&x,&y);
    printf("현재 속한 Blob안에 image pixel의 개수 : %d\n",countingCells(x,y));
    
    return 0;
}