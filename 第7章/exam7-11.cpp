#include "AdjGraph.cpp"			//�����ڽӱ�Ļ������㺯��
int visited[MAXVEX];
void FindallPath(AdjGraph *G,int u,int v,int path[],int d)
{	ArcNode *p;
	int w,i;
	visited[u]=1;
	d++; path[d]=u;						//����u���뵽·����
	if (u==v && d>=1)					//�ҵ�һ��·��
	{	for (i=0;i<=d;i++)				//����ҵ�һ��·��������
			printf(" %d",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;			//pָ��u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;					//���ڵ�ı��Ϊw
		if (visited[w]==0)
			FindallPath(G,w,v,path,d);	//�ݹ����
		p=p->nextarc;					//pָ����һ�����ڵ�
	}
	visited[u]=0;						//���������м�·��
}
void main()
{
	AdjGraph *G;
	int n=5,e=6,i;
	int path[MAXVEX],d=-1;
	int u=0,v=4;
	int A[MAXVEX][MAXVEX]={
		{0,1,0,1,0},
		{1,0,1,0,0},
		{0,1,0,1,1},
		{1,0,1,0,1},
		{0,0,1,1,0}};
	CreateGraph(G,A,n,e);				//����ͼ7.8(a)���ڽӱ�
	for (i=0;i<G->n;i++)
		visited[i]=0;
	printf("�Ӷ���%d��%d������·��:\n",u,v);
	FindallPath(G,u,v,path,d);
	DestroyGraph(G);
}

