#include "AdjGraph.cpp"			//�����ڽӱ�Ļ������㺯��
int visited[MAXVEX];
void DFS(AdjGraph *G,int v)		//������ȱ����㷨
{	int w; ArcNode *p;
	printf("%d ",v);			//����v����
	visited[v]=1;
	p=G->adjlist[v].firstarc;	//��v�ĵ�һ���ڽӵ�
	while (p!=NULL)				//��v�������ڽӵ�
	{	w= p->adjvex;			//����v�����ڵ�w
		if (visited[w]==0)		//����wδ���ʹ�
			DFS(G,w);			//��w����������ȱ���
		p=p->nextarc;			//��v����һ���ڽӵ�
	}
}
int Connect(AdjGraph *G)	//�ж�����ͼG����ͨ��
{	int i,flag=1;
	DFS(G,0);				//����DFS�㷨,�Ӷ���0��ʼ������ȱ���
	for (i=0;i<G->n;i++)
		if (visited[i]==0)
		{	flag=0;
			break;
		}
	return flag;
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
	CreateGraph(G,A,n,e);	//����һ��ͼ7.1(a)���ڽӱ�
	for (i=0;i<G->n;i++)
		visited[i]=0;
	if (Connect(G))
		printf("\nͼG����ͨͼ\n");
	else
		printf("\nͼG�Ƿ���ͨͼ\n");
	DestroyGraph(G);
}

