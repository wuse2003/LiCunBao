#include <stdio.h>
#include "GSearch.cpp"
void main()
{
	MatGraph g;
	int n=5,e=6;
	int A[MAXVEX][MAXVEX]={{0,1,0,1,0},{1,0,1,0,0},{0,1,0,1,1},{1,0,1,0,1},{0,0,1,1,0}};
	CreateGraph(g,A,n,e);	//建立图7.8(a)的邻接矩阵
	printf("邻接矩阵G:\n"); DispGraph(g);
	printf("各种遍历序列:\n");
	printf("  DFS1:"); DFS1(g,0); printf("\n");
	printf("  BFS1:"); BFS1(g,0); printf("\n");
	DestroyGraph(g);
}

