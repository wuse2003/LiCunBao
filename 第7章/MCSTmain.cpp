#include <stdio.h>
#include "MCST.cpp"		//包含构造最小生成树的算法
void main()
{
	MatGraph g;
	int n=5,e=8;
	int A[MAXVEX][MAXVEX]={{0,1,3,4,7},{1,0,2,INF,INF},{3,2,0,5,8},{4,INF,5,0,6},{7,INF,8,6,0}};
	CreateGraph(g,A,n,e);	//建立图7.18图的邻接矩阵
	printf("图G的存储结构:\n"); DispGraph(g);
	printf("Prim:从顶点0出发构造的最小生成树:\n"); 
	Prim(g,0);
	printf("Kruskal:构造的最小生成树:\n"); 
	Kruskal(g);
	DestroyGraph(g);
}

