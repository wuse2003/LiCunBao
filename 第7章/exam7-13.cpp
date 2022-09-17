#include "MatGraph.cpp"					//包含邻接矩阵的基本运算函数
void Floyd(MatGraph g,int A[][MAXVEX])	//求每对顶点之间的最短路径
{	int i,j,k;
	for (i=0;i<g.n;i++)					//给数组A和path置初值即求A-1[i][j]
		for (j=0;j<g.n;j++) 
			A[i][j]=g.edges[i][j];
	for (k=0;k<g.n;k++)					//求Ak[i][j]
	{	for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])	//找到更短路径
					A[i][j]=A[i][k]+A[k][j];	//修改路径长度
	}
	printf("A:\n");
	for (int i1=0;i1<g.n;i1++)
	{
		for (int j1=0;j1<g.n;j1++)
			if (A[i1][j1]==INF)
				printf("∞");
			else
				printf("%4d",A[i1][j1]);
		printf("\n");
	}
}
int FindVex(int A[][MAXVEX],int n)	//返回找到的最佳村庄编号
{	int B[MAXVEX];
	int i,j,minv;
	for (i=0;i<n;i++)		//求村庄i到其他所有村庄最短路径长度之和B[i]
	{	B[i]=0;
		for (j=0;j<n;j++)
			B[i]+=A[i][j];
	}
	minv=0;					//求B数组中最小的B[minv]
	for (i=1;i<n;i++)
		if (B[i]<B[minv])
			minv=i;
	printf("B:\n");
	for (int i1=0;i1<n;i1++)
		printf("%4d",B[i1]);
	printf("\n");
	return minv;
}
void main()
{	MatGraph g;
	int A[MAXVEX][MAXVEX];				//建立A数组
	int n=5,e=6;
	int B[MAXVEX][MAXVEX]={
		{0,12,9,INF,3},
		{12,0,6,INF,INF},
		{9,6,0,4,INF},
		{INF,INF,4,0,6},
		{3,INF,INF,6,0}};
	CreateGraph(g,B,n,e);				//建立图7.32的邻接矩阵
	printf("图G的存储结构:\n"); DispGraph(g);
	Floyd(g,A);
	printf("最佳村庄编号为%d\n",FindVex(A,g.n));
	DestroyGraph(g);
}
