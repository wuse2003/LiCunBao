#include <stdio.h>
#include <malloc.h>
#define MAXVEX 100				//ͼ����󶥵����
#define INF 32767				//��ʾ��
typedef char VertexType[10];	//����VertexTypeΪ�ַ�������
typedef struct vertex
{	int adjvex;					//������
	VertexType data; 			//�������Ϣ
} VType;						//��������
typedef struct graph
{	int n,e;					//nΪʵ�ʶ�����,eΪʵ�ʱ���
	VType vexs[MAXVEX];			//���㼯��
	int edges[MAXVEX][MAXVEX];	//�ߵļ���
} MatGraph;						//ͼ���ڽӾ�������
void CreateGraph(MatGraph &g,int A[][MAXVEX],int n,int e)
//���ڽӾ�������A��������n�ͱ���e����ͼG���ڽӾ���洢�ṹ
{
	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			g.edges[i][j]=A[i][j];
}
void DestroyGraph(MatGraph g)		//����ͼ
{
}
void DispGraph(MatGraph g)			//��ʾͼG�Ľṹ
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]<INF)
				printf("%4d",g.edges[i][j]);
			else
				printf("%4s","��");
		printf("\n");
	}
}
void AddaVex(MatGraph &g)		//��Ӷ���
{
	g.n++;
}
int InsertEdge1(MatGraph &g,int u,int v,int w)		//����ͼ�����
{
	if (u<0 || u>=g.n || v<0 || v>=g.n)
		return 0;			//�����Ŵ��󷵻�0
	g.edges[u][v]=w;
	g.edges[v][u]=w;
	g.e++;
	return 1;
}
int InsertEdge2(MatGraph &g,int u,int v,int w)		//����ͼ�����
{
	if (u<0 || u>=g.n || v<0 || v>=g.n)
		return 0;			//�����Ŵ��󷵻�0
	g.edges[u][v]=w;
	g.e++;
	return 1;
}
int Degree1(MatGraph g,int v)	//������ͼG�ж���v�Ķ�
{
	int i,d=0;
	if (v<0 || v>=g.n)
		return -1;				//�����Ŵ��󷵻�-1
	for (i=0;i<g.n;i++)
		if (g.edges[v][i]>0 && g.edges[v][i]<INF)
			d++;				//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�޵ı�������
	return d;
}
int Degree2(MatGraph g,int v)	//������ͼG�ж���v�Ķ�
{
	int i,d1=0,d2=0,d;
	if (v<0 || v>=g.n)
		return -1;				//�����Ŵ��󷵻�-1
	for (i=0;i<g.n;i++)
		if (g.edges[v][i]>0 && g.edges[v][i]<INF)
			d1++;				//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�޵ı���������
	for (i=0;i<g.n;i++)
		if (g.edges[i][v]>0 && g.edges[i][v]<INF)
			d2++;				//ͳ�Ƶ�v�мȲ�Ϊ0Ҳ��Ϊ�޵ı��������
	d=d1+d2;
	return d;
}