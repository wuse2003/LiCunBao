#include <stdio.h>
#include "MinPath.cpp"		//�����������Ȩ����ͼ�����·���ĺ���
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
	CreateGraph(g,A,n,e);		//����ͼ7.29ͼ���ڽӾ���
	printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(g);
	printf("Dijkstra���������:\n"); 
	Dijkstra(g,v);
	printf("Floyd���������:\n"); 
	Floyd(g);
	DestroyGraph(g);
}

