#include <stdio.h>
#include "MinPath.cpp"		//含有两个求带权有向图中最短路径的函数
void main()
{
	MatGraph g;
	int n=6,e=11,v=0;
	int A[][MAXVEX]={
		{0,50,10,INF,INF,INF},
		{INF,0,15,50,10,INF},
		{20,INF,0,15,INF,INF},
		{INF,20,INF,0,35,INF},
		{INF,INF,INF,30,0,INF},
		{INF,INF,INF,3,INF,0}};
	CreateGraph(g,A,n,e);		//建立图7.29图的邻接矩阵
	printf("图G的存储结构:\n"); DispGraph(g);
	printf("Dijkstra求解结果如下:\n"); 
	Dijkstra(g,v);
	printf("Floyd求解结果如下:\n"); 
	Floyd(g);
	DestroyGraph(g);
}

