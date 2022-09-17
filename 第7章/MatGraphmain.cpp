#include "MatGraph.cpp"		//包含邻接矩阵的基本运算函数
void main()
{
	MatGraph g;
	int n=5,e=7,i;
	int A[MAXVEX][MAXVEX]={{0,1,2,6,INF},{INF,0,INF,4,5},{INF,INF,0,INF,3},{INF,INF,INF,0,INF},{INF,INF,INF,7,0}};
	CreateGraph(g,A,n,e);	//建立图7.4图的邻接矩阵
	printf("图G的存储结构:\n"); DispGraph(g);
	printf("图G中所有顶点的度:\n"); 
	printf("  顶点\t度\n");
	for (i=0;i<g.n;i++)
		printf("   %d\t%d\n",i,Degree2(g,i));
	DestroyGraph(g);
}

