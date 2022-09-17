#include <stdio.h>
#include "MatGraph.cpp"
//----------Dijkstra----------------------------------
void DispAllPath(MatGraph g,int dist[],int path[],int S[],int v);
void Dispdistpath(int dist[],int path[],int n)	//���dist�����path����
{
	int i;
	printf("\tdist\t\t\tpath\n");
	for (i=0;i<n;i++)
		if (dist[i]==INF)
			printf("%3s","��");
		else
			printf("%3d",dist[i]);
	printf("\t");
	for (i=0;i<n;i++)
		printf("%3d",path[i]);
	printf("\n");
}
void Dijkstra(MatGraph g,int v)		//���v��������������·��
{	int dist[MAXVEX];				//����dist����
	int path[MAXVEX];				//����path����
	int S[MAXVEX];					//����S����
	int mindis,i,j,u=0;
	for (i=0;i<g.n;i++)
	{	dist[i]=g.edges[v][i];		//�����ʼ��
		S[i]=0;						//S[]�ÿ�
		if (g.edges[v][i]<INF)		//·����ʼ��
			path[i]=v;				//����v������i�б�ʱ���ö���i��ǰһ������Ϊv
		else
			path[i]=-1;				//����v������iû��ʱ���ö���i��ǰһ������Ϊ-1
	}
	Dispdistpath(dist,path,g.n);	//���dist��ʼֵ��path��ʼֵ
	S[v]=1;							//Դ����v����s��
	for (i=0;i<g.n-1;i++)			//ѭ����S�����n-1������
	{	mindis=INF;					//mindis����С���ȳ�ֵ
		for (j=0;j<g.n;j++)			//ѡȡ����s���Ҿ�����С����Ķ���u
			if (S[j]==0 && dist[j]<mindis) 
			{	u=j;
				mindis=dist[j];
			}
		printf("������%d����S��\n",u);
		S[u]=1;						//����u����s��
		for (j=0;j<g.n;j++)			//�޸Ĳ���s�еĶ���ľ���
			if (S[j]==0)
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
				{	dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}
		Dispdistpath(dist,path,g.n);	//���distֵ��pathֵ
	}
	DispAllPath(g,dist,path,S,v);		//����������·��������
}
void DispAllPath(MatGraph g,int dist[],int path[],int S[],int v) //����Ӷ���v�������������·��
{
	int i,j,k,count=0;
	int apath[MAXVEX],d;				//���һ�����·��(����)���䶥�����
	for (i=0;i<g.n;i++)
		if (path[i]!=-1)
			count++;
	if (count==1)						//path��ֻ��һ����Ϊ-1ʱ��ʾû��·��
	{	printf("��ָ���Ķ��㵽�������㶼û��·��!!!\n");
		return;
	}
	for (i=0;i<g.n;i++)					//ѭ������Ӷ���v��i��·��
		if (S[i]==1 && i!=v)
		{
			printf("  ��%d��%d���·������Ϊ:%d\t·��:",v,i,dist[i]);
			d=0; apath[d]=i;			//���·���ϵ��յ�
			k=path[i];
			if (k==-1)					//û��·�������
				printf("��·��\n");
			else						//����·��ʱ�����·��
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//���·���ϵ����
				printf("%d",apath[d]);	//��������
				for (j=d-1;j>=0;j--)	//�������������
					printf("��%d",apath[j]);
				printf("\n");
			}
		}
}
//----------Floyd----------------------------------
void DispAllPath(MatGraph g,int A[][MAXVEX],int path[][MAXVEX]);	//������е����·���ͳ���
void DispApath(int A[][MAXVEX],int path[][MAXVEX],int n,int k)		//���A��path����
{
	int i,j;
	printf("\tA[%d]\t\t\t\tpath[%d]\n",k,k);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (A[i][j]==INF)
				printf("%4s","��");
			else
				printf("%4d",A[i][j]);
		printf("\t");
		for (j=0;j<n;j++)
			printf("%3d",path[i][j]);
		printf("\n");
	}
}
void Floyd(MatGraph g)					//��ÿ�Զ���֮������·��
{	int A[MAXVEX][MAXVEX];				//����A����
	int path[MAXVEX][MAXVEX];			//����path����
	int i,j,k;
	for (i=0;i<g.n;i++)					//������A��path�ó�ֵ����A-1[i][j]
		for (j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;
			else
				path[i][j]=-1;
		}
	DispApath(A,path,g.n,-1);				//�����ʼA�ͳ�ʼpath
	for (k=0;k<g.n;k++)						//��Ak[i][j]
	{	for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])	//�ҵ�����·��
				{	A[i][j]=A[i][k]+A[k][j];	//�޸�·������
					path[i][j]=path[k][j];		//�޸����·��Ϊ��������k
				}
		DispApath(A,path,g.n,k);				//���A��path
	}	
	DispAllPath(g,A,path);						//������·���ͳ���
}
void DispAllPath(MatGraph g,int A[][MAXVEX],int path[][MAXVEX])	//������е����·���ͳ���
{
	int i,j,k,s;
	int apath[MAXVEX],d;						//���һ�����·���м䶥��(����)���䶥�����
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{
			if (A[i][j]!=INF && i!=j)			//������i��j֮�����·��
			{
				printf("  ����%d��%d�����·������:%d\t·��:",i,j,A[i][j]);
				k=path[i][j];
				d=0; apath[d]=j;				//·��������յ�
				while (k!=-1 && k!=i)			//·��������м��
				{
					d++; apath[d]=k;
					k=path[i][k];
				}
				d++; apath[d]=i;				//·����������
				printf("%d",apath[d]);			//������
				for (s=d-1;s>=0;s--)			//���·���ϵ��м䶥��
					printf("��%d",apath[s]);
				printf("\n");
			}
		}
}
