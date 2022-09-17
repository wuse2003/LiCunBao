#include <stdio.h>
#include "GSearch.cpp"
void main()
{
	AdjGraph *G;
	int n=5,e=6,i;
	int A[MAXVEX][MAXVEX]={{0,1,0,1,0},{1,0,1,0,0},{0,1,0,1,1},{1,0,1,0,1},{0,0,1,1,0}};
	CreateGraph(G,A,n,e);	//建立图7.8(a)的邻接表
	printf("邻接表G:\n"); DispGraph(G);
	for (i=0;i<G->n;i++) visited[i]=0;
	printf("各种遍历序列:\n");
	printf("  DFS:"); DFS(G,0); printf("\n");
	printf("  BFS:"); BFS(G,0); printf("\n");
	DestroyGraph(G);
}

