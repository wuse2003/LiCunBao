#include "AdjGraph.cpp"			//包含邻接表的基本运算函数
int visited[MAXVEX];

void ShortPath(AdjGraph *G,int u,int v)
{
	struct QUEUE						//非循环队列类型
	{	int data;						//顶点编号
		int parent;						//前一个顶点的位置
	} qu[MAXVEX];						//定义一个非循环队列qu
	int front=-1,rear=-1;				//队列的头、尾指针
	ArcNode *p; int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;	//访问标记置初值0
	rear++;								//顶点u进队
	qu[rear].data=u; qu[rear].parent=-1;//起点的双亲置为-1
	visited[u]=1;
	while (front!=rear)					//队不空循环
	{	front++;						//出队顶点w
		w=qu[front].data;
		if (w==v)						//找到v时输出路径之逆并退出
		{	i=front;					//通过队列输出逆路径
			while (qu[i].parent!=-1)
			{	printf("%d ",qu[i].data);
				i=qu[i].parent;
			}
			printf("%d\n",qu[i].data);
			break;						//找到路径后退出while循环
		}
		p=G->adjlist[w].firstarc;		//找w的第一个邻接点
		while (p!=NULL)
		{	if (visited[p->adjvex]==0)
			{	visited[p->adjvex]=1;
				rear++;					//将w的未访问过的邻接点进队
				qu[rear].data=p->adjvex;
				qu[rear].parent=front;	//进队顶点的双亲置为front
			}
			p=p->nextarc;				//找w的下一个邻接点
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
	CreateGraph(G,A,n,e);	//建立图7.8(a)的邻接表
	for (i=0;i<G->n;i++)
		visited[i]=0;
	printf("从顶点%d到%d的最短逆路径:",u,v);
	ShortPath(G,u,v);
	DestroyGraph(G);
}

