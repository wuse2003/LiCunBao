#include <stdio.h>
#include <malloc.h>
#define MAXVEX 100				//图中最大顶点个数
#define INF 32767				//表示∞
typedef char VertexType[10];	//定义VertexType为字符串类型
typedef struct edgenode
{	int adjvex;					//邻接点序号
	int weight;					//边的权值
	struct edgenode *nextarc;	//下一条边的顶点
} ArcNode;						//每个顶点建立的单链表中边结点的类型
typedef struct vexnode
{	VertexType data;			//顶点信息
	ArcNode *firstarc; 			//指向第一条边结点
} VHeadNode;					//单链表的头结点类型
typedef struct 
{	int n,e;					//n为实际顶点数,e为实际边数
	VHeadNode adjlist[MAXVEX];	//单链表头结点数组
} AdjGraph;						//图的邻接表类型

void CreateGraph(AdjGraph *&G,int A[][MAXVEX],int n,int e)
//由邻接矩阵数组A、顶点数n和边数e建立图G的邻接矩阵存储结构
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	G->n=n; G->e=e;
	for (i=0;i<G->n;i++)			//邻接表中所有头结点的指针域置空
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<G->n;i++)				//检查A中每个元素
		for (j=G->n-1;j>=0;j--)
			if (A[i][j]>0 && A[i][j]<INF)		//存在一条边
			{
				p=(ArcNode *)malloc(sizeof(ArcNode));	//创建一个结点*p
				p->adjvex=j;
				p->weight=A[i][j]; 
				p->nextarc=G->adjlist[i].firstarc;		//采用头插法插入*p
				G->adjlist[i].firstarc=p;
			}
}
void DestroyGraph(AdjGraph *&G)	//销毁图
{
	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)		//释放边结点所占空间
	{
		pre=G->adjlist[i].firstarc;
		if (pre!=NULL)
		{
			p=pre->nextarc;
			while (p!=NULL)
			{
				free(pre);
				pre=p; p=p->nextarc;
			}
			free(pre);
		}
	}
	free(G);				//释放G所指的内存空间	
}
void DispGraph(AdjGraph *G)	//输出图的邻接表
{
	ArcNode *p;
	int i;
	for (i=0;i<G->n;i++)
	{
		printf("  [%2d]",i);
		p=G->adjlist[i].firstarc;	//p指向第一个邻接点	
		if (p!=NULL)
			printf(" →");
		while (p!=NULL)
		{
			printf(" %d(%d)",p->adjvex,p->weight);
			p=p->nextarc;			//p移向下一个邻接点
		}
		printf("\n");
	}
}
int Degree1(AdjGraph *G,int v)	//求无向图G中顶点v的度
{
	int d=0;
	ArcNode *p;
	if (v<0 || v>=G->n)
		return -1;				//顶点编号错误返回-1
	p=G->adjlist[v].firstarc;
	while (p!=NULL)				//统计v顶点的单链表中边结点个数即度
	{
		d++;
		p=p->nextarc;
	}
	return d;
}
int Degree2(AdjGraph *G,int v)	//求有向图G中顶点v的度
{
	int i,d1=0,d2=0,d;
	ArcNode *p;
	if (v<0 || v>=G->n)
		return -1;				//顶点编号错误返回-1
	p=G->adjlist[v].firstarc;
	while (p!=NULL)				//统计v顶点的单链表中边结点个数即出度
	{
		d1++;
		p=p->nextarc;
	}
	for (i=0;i<G->n;i++)		//统计边结点中adjvex为v的个数即入度
	{
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{
			if (p->adjvex==v) d2++;
			p=p->nextarc;
		}
	}
	d=d1+d2;
	return d;
}