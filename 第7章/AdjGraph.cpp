#include <stdio.h>
#include <malloc.h>
#define MAXVEX 100				//ͼ����󶥵����
#define INF 32767				//��ʾ��
typedef char VertexType[10];	//����VertexTypeΪ�ַ�������
typedef struct edgenode
{	int adjvex;					//�ڽӵ����
	int weight;					//�ߵ�Ȩֵ
	struct edgenode *nextarc;	//��һ���ߵĶ���
} ArcNode;						//ÿ�����㽨���ĵ������б߽�������
typedef struct vexnode
{	VertexType data;			//������Ϣ
	ArcNode *firstarc; 			//ָ���һ���߽��
} VHeadNode;					//�������ͷ�������
typedef struct 
{	int n,e;					//nΪʵ�ʶ�����,eΪʵ�ʱ���
	VHeadNode adjlist[MAXVEX];	//������ͷ�������
} AdjGraph;						//ͼ���ڽӱ�����

void CreateGraph(AdjGraph *&G,int A[][MAXVEX],int n,int e)
//���ڽӾ�������A��������n�ͱ���e����ͼG���ڽӾ���洢�ṹ
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	G->n=n; G->e=e;
	for (i=0;i<G->n;i++)			//�ڽӱ�������ͷ����ָ�����ÿ�
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<G->n;i++)				//���A��ÿ��Ԫ��
		for (j=G->n-1;j>=0;j--)
			if (A[i][j]>0 && A[i][j]<INF)		//����һ����
			{
				p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ�����*p
				p->adjvex=j;
				p->weight=A[i][j]; 
				p->nextarc=G->adjlist[i].firstarc;		//����ͷ�巨����*p
				G->adjlist[i].firstarc=p;
			}
}
void DestroyGraph(AdjGraph *&G)	//����ͼ
{
	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)		//�ͷű߽����ռ�ռ�
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
	free(G);				//�ͷ�G��ָ���ڴ�ռ�	
}
void DispGraph(AdjGraph *G)	//���ͼ���ڽӱ�
{
	ArcNode *p;
	int i;
	for (i=0;i<G->n;i++)
	{
		printf("  [%2d]",i);
		p=G->adjlist[i].firstarc;	//pָ���һ���ڽӵ�	
		if (p!=NULL)
			printf(" ��");
		while (p!=NULL)
		{
			printf(" %d(%d)",p->adjvex,p->weight);
			p=p->nextarc;			//p������һ���ڽӵ�
		}
		printf("\n");
	}
}
int Degree1(AdjGraph *G,int v)	//������ͼG�ж���v�Ķ�
{
	int d=0;
	ArcNode *p;
	if (v<0 || v>=G->n)
		return -1;				//�����Ŵ��󷵻�-1
	p=G->adjlist[v].firstarc;
	while (p!=NULL)				//ͳ��v����ĵ������б߽���������
	{
		d++;
		p=p->nextarc;
	}
	return d;
}
int Degree2(AdjGraph *G,int v)	//������ͼG�ж���v�Ķ�
{
	int i,d1=0,d2=0,d;
	ArcNode *p;
	if (v<0 || v>=G->n)
		return -1;				//�����Ŵ��󷵻�-1
	p=G->adjlist[v].firstarc;
	while (p!=NULL)				//ͳ��v����ĵ������б߽�����������
	{
		d1++;
		p=p->nextarc;
	}
	for (i=0;i<G->n;i++)		//ͳ�Ʊ߽����adjvexΪv�ĸ��������
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