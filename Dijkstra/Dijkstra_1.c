#include <stdio.h>
#define MAX 1001
#define INF 99999999

int D[MAX];// 출발지서 각 도시간 최소비용

int Visited[MAX];
int Map[MAX][MAX];

void Dijkstra(int maxV,int startV,int destV)    
{
    //최소거리를 INF로 초기화
    for (int  i = 0; i <= maxV; i++)
    {
        D[i] = INF;
    }

    //출발지는 0으로 초기화
    D[startV] = 0;

    //출발지에서 모든 정점 비교 , 비교회수는 간선수의 - 1
    for (int i = 0; i < maxV-1; i++)
    {
        //최솟값 초기화
        int min = INF;
        for (int j = 0; j < maxV-1; j++)
        {
            //가중치가 가장 작은 값 구하기.
            if(!Visited[j] && min > D[j])
            {
                min = D[j];
                startV = j;
            }
        }
        //방문 표시
        Visited[startV]  = 1;

        //인접 정점 체크
        for (int nextV = 1; nextV <= maxV; nextV++)
        {
            //이동 가능하고, 출발지에서 k까지의 총비용 > 출발지에서 V를 거쳐 k까지 가는 총 비용
            if(Map[startV][nextV] != INF && D[nextV] > D[startV] + Map[startV][nextV])
            {
                D[nextV] = D[startV] + Map[startV][nextV];
            }
        }
    }
    printf("%d\n",D[destV]);
    
}

void initMap()
{
    for (int y = 0; y < MAX; y++)
    {
        for (int x = 0; x < MAX; x++)
        {
            Map[y][x] = INF;
        }
        
    }
    
}
int main(void)
{
    int start = 0;
    int dest = 0;
    int N = 0;
    int M = 0;

    initMap();

    scanf("%d",&N);
    scanf("%d",&M);

    for (int i = 0; i < M; i++)
    {
        int s = 0;
        int d = 0;
        int w = 0;

        scanf("%d %d %d",&s,&d,&w);
        if(Map[s][d] > w)
        {
            Map[s][d] = w;
        }
    }
    scanf("%d %d",&start ,&dest);
    Dijkstra(N,start,dest);
    
    return 0;
}