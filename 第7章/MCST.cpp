#include <stdio.h>
#include "MatGraph.cpp"
#define MAXE 100						//ͼ�����ı���
//-----------Prim----------------------------------------------------
void Prim(MatGraph g,int v)				//�����õ���С���������б�
{
	int lowcost[MAXVEX];				//��������lowcost
	int closest[MAXVEX];				//��������closest
	int min,i,j,k;
	for (i=0;i<g.n;i++)					//��lowcost[]��closest[]�ó�ֵ
	{	lowcost[i]=g.edges[v][i];
		closest[i]=v;
	}
	for (i=1;i<g.n;i++)					//����n-1����
	{	min=INF;k=-1;
		for (j=0;j<g.n;j++)				//��(V-U)���ҳ���U����Ķ���k
			if (lowcost[j]!=0 && lowcost[j]<min)
			{	min=lowcost[j];
				k=j;					//k��¼�������ı��
			}
		printf("  ��(%d,%d),ȨֵΪ%d\n",closest[k],k,min);
		lowcost[k]=0;					//���k�Ѿ�����U
		for (j=0;j<g.n;j++)				//��������lowcost��closest
		if (lowcost[j]!=0 && g.edges[k][j]<lowcost[j])
		{	lowcost[j]=g.edges[k][j];
			closest[j]=k;
		}
	}
}
//-----------Kruskal----------------------------------------------------
typedef struct
{	int u;							//�ߵ���ʼ����
	int v;							//�ߵ���ֹ����
	int w;							//�ߵ�Ȩֵ
} Edge;								//������Ԫ������
void SortEdge(Edge E[],int e)		//��E���鰴Ȩֵ��������
{
	int i,j,k=0;
	Edge temp;
	for (i=1;i<e;i++)
	{	temp=E[i];
		j=i-1;						//����������������E[0..i-1]����E[i]�Ĳ���λ��
		while (j>=0 && temp.w<E[j].w)
		{	E[j+1]=E[j];			//��Ȩֵ����E[i].w�ļ�¼����
			j--;
		}
		E[j+1]=temp;				//��j+1������E[i]
	}
}
void Kruskal(MatGraph g)			//�����õ���С���������б�
{
	int i,j,u1,v1,sn1,sn2,k;
	int vset[MAXVEX];				//��������vset
	Edge E[MAXE];					//����������бߵ�����E
	k=0;							//E������±��0��ʼ��
	for (i=0;i<g.n;i++)				//��ͼ���ڽӾ���g�����ı߼�����E
		for (j=0;j<=i;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
			{	E[k].u=i;
				E[k].v=j;
				E[k].w=g.edges[i][j];
				k++;				//�ۼƱ���
			}
	SortEdge(E,k);					//����ֱ�Ӳ��������E���鰴Ȩֵ��������
	for (i=0;i<g.n;i++) vset[i]=i;	//��ʼ����������
	k=1;							//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
	j=0;							//E�бߵ��±�,��ֵΪ0
	while (k<g.n)					//���ɵı���С��nʱѭ��
	{	u1=E[j].u; v1=E[j].v;		//ȡһ���ߵ�ͷβ����
		sn1=vset[u1];
		sn2=vset[v1];				//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)				//���������ڲ�ͬ�ļ���,�ñ�����С��������һ����
		{
			printf("  ��(%d,%d),ȨֵΪ%d\n",u1,v1,E[j].w);
			k++;					//���ɱ�����1
			for (i=0;i<g.n;i++)		//��������ͳһ���
				if (vset[i]==sn2)	//���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i]=sn1;
		}
		j++;						//ɨ����һ����
	}
}
