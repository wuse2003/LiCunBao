#include <stdio.h>
#include "MatGraph.cpp"
//----------Dijkstra----------------------------------
void DispAllPath(MatGraph g,int dist[],int path[],int S[],int v);
void Dispdistpath(int dist[],int path[],int n)	//输出dist数组和path数组
{
	int i;
	printf("\tdist\t\t\tpath\n");
	for (i=0;i<n;i++)
		if (dist[i]==INF)
			printf("%3s","∞");
		else
			printf("%3d",dist[i]);
	printf("\t");
	for (i=0;i<n;i++)
		printf("%3d",path[i]);
	printf("\n");
}
void Dijkstra(MatGraph g,int v)		//求从v到其他顶点的最短路径
{	int dist[MAXVEX];				//建立dist数组
	int path[MAXVEX];				//建立path数组
	int S[MAXVEX];					//建立S数组
	int mindis,i,j,u=0;
	for (i=0;i<g.n;i++)
	{	dist[i]=g.edges[v][i];		//距离初始化
		S[i]=0;						//S[]置空
		if (g.edges[v][i]<INF)		//路径初始化
			path[i]=v;				//顶点v到顶点i有边时，置顶点i的前一个顶点为v
		else
			path[i]=-1;				//顶点v到顶点i没边时，置顶点i的前一个顶点为-1
	}
	Dispdistpath(dist,path,g.n);	//输出dist初始值和path初始值
	S[v]=1;							//源点编号v放入s中
	for (i=0;i<g.n-1;i++)			//循环向S中添加n-1个顶点
	{	mindis=INF;					//mindis置最小长度初值
		for (j=0;j<g.n;j++)			//选取不在s中且具有最小距离的顶点u
			if (S[j]==0 && dist[j]<mindis) 
			{	u=j;
				mindis=dist[j];
			}
		printf("将顶点%d加入S中\n",u);
		S[u]=1;						//顶点u加入s中
		for (j=0;j<g.n;j++)			//修改不在s中的顶点的距离
			if (S[j]==0)
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
				{	dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}
		Dispdistpath(dist,path,g.n);	//输出dist值和path值
	}
	DispAllPath(g,dist,path,S,v);		//输出所有最短路径及长度
}
void DispAllPath(MatGraph g,int dist[],int path[],int S[],int v) //输出从顶点v出发的所有最短路径
{
	int i,j,k,count=0;
	int apath[MAXVEX],d;				//存放一条最短路径(逆向)及其顶点个数
	for (i=0;i<g.n;i++)
		if (path[i]!=-1)
			count++;
	if (count==1)						//path中只有一个不为-1时表示没有路径
	{	printf("从指定的顶点到其他顶点都没有路径!!!\n");
		return;
	}
	for (i=0;i<g.n;i++)					//循环输出从顶点v到i的路径
		if (S[i]==1 && i!=v)
		{
			printf("  从%d到%d最短路径长度为:%d\t路径:",v,i,dist[i]);
			d=0; apath[d]=i;			//添加路径上的终点
			k=path[i];
			if (k==-1)					//没有路径的情况
				printf("无路径\n");
			else						//存在路径时输出该路径
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//添加路径上的起点
				printf("%d",apath[d]);	//先输出起点
				for (j=d-1;j>=0;j--)	//再输出其他顶点
					printf("→%d",apath[j]);
				printf("\n");
			}
		}
}
//----------Floyd----------------------------------
void DispAllPath(MatGraph g,int A[][MAXVEX],int path[][MAXVEX]);	//输出所有的最短路径和长度
void DispApath(int A[][MAXVEX],int path[][MAXVEX],int n,int k)		//输出A和path数组
{
	int i,j;
	printf("\tA[%d]\t\t\t\tpath[%d]\n",k,k);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (A[i][j]==INF)
				printf("%4s","∞");
			else
				printf("%4d",A[i][j]);
		printf("\t");
		for (j=0;j<n;j++)
			printf("%3d",path[i][j]);
		printf("\n");
	}
}
void Floyd(MatGraph g)					//求每对顶点之间的最短路径
{	int A[MAXVEX][MAXVEX];				//建立A数组
	int path[MAXVEX][MAXVEX];			//建立path数组
	int i,j,k;
	for (i=0;i<g.n;i++)					//给数组A和path置初值即求A-1[i][j]
		for (j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;
			else
				path[i][j]=-1;
		}
	DispApath(A,path,g.n,-1);				//输出初始A和初始path
	for (k=0;k<g.n;k++)						//求Ak[i][j]
	{	for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])	//找到更短路径
				{	A[i][j]=A[i][k]+A[k][j];	//修改路径长度
					path[i][j]=path[k][j];		//修改最短路径为经过顶点k
				}
		DispApath(A,path,g.n,k);				//输出A和path
	}	
	DispAllPath(g,A,path);						//输出最短路径和长度
}
void DispAllPath(MatGraph g,int A[][MAXVEX],int path[][MAXVEX])	//输出所有的最短路径和长度
{
	int i,j,k,s;
	int apath[MAXVEX],d;						//存放一条最短路径中间顶点(反向)及其顶点个数
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{
			if (A[i][j]!=INF && i!=j)			//若顶点i和j之间存在路径
			{
				printf("  顶点%d到%d的最短路径长度:%d\t路径:",i,j,A[i][j]);
				k=path[i][j];
				d=0; apath[d]=j;				//路径上添加终点
				while (k!=-1 && k!=i)			//路径上添加中间点
				{
					d++; apath[d]=k;
					k=path[i][k];
				}
				d++; apath[d]=i;				//路径上添加起点
				printf("%d",apath[d]);			//输出起点
				for (s=d-1;s>=0;s--)			//输出路径上的中间顶点
					printf("→%d",apath[s]);
				printf("\n");
			}
		}
}
