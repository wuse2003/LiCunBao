#include "AdjGraph.cpp"
#include "MatGraph.cpp"
int visited[MAXVEX];
void DFS(AdjGraph *G,int v)		//对邻接表G从顶点v开始进行深度优先遍历
{	int w; ArcNode *p;
	printf("%d ",v);			//访问v顶点
	visited[v]=1;
	p=G->adjlist[v].firstarc;	//找v的第一个邻接点
	while (p!=NULL)				//找v的所有邻接点
	{	w= p->adjvex;			//顶点v的相邻点w
		if (visited[w]==0)		//顶点w未访问过
			DFS(G,w);			//从w出发深度优先遍历
		p=p->nextarc;				//找v的下一个邻接点
	}
}
void DFS1(MatGraph g,int v)	//邻接矩阵的DFS算法
{  int w;
   printf("%d ",v);		//输出被访问顶点的编号
   visited[v]=1;			//置已访问标记
   for (w=0;w<g.n;w++)		//找顶点v的所有相邻点
     if (g.edges[v][w]!=0 && g.edges[v][w]!=INF 
		&& visited[w]==0)
	DFS1(g,w);		//找顶点v的未访问过的相邻点w
}
void BFS(AdjGraph *G,int v)				//对邻接表G从顶点v开始进行广度优先遍历
{	int i,w,visited[MAXVEX];
	int Qu[MAXVEX],front=0,rear=0;		//定义一个循环队列Qu
	ArcNode *p;
	for (i=0;i<G->n;i++) visited[i]=0;	//visited数组置初值0
	printf("%d ",v);					//访问初始顶点
	visited[v]=1;
	rear=(rear=1)%MAXVEX;
	Qu[rear]=v;							//初始顶点v进队
	while (front!=rear)					//队不为空时循环
	{	front=(front+1) % MAXVEX;
		w=Qu[front];					//出队顶点w
		p=G->adjlist[w].firstarc;		//查找w的第一个邻接点
		while (p!=NULL)					//查找w的所有邻接点
		{	if (visited[p->adjvex]==0)	//未访问过则访问之
			{	printf("%d ",p->adjvex);//访问该点并进队
				visited[p->adjvex]=1;
				rear=(rear+1) % MAXVEX;
				Qu[rear]=p->adjvex;
			}
			p=p->nextarc;				//查找w的下一个邻接点
		}
	}
}
void BFS1(MatGraph g,int v)			//邻接矩阵的BFS算法
{	int i,w,visited[MAXVEX];
	int Qu[MAXVEX],front=0,rear=0;		//定义一个循环队列Qu
	for (i=0;i<g.n;i++) visited[i]=0;	//visited数组置初值0
	printf("%d ",v);					//访问初始顶点
	visited[v]=1;
	rear=(rear=1)%MAXVEX;
	Qu[rear]=v;							//初始顶点v进队
	while (front!=rear)					//队不为空时循环
	{	front=(front+1) % MAXVEX;
		w=Qu[front];					//出队顶点w
		for (i=0;i<g.n;i++)				//找与顶点w相邻的顶点
			if (g.edges[w][i]!=0 && g.edges[w][i]!=INF && visited[i]==0)
			{
				printf("%d ",i);		//访问w的未被访问的相邻顶点i
				visited[i]=1;			//置该顶点已被访问的标志
				rear=(rear+1)%MAXVEX;
				Qu[rear]=i;				//该顶点进队
			}
	}
}

