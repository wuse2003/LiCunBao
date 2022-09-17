#include "AdjGraph.cpp"
#include "MatGraph.cpp"
int visited[MAXVEX];
void DFS(AdjGraph *G,int v)		//���ڽӱ�G�Ӷ���v��ʼ����������ȱ���
{	int w; ArcNode *p;
	printf("%d ",v);			//����v����
	visited[v]=1;
	p=G->adjlist[v].firstarc;	//��v�ĵ�һ���ڽӵ�
	while (p!=NULL)				//��v�������ڽӵ�
	{	w= p->adjvex;			//����v�����ڵ�w
		if (visited[w]==0)		//����wδ���ʹ�
			DFS(G,w);			//��w����������ȱ���
		p=p->nextarc;				//��v����һ���ڽӵ�
	}
}
void DFS1(MatGraph g,int v)	//�ڽӾ����DFS�㷨
{  int w;
   printf("%d ",v);		//��������ʶ���ı��
   visited[v]=1;			//���ѷ��ʱ��
   for (w=0;w<g.n;w++)		//�Ҷ���v���������ڵ�
     if (g.edges[v][w]!=0 && g.edges[v][w]!=INF 
		&& visited[w]==0)
	DFS1(g,w);		//�Ҷ���v��δ���ʹ������ڵ�w
}
void BFS(AdjGraph *G,int v)				//���ڽӱ�G�Ӷ���v��ʼ���й�����ȱ���
{	int i,w,visited[MAXVEX];
	int Qu[MAXVEX],front=0,rear=0;		//����һ��ѭ������Qu
	ArcNode *p;
	for (i=0;i<G->n;i++) visited[i]=0;	//visited�����ó�ֵ0
	printf("%d ",v);					//���ʳ�ʼ����
	visited[v]=1;
	rear=(rear=1)%MAXVEX;
	Qu[rear]=v;							//��ʼ����v����
	while (front!=rear)					//�Ӳ�Ϊ��ʱѭ��
	{	front=(front+1) % MAXVEX;
		w=Qu[front];					//���Ӷ���w
		p=G->adjlist[w].firstarc;		//����w�ĵ�һ���ڽӵ�
		while (p!=NULL)					//����w�������ڽӵ�
		{	if (visited[p->adjvex]==0)	//δ���ʹ������֮
			{	printf("%d ",p->adjvex);//���ʸõ㲢����
				visited[p->adjvex]=1;
				rear=(rear+1) % MAXVEX;
				Qu[rear]=p->adjvex;
			}
			p=p->nextarc;				//����w����һ���ڽӵ�
		}
	}
}
void BFS1(MatGraph g,int v)			//�ڽӾ����BFS�㷨
{	int i,w,visited[MAXVEX];
	int Qu[MAXVEX],front=0,rear=0;		//����һ��ѭ������Qu
	for (i=0;i<g.n;i++) visited[i]=0;	//visited�����ó�ֵ0
	printf("%d ",v);					//���ʳ�ʼ����
	visited[v]=1;
	rear=(rear=1)%MAXVEX;
	Qu[rear]=v;							//��ʼ����v����
	while (front!=rear)					//�Ӳ�Ϊ��ʱѭ��
	{	front=(front+1) % MAXVEX;
		w=Qu[front];					//���Ӷ���w
		for (i=0;i<g.n;i++)				//���붥��w���ڵĶ���
			if (g.edges[w][i]!=0 && g.edges[w][i]!=INF && visited[i]==0)
			{
				printf("%d ",i);		//����w��δ�����ʵ����ڶ���i
				visited[i]=1;			//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXVEX;
				Qu[rear]=i;				//�ö������
			}
	}
}

