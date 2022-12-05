#include <stdio.h>
int graph[101][101] = {0, }; // 미로 저장
int q[10001][2] = {0, }; // 현재 방문한 좌표(x, y) 저장

// 상하좌우 (-1, 0), (1, 0), (0, -1), (0, 1) 이동
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
//int dy[4] = {0, 0, -1, 1};
int n = 0, m = 0; // 미로 크기
int cnt=0;
int visited[100][100];
int bfs() {
    // 큐 front, rear
    int front = 0, rear = 0;
    // 큐에 처음 (0, 0) 좌표 삽입
    q[front][0] = 0;
    q[front][1] = 0;
    visited[0][0] = 0;
    rear++;
    
    // 큐가 빌 때 까지
    while(front < rear){
        int x = q[front][0]; // x 좌표
        int y = q[front][1]; // y 좌표 
        front++; // front 이동
        
        // 인접 칸(상하좌우) 이동
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위를 벗어나는 경우
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            // 길이 아닌 경우
            if(graph[nx][ny] == 1)
                continue;
            
            if (visited[nx][ny] < visited[x][y]+1)
                continue;
            // 이전 칸에서 이동한 칸 수 + 1
            graph[nx][ny] = graph[x][y] + 1;

            // 큐에 (nx, ny) 삽입
            q[rear][0] = nx;
            q[rear][1] = ny;
            visited[nx][ny] = visited[x][y]+1;
            rear++;
        }
    }
    return graph[n][n];
}

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    int ans = bfs();
    printf("%d",visited[n-1][n-1]);
    return 0;
}