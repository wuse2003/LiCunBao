#include <stdio.h>
#include "MatGraph.cpp"
#define MAXE 100						//图中最多的边数
//-----------Prim----------------------------------------------------
void Prim(MatGraph g,int v)				//输出求得的最小生树的所有边
{
	int lowcost[MAXVEX];				//建立数组lowcost
	int closest[MAXVEX];				//建立数组closest
	int min,i,j,k;
	for (i=0;i<g.n;i++)					//给lowcost[]和closest[]置初值
	{	lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	for (i=1;i<g.n;i++)					//构造n-1条边
	{	min=INF;k=-1;
		for (j=0;j<g.n;j++)				//在(V-U)中找出离U最近的顶点k
			if (lowcost[j]!=0 && lowcost[j]<min)
			{	min=lowcost[j];
				k=j;					//k记录最近顶点的编号
			}
		printf("  边(%d,%d),权值为%d\n",closest[k],k,min);
		lowcost[k]=0;					//标记k已经加入U
		for (j=0;j<g.n;j++)				//修正数组lowcost和closest
		if (lowcost[j]!=0 && g.edges[k][j]<lowcost[j])
		{	lowcost[j]=g.edges[k][j];
			closest[j]=k;
		}
	}
}
//-----------Kruskal----------------------------------------------------
typedef struct
{	int u;							//边的起始顶点
	int v;							//边的终止顶点
	int w;							//边的权值
} Edge;								//边数组元素类型
void SortEdge(Edge E[],int e)		//对E数组按权值递增排序
{
	int i,j,k=0;
	Edge temp;
	for (i=1;i<e;i++)
	{	temp=E[i];
		j=i-1;						//从右向左在有序区E[0..i-1]中找E[i]的插入位置
		while (j>=0 && temp.w<E[j].w)
		{	E[j+1]=E[j];			//将权值大于E[i].w的记录后移
			j--;
		}
		E[j+1]=temp;				//在j+1处插入E[i]
	}
}
void Kruskal(MatGraph g)			//输出求得的最小生树的所有边
{
	int i,j,u1,v1,sn1,sn2,k;
	int vset[MAXVEX];				//建立数组vset
	Edge E[MAXE];					//建立存放所有边的数组E
	k=0;							//E数组的下标从0开始计
	for (i=0;i<g.n;i++)				//由图的邻接矩阵g产生的边集数组E
		for (j=0;j<=i;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
			{	E[k].u=i;
				E[k].v=j;
				E[k].w=g.edges[i][j];
				k++;				//累计边数
			}
	SortEdge(E,k);					//采用直接插入排序对E数组按权值递增排序
	for (i=0;i<g.n;i++) vset[i]=i;	//初始化辅助数组
	k=1;							//k表示当前构造生成树的第几条边,初值为1
	j=0;							//E中边的下标,初值为0
	while (k<g.n)					//生成的边数小于n时循环
	{	u1=E[j].u; v1=E[j].v;		//取一条边的头尾顶点
		sn1=vset[u1];
		sn2=vset[v1];				//分别得到两个顶点所属的集合编号
		if (sn1!=sn2)				//两顶点属于不同的集合,该边是最小生成树的一条边
		{
			printf("  边(%d,%d),权值为%d\n",u1,v1,E[j].w);
			k++;					//生成边数增1
			for (i=0;i<g.n;i++)		//两个集合统一编号
				if (vset[i]==sn2)	//集合编号为sn2的改为sn1
					vset[i]=sn1;
		}
		j++;						//扫描下一条边
	}
}
