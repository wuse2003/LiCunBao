#include "AdjGraph.cpp"			//�����ڽӱ�Ļ������㺯��
int visited[MAXVEX];

void ShortPath(AdjGraph *G,int u,int v)
{
	struct QUEUE						//��ѭ����������
	{	int data;						//������
		int parent;						//ǰһ�������λ��
	} qu[MAXVEX];						//����һ����ѭ������qu
	int front=-1,rear=-1;				//���е�ͷ��βָ��
	ArcNode *p; int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;	//���ʱ���ó�ֵ0
	rear++;								//����u����
	qu[rear].data=u; qu[rear].parent=-1;//����˫����Ϊ-1
	visited[u]=1;
	while (front!=rear)					//�Ӳ���ѭ��
	{	front++;						//���Ӷ���w
		w=qu[front].data;
		if (w==v)						//�ҵ�vʱ���·��֮�沢�˳�
		{	i=front;					//ͨ�����������·��
			while (qu[i].parent!=-1)
			{	printf("%d ",qu[i].data);
				i=qu[i].parent;
			}
			printf("%d\n",qu[i].data);
			break;						//�ҵ�·�����˳�whileѭ��
		}
		p=G->adjlist[w].firstarc;		//��w�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)
			{	visited[p->adjvex]=1;
				rear++;					//��w��δ���ʹ����ڽӵ����
				qu[rear].data=p->adjvex;
				qu[rear].parent=front;	//���Ӷ����˫����Ϊfront
			}
			p=p->nextarc;				//��w����һ���ڽӵ�
		}
	}
}
void main()
{
	AdjGraph *G;
	int n=5,e=6,i;
	int u=0,v=4;
	int A[MAXVEX][MAXVEX]={
		{0,1,0,1,0},
		{1,0,1,0,0},
		{0,1,0,1,1},
		{1,0,1,0,1},
		{0,0,1,1,0}};
	CreateGraph(G,A,n,e);	//����ͼ7.8(a)���ڽӱ�
	for (i=0;i<G->n;i++)
		visited[i]=0;
	printf("�Ӷ���%d��%d�������·��:",u,v);
	ShortPath(G,u,v);
	DestroyGraph(G);
}

