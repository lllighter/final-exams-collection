#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
typedef struct node *node_ptr; // 指向结点的指针类型
typedef struct node{  // 结点的定义
	int vertex;
	int weight;
	node_ptr next;
};

void PrintList(node_ptr ptr)
{
	while(ptr){
		printf("%d ", ptr->vertex);
		ptr = ptr->next;
	}
}


void dfs(node_ptr graph[], int visited[], int v)
{
	node_ptr  w;
    visited[v] = TRUE ;
    printf ("%d ", v ) ;
    for(w=graph[v]; w; w = w->next )
        if  ( !visited[ w->vertex ] )
			dfs(graph, visited, w->vertex);

}

void  bfs ( node_ptr graph[], int visited[], int  v )
{   /* breadth first search of a graph
        beginning with vertex v */
    node_ptr  w;
	circular_queue queue = CreateQueue(100);
    printf ("%d ", v);
    visited[v] = TRUE ;
	element e;
	e = v;
	EnQueue(&queue, e);
	while(!IsQueueEmpty(queue))  {
		DeQueue(&queue, &e);
        v = e;
        for( w = graph[v]; w; w = w->next )
           if  ( !visited[ w->vertex ] )  {
				printf ("%d ", w->vertex ) ;
				e =  w->vertex;
				EnQueue(&queue, e);
				visited[w->vertex] = TRUE ;
            }  /* end if */
    }  /* end while-loop */
    
}

int choose(int distance[], int n, short int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i=0;i<n;i++)
		if(distance[i]<min && !found[i]){
			min = distance[i];
			minpos = i;
		}
	return minpos;
}


void shortestpath ( int  v,  int  cost[][MAX_VERTICES], 
                                   int  distance [],  int  n,  short  int  found [] )
{   int  i, u, w ;
    for  ( i = 0; i < n; i++ )  {  /* initialization */
        found [ i ] = FALSE ;
        distance [ i ] = cost [ v ] [ i ] ;
    }  /* end for-loop */
    found [ v ] = TRUE ;
    distance [ v ] = 0 ;
    for  ( i = 0; i < n/2; i++ )  {
        u = choose ( distance, n, found ) ;   /* O( n ) */
  /* find the min distance not yet checked.  Program 6.11 on p.296 */
        found [ u ] = TRUE ;
        for  ( w = 0; w < n; w++ )
            if ( !found [ w ] )
                 if ( distance [ u ] + cost [ u ] [ w ] < distance [ w ] )
                 /* if adding u into S makes distance[w] shorter */
                    distance [ w ] = distance [ u ] + cost [ u ] [ w ] ;
    }   /* end for-loop */
}


void main()
{
	int number_vertex, number_edges;
	FILE *fp;

	fp = fopen("c:\\input.txt","r");
	// 输入图
	// 读入顶点个数，边的个数
	fscanf(fp, "%d%d",&number_vertex,&number_edges);
	// 建立一个大小为number_vertex的数组，存储每一个顶点出发的邻接表的头指针。
	node_ptr *graph = (node_ptr *)malloc(sizeof(node_ptr)*number_vertex);
	// 初始化
	for(int i=0; i<number_vertex; i++)
		graph[i] = NULL;
	// 根据边的个数，输入每一条边
	for(int i=0; i<number_edges; i++){
		// 读入一条边的信息（start,end,weight）
		int start, end, weight;
		fscanf(fp, "%d%d%d", &start, &end, &weight);
		// 在graph[start]这个链表的最前面新增一个结点(end,weight)
		node_ptr temp = (node_ptr)malloc(sizeof(node));
		temp->vertex = end;
		temp->weight =weight;
		temp->next = graph[start];
		graph[start] = temp;
	}

	// 输出核实
	for(int i=0; i<number_vertex; i++){
		printf("%d:",i);
		PrintList(graph[i]);
		printf("\n");
	}

	int *visited;
	visited = (int *)malloc(sizeof(int)*number_vertex);
	
	// DFS
	for(int i=0;i<number_vertex;i++)
		visited[i]=FALSE;
    printf("the dfs result is:");
	dfs(graph, visited, 1);
	printf("\n");
	
	// BFS
	for(int i=0;i<number_vertex;i++)
		visited[i]=FALSE;
    printf("the bfs result is:");
	bfs(graph, visited, 1);
	printf("\n");

	// ShortestPath
	// 建立邻接矩阵

	// 
}