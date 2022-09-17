#include "AdjGraph.cpp"			//�����ڽӱ�Ļ������㺯��
int visited[MAXVEX];
int HasaPath(AdjGraph *G,int u,int v)
{
	ArcNode *p;
	int w;
	visited[u]=1;
	p=G->adjlist[u].firstarc;		//pָ��u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;				//�ڽӵ�ı��Ϊw
		if (w==v)					//�ҵ�����v�󷵻�1
			return 1;
		if (visited[w]==0)			//������wû�з��ʹ�
		{
			if (HasaPath(G,w,v))	//��w��������������ȱ���
				return true;		//����w�����ҵ�����v����1
		}
		p=p->nextarc;				//pָ����һ���ڽӵ�
	}
	return 0;						//û���ҵ�����v������0
}
int HasaPath1(AdjGraph *G,int u,int v)
{
	ArcNode *p;
	int w;
	if (u==v) return 1;				//�ҵ�����v�󷵻�1
	visited[u]=1;
	p=G->adjlist[u].firstarc;		//pָ��u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;				//�ڽӵ�ı��Ϊw
		if (visited[w]==0)			//������wû�з��ʹ�
		{
			if (HasaPath1(G,w,v))	//��w��������������ȱ���
				return true;		//����w�����ҵ�����v����1
		}
		p=p->nextarc;				//pָ����һ���ڽӵ�
	}
	return 0;						//û���ҵ�����v������0
}
void main()
{
	AdjGraph *G;
	int n=5,e=6,i;
	int A[MAXVEX][MAXVEX]={
		{0,1,0,1,0},
		{1,0,1,0,0},
		{0,1,0,1,1},
		{1,0,1,0,1},
		{0,0,1,1,0}};
	CreateGraph(G,A,n,e);		//����ͼ7.8(a)���ڽӱ�
	for (i=0;i<G->n;i++)
		visited[i]=0;
	int u=0,v=4;
	if (HasaPath1(G,u,v))
		printf("����%d��%d�м�·��\n",u,v);
	else
		printf("����%d��%dû�м�·��\n",u,v);
	DestroyGraph(G);
}

