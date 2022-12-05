#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTIVLES 100
#define INF 1000//무한을 의미

int parent[MAX_VERTIVLES];//부모노드


//초기화
void set_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;//전부 -1로 초기화
    }
    
}

//curr가 속하는 집합을 반환한다.
int set_find(int curr)
{
    if(parent[curr] == -1)
    {
        return curr; //루트
    }
    while (parent[curr] != -1)
    {
        curr = parent[curr];
    }
    return curr;
}


//두개의 원소가 속한 집합을 합친다.
void set_union(int a,int b)
{
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2)
        parent[root1] = root2;
}

struct Edge
{
    int start,end,weight;
};

typedef struct GraphType
{
    int n;//간선의 개수
    struct Edge edges[2*MAX_VERTIVLES];
}GraphType;

void graph_init(GraphType* g)
{
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTIVLES; i++)
    {
        g -> edges[i].start = 0;
        g -> edges[i].end = 0;
        g -> edges[i].weight = INF;
    }
}

//간선 삽입 연산
void insert_edge(GraphType* g,int start, int end, int weight)    
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = weight;
    g->n++;
}

int compare(const void* a,const void *b)
{
    struct Edge *x = (struct Edge *)a;
    struct Edge *y = (struct Edge *)b;
    return (x->weight - y->weight);
}

//Kruskal의 최소비용신장트리 프로그램
void Kruskal(GraphType *g)
{
    int edge_accepted = 0;//현재까지 선택된 간선의 수
    int uset,vset;//정점 u와 v의 집합번호
    struct Edge e;

    set_init(g->n);
    qsort(g->edges,g->n,sizeof(struct Edge),compare);

    printf("크루스칼 최소 신장 트리 알고리즘\n");
    int i = 0;
    while (edge_accepted <(g->n-1))//간선의 수가 n-1 이 될때까지
    {
        e = g->edges[i];
        uset = set_find(e.start);//정점u의 집합번호
        vset = set_find(e.end);//정점v의 집합번호
        if(uset != vset)//서로 다른 집합이면 사이클이 없어서 union가능
        {
            printf("간선 (%d ,%d)  %d 선택\n",e.start,e.end,e.weight);
            edge_accepted++;
            set_union(uset,vset);
        }
        i++;
    }
}

int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g,0,1,29);
    insert_edge(g,1,2,16);
    insert_edge(g,2,3,12);
    insert_edge(g,3,4,22);
    insert_edge(g,4,5,27);
    insert_edge(g,5,0,10);
    insert_edge(g,6,1,15);
    insert_edge(g,6,3,18);
    insert_edge(g,6,4,25);

    Kruskal(g);
    free(g);

    return 0;
}

