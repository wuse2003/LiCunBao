#include "AdjGraph.cpp"					//�����ڽӱ�Ļ������㺯��
int visited[MAXVEX];					//ȫ������
void FindaPath(AdjGraph *G,int u,int v,int path[],int d)
{	ArcNode *p;
	int w,i;
	visited[u]=1;
	d++;
	path[d]=u;							//����u���뵽·����
	if (u==v)							//�ҵ�һ��·��
	{	for (i=0;i<=d;i++)				//����ҵ�һ��·��������
			printf("%d ",path[i]);
		printf("\n");
		return;
	}
	p=G->adjlist[u].firstarc;			//pָ��u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;					//���ڵ�ı��Ϊw
		if (visited[w]==0)
			FindaPath(G,w,v,path,d);	//�ݹ����
		p=p->nextarc;					//pָ����һ�����ڵ�
	}
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
	int u=0,v=4,d=-1;
	int path[MAXVEX];
	printf("�Ӷ���%d��%d��һ��·��:",u,v);
	FindaPath(G,u,v,path,d);
}
