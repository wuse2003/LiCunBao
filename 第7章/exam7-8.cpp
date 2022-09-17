#include "AdjGraph.cpp"			//包含邻接表的基本运算函数
int visited[MAXVEX];
void DFS(AdjGraph *G,int v)		//深度优先遍历算法
{	int w; ArcNode *p;
	printf("%d ",v);			//访问v顶点
	visited[v]=1;
	p=G->adjlist[v].firstarc;	//找v的第一个邻接点
	while (p!=NULL)				//找v的所有邻接点
	{	w= p->adjvex;			//顶点v的相邻点w
		if (visited[w]==0)		//顶点w未访问过
			DFS(G,w);			//从w出发深度优先遍历
		p=p->nextarc;			//找v的下一个邻接点
	}
}
int Connect(AdjGraph *G)	//判断无向图G的连通性
{	int i,flag=1;
	DFS(G,0);				//调用DFS算法,从顶点0开始深度优先遍历
	for (i=0;i<G->n;i++)
		if (visited[i]==0)
		{	flag=0;
			break;
		}
	return flag;
}
void main()
{
	AdjGraph *G;
	int n=5,e=6,i;
	int A[MAXVEX][MAXVEX]={
		{0,1,0,1,0},
		{1,0,1,0,0},
		{0,1,0,1,1},
		{1,0,1,0,1},
		{0,0,1,1,0}};
	CreateGraph(G,A,n,e);	//建立一个图7.1(a)的邻接表
	for (i=0;i<G->n;i++)
		visited[i]=0;
	if (Connect(G))
		printf("\n图G是连通图\n");
	else
		printf("\n图G是非连通图\n");
	DestroyGraph(G);
}

