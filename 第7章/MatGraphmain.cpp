#include "MatGraph.cpp"		//�����ڽӾ���Ļ������㺯��
void main()
{
	MatGraph g;
	int n=5,e=7,i;
	int A[MAXVEX][MAXVEX]={{0,1,2,6,INF},{INF,0,INF,4,5},{INF,INF,0,INF,3},{INF,INF,INF,0,INF},{INF,INF,INF,7,0}};
	CreateGraph(g,A,n,e);	//����ͼ7.4ͼ���ڽӾ���
	printf("ͼG�Ĵ洢�ṹ:\n"); DispGraph(g);
	printf("ͼG�����ж���Ķ�:\n"); 
	printf("  ����\t��\n");
	for (i=0;i<g.n;i++)
		printf("   %d\t%d\n",i,Degree2(g,i));
	DestroyGraph(g);
}

