#include "MatGraph.cpp"			//包含邻接矩阵的基本运算函数
#include "AdjGraph.cpp"			//包含邻接表的基本运算函数
void MatToAdj(MatGraph g,AdjGraph *&G)	//将邻接矩阵g转换成邻接表G
{	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<g.n;i++)					//给邻接表中所有头节点的指针域置初值
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//检查邻接矩阵中每个元素
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)		//存在一条边
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//创建一个节点*p
				p->adjvex=j;
				p->weight=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		//采用头插法插入*p
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void AdjToMat(AdjGraph *G,MatGraph &g)	//将邻接表G转换成邻接矩阵g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)
		for (j=0;j<G->n;j++)
			if (i==j) g.edges[i][i]=0;
			else g.edges[i][j]=INF;
	for (i=0;i<G->n;i++)
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	g.edges[i][p->adjvex]=p->weight;
			p=p->nextarc;
		}
	}
	g.n=G->n; g.e=G->e;
}

void main()
{
	MatGraph g,g1;
	AdjGraph *G;
	int n=5,e=7;
	int A[MAXVEX][MAXVEX]={{0,1,2,6,INF},{INF,0,INF,4,5},{INF,INF,0,INF,3},{INF,INF,INF,0,INF},{INF,INF,INF,7,0}};
	CreateGraph(g,A,n,e);	//建立图7.4图的邻接矩阵
	printf("邻接矩阵g:\n"); DispGraph(g);
	printf("g转换为G\n");
	MatToAdj(g,G);
	printf("邻接表G:\n"); DispGraph(G);
	printf("G转换为g1\n");
	AdjToMat(G,g1);
	printf("邻接矩阵g1:\n"); DispGraph(g1);
	DestroyGraph(g);
	DestroyGraph(g1);
	DestroyGraph(G);
}

