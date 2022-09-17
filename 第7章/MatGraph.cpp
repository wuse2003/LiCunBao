#include <stdio.h>
#include <malloc.h>
#define MAXVEX 100				//图中最大顶点个数
#define INF 32767				//表示∞
typedef char VertexType[10];	//定义VertexType为字符串类型
typedef struct vertex
{	int adjvex;					//顶点编号
	VertexType data; 			//顶点的信息
} VType;						//顶点类型
typedef struct graph
{	int n,e;					//n为实际顶点数,e为实际边数
	VType vexs[MAXVEX];			//顶点集合
	int edges[MAXVEX][MAXVEX];	//边的集合
} MatGraph;						//图的邻接矩阵类型
void CreateGraph(MatGraph &g,int A[][MAXVEX],int n,int e)
//由邻接矩阵数组A、顶点数n和边数e建立图G的邻接矩阵存储结构
{
	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			g.edges[i][j]=A[i][j];
}
void DestroyGraph(MatGraph g)		//销毁图
{
}
void DispGraph(MatGraph g)			//显示图G的结构
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]<INF)
				printf("%4d",g.edges[i][j]);
			else
				printf("%4s","∞");
		printf("\n");
	}
}
void AddaVex(MatGraph &g)		//添加顶点
{
	g.n++;
}
int InsertEdge1(MatGraph &g,int u,int v,int w)		//无向图插入边
{
	if (u<0 || u>=g.n || v<0 || v>=g.n)
		return 0;			//顶点编号错误返回0
	g.edges[u][v]=w;
	g.edges[v][u]=w;
	g.e++;
	return 1;
}
int InsertEdge2(MatGraph &g,int u,int v,int w)		//有向图插入边
{
	if (u<0 || u>=g.n || v<0 || v>=g.n)
		return 0;			//顶点编号错误返回0
	g.edges[u][v]=w;
	g.e++;
	return 1;
}
int Degree1(MatGraph g,int v)	//求无向图G中顶点v的度
{
	int i,d=0;
	if (v<0 || v>=g.n)
		return -1;				//顶点编号错误返回-1
	for (i=0;i<g.n;i++)
		if (g.edges[v][i]>0 && g.edges[v][i]<INF)
			d++;				//统计第v行既不为0也不为∞的边数即度
	return d;
}
int Degree2(MatGraph g,int v)	//求有向图G中顶点v的度
{
	int i,d1=0,d2=0,d;
	if (v<0 || v>=g.n)
		return -1;				//顶点编号错误返回-1
	for (i=0;i<g.n;i++)
		if (g.edges[v][i]>0 && g.edges[v][i]<INF)
			d1++;				//统计第v行既不为0也不为∞的边数即出度
	for (i=0;i<g.n;i++)
		if (g.edges[i][v]>0 && g.edges[i][v]<INF)
			d2++;				//统计第v列既不为0也不为∞的边数即入度
	d=d1+d2;
	return d;
}