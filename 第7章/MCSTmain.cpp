#include <stdio.h>
#include "MCST.cpp"		//����������С���������㷨
void main()
{
	MatGraph g;
	int n=5,e=8;
	int A[MAXVEX][MAXVEX]={{0,1,3,4,7},{1,0,2,INF,INF},{3,2,0,5,8},{4,INF,5,0,6},{7,INF,8,6,0}};
	CreateGraph(g,A,n,e);	//����ͼ7.18ͼ���ڽӾ���
	printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(g);
	printf("Prim:�Ӷ���0�����������С������:\n"); 
	Prim(g,0);
	printf("Kruskal:�������С������:\n"); 
	Kruskal(g);
	DestroyGraph(g);
}

