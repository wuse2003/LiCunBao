#include "AdjGraph.cpp"		//�����ڽӱ�Ļ������㺯��
void main()
{
	AdjGraph *G;
	int n=5,e=7,i;
	int A[MAXVEX][MAXVEX]={{0,1,2,6,INF},{INF,0,INF,4,5},{INF,INF,0,INF,3},{INF,INF,INF,0,INF},{INF,INF,INF,7,0}};
	CreateGraph(G,A,n,e);	//����ͼ7.4ͼ���ڽӱ�
	printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(G);
	printf("ͼG�����ж���Ķ�:\n"); 
	printf("  ����\t��\n");
	for (i=0;i<G->n;i++)
		printf("   %d\t%d\n",i,Degree2(G,i));
	DestroyGraph(G);
}

