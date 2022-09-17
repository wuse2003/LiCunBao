#include "AdjGraph.cpp"			//包含邻接表的基本运算函数
int visited[MAXVEX];
int HasaPath(AdjGraph *G,int u,int v)
{
	ArcNode *p;
	int w;
	visited[u]=1;
	p=G->adjlist[u].firstarc;		//p指向u的第一个邻接点
	while (p!=NULL)
	{	w=p->adjvex;				//邻接点的编号为w
		if (w==v)					//找到顶点v后返回1
			return 1;
		if (visited[w]==0)			//若顶点w没有访问过
		{
			if (HasaPath(G,w,v))	//从w出发进行深度优先遍历
				return true;		//若从w出发找到顶点v返回1
		}
		p=p->nextarc;				//p指向下一个邻接点
	}
	return 0;						//没有找到顶点v，返回0
}
int HasaPath1(AdjGraph *G,int u,int v)
{
	ArcNode *p;
	int w;
	if (u==v) return 1;				//找到顶点v后返回1
	visited[u]=1;
	p=G->adjlist[u].firstarc;		//p指向u的第一个邻接点
	while (p!=NULL)
	{	w=p->adjvex;				//邻接点的编号为w
		if (visited[w]==0)			//若顶点w没有访问过
		{
			if (HasaPath1(G,w,v))	//从w出发进行深度优先遍历
				return true;		//若从w出发找到顶点v返回1
		}
		p=p->nextarc;				//p指向下一个邻接点
	}
	return 0;						//没有找到顶点v，返回0
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
	CreateGraph(G,A,n,e);		//建立图7.8(a)的邻接表
	for (i=0;i<G->n;i++)
		visited[i]=0;
	int u=0,v=4;
	if (HasaPath1(G,u,v))
		printf("顶点%d到%d有简单路径\n",u,v);
	else
		printf("顶点%d到%d没有简单路径\n",u,v);
	DestroyGraph(G);
}

