#include "MatGraph.cpp"					//�����ڽӾ���Ļ������㺯��
void Floyd(MatGraph g,int A[][MAXVEX])	//��ÿ�Զ���֮������·��
{	int i,j,k;
	for (i=0;i<g.n;i++)					//������A��path�ó�ֵ����A-1[i][j]
		for (j=0;j<g.n;j++) 
			A[i][j]=g.edges[i][j];
	for (k=0;k<g.n;k++)					//��Ak[i][j]
	{	for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])	//�ҵ�����·��
					A[i][j]=A[i][k]+A[k][j];	//�޸�·������
	}
	printf("A:\n");
	for (int i1=0;i1<g.n;i1++)
	{
		for (int j1=0;j1<g.n;j1++)
			if (A[i1][j1]==INF)
				printf("��");
			else
				printf("%4d",A[i1][j1]);
		printf("\n");
	}
}
int FindVex(int A[][MAXVEX],int n)	//�����ҵ�����Ѵ�ׯ���
{	int B[MAXVEX];
	int i,j,minv;
	for (i=0;i<n;i++)		//���ׯi���������д�ׯ���·������֮��B[i]
	{	B[i]=0;
		for (j=0;j<n;j++)
			B[i]+=A[i][j];
	}
	minv=0;					//��B��������С��B[minv]
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
	int A[MAXVEX][MAXVEX];				//����A����
	int n=5,e=6;
	int B[MAXVEX][MAXVEX]={
		{0,12,9,INF,3},
		{12,0,6,INF,INF},
		{9,6,0,4,INF},
		{INF,INF,4,0,6},
		{3,INF,INF,6,0}};
	CreateGraph(g,B,n,e);				//����ͼ7.32���ڽӾ���
	printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(g);
	Floyd(g,A);
	printf("��Ѵ�ׯ���Ϊ%d\n",FindVex(A,g.n));
	DestroyGraph(g);
}
