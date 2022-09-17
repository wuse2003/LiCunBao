#include "MatGraph.cpp"			//�����ڽӾ���Ļ������㺯��
#include "AdjGraph.cpp"			//�����ڽӱ�Ļ������㺯��
void MatToAdj(MatGraph g,AdjGraph *&G)	//���ڽӾ���gת�����ڽӱ�G
{	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for (i=0;i<g.n;i++)					//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<g.n;i++)					//����ڽӾ�����ÿ��Ԫ��
		for (j=g.n-1;j>=0;j--)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)		//����һ����
			{	p=(ArcNode *)malloc(sizeof(ArcNode));	//����һ���ڵ�*p
				p->adjvex=j;
				p->weight=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		//����ͷ�巨����*p
				G->adjlist[i].firstarc=p;
			}
	G->n=g.n;G->e=g.e;
}
void AdjToMat(AdjGraph *G,MatGraph &g)	//���ڽӱ�Gת�����ڽӾ���g
{
	int i,j;
	ArcNode *p;
	for (i=0;i<G->n;i++)
		for (j=0;j<G->n;j++)
			if (i==j) g.edges[i][i]=0;
			else g.edges[i][j]=INF;
	for (i=0;i<G->n;i++)
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	g.edges[i][p->adjvex]=p->weight;
			p=p->nextarc;
		}
	}
	g.n=G->n; g.e=G->e;
}

void main()
{
	MatGraph g,g1;
	AdjGraph *G;
	int n=5,e=7;
	int A[MAXVEX][MAXVEX]={{0,1,2,6,INF},{INF,0,INF,4,5},{INF,INF,0,INF,3},{INF,INF,INF,0,INF},{INF,INF,INF,7,0}};
	CreateGraph(g,A,n,e);	//����ͼ7.4ͼ���ڽӾ���
	printf("�ڽӾ���g:\n"); DispGraph(g);
	printf("gת��ΪG\n");
	MatToAdj(g,G);
	printf("�ڽӱ�G:\n"); DispGraph(G);
	printf("Gת��Ϊg1\n");
	AdjToMat(G,g1);
	printf("�ڽӾ���g1:\n"); DispGraph(g1);
	DestroyGraph(g);
	DestroyGraph(g1);
	DestroyGraph(G);
}

