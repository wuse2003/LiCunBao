#include <stdio.h>
#include "GSearch.cpp"
void main()
{
	MatGraph g;
	int n=5,e=6;
	int A[MAXVEX][MAXVEX]={{0,1,0,1,0},{1,0,1,0,0},{0,1,0,1,1},{1,0,1,0,1},{0,0,1,1,0}};
	CreateGraph(g,A,n,e);	//����ͼ7.8(a)���ڽӾ���
	printf("�ڽӾ���G:\n"); DispGraph(g);
	printf("���ֱ�������:\n");
	printf("  DFS1:"); DFS1(g,0); printf("\n");
	printf("  BFS1:"); BFS1(g,0); printf("\n");
	DestroyGraph(g);
}

