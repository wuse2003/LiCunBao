#include "AdjGraph.cpp"					//包含邻接表的基本运算函数
int visited[MAXVEX];					//全局数组
void FindaPath(AdjGraph *G,int u,int v,int path[],int d)
{	ArcNode *p;
	int w,i;
	visited[u]=1;
	d++;
	path[d]=u;							//顶点u加入到路径中
	if (u==v)							//找到一条路径
	{	for (i=0;i<=d;i++)				//输出找到一条路径并返回
			printf("%d ",path[i]);
		printf("\n");
		return;
	}
	p=G->adjlist[u].firstarc;			//p指向u的第一个相邻点
	while (p!=NULL)
	{	w=p->adjvex;					//相邻点的编号为w
		if (visited[w]==0)
			FindaPath(G,w,v,path,d);	//递归调用
		p=p->nextarc;					//p指向下一个相邻点
	}
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
	int u=0,v=4,d=-1;
	int path[MAXVEX];
	printf("从顶点%d到%d的一条路径:",u,v);
	FindaPath(G,u,v,path,d);
}
