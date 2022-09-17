#include "AdjGraph.cpp"		//包含邻接表的基本运算函数
void main()
{
	AdjGraph *G;
	int n=5,e=7,i;
	int A[MAXVEX][MAXVEX]={{0,1,2,6,INF},{INF,0,INF,4,5},{INF,INF,0,INF,3},{INF,INF,INF,0,INF},{INF,INF,INF,7,0}};
	CreateGraph(G,A,n,e);	//建立图7.4图的邻接表
	printf("图G的存储结构:\n"); DispGraph(G);
	printf("图G中所有顶点的度:\n"); 
	printf("  顶点\t度\n");
	for (i=0;i<G->n;i++)
		printf("   %d\t%d\n",i,Degree2(G,i));
	DestroyGraph(G);
}

