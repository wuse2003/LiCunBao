#include <stdio.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{	ElemType data[MaxSize];		//存放队列中的元素
	int front;					//队头指针
	int count;					//队列中元素个数
} SQueue;
void InitQueue(SQueue &qu)				//队初始化算法
{
	qu.front=qu.count=0;
}
void DestroyQueue(SQueue sq)			//销毁队列
{  }
int EnQueue(SQueue &sq,ElemType x)		//元素进队算法
{	if (sq.count==MaxSize) return 0;	//队满
	sq.count++;							//队中元素个数增1
	sq.data[(sq.front+sq.count)%MaxSize]=x;
	return 1;
}
int DeQueue(SQueue &sq,ElemType &x)	//出队元素算法
{	if (sq.count==0) return 0;			//队空
	sq.count--;							//队中元素个数减1
	sq.front=(sq.front+1)%MaxSize;
	x=sq.data[sq.front];
	return 1;
}
int GetHead(SQueue sq,ElemType &x)		//取队头元素算法
{	if (sq.count==0) return 0;			//队空
	x=sq.data[(sq.front+1)%MaxSize];
	return 1;
}
int QueueEmpty(SQueue sq)				//判队空算法
{	if (sq.count==0) return 1;			//队空返回1
	else return 0;						//队不空返回0
}
void main()
{	SQueue sq;
	ElemType e;
	printf("初始化队列\n");
	InitQueue(sq);
	printf("队%s\n",(QueueEmpty(sq)==1?"空":"不空"));
	printf("a进队\n");EnQueue(sq,'a');
	printf("b进队\n");EnQueue(sq,'b');
	printf("c进队\n");EnQueue(sq,'c');
	printf("d进队\n");EnQueue(sq,'d');
	printf("队%s\n",(QueueEmpty(sq)==1?"空":"不空"));
	GetHead(sq,e);
	printf("队头元素:%c\n",e);
	printf("出队次序:");
	while (!QueueEmpty(sq))		//队不空循环
	{	DeQueue(sq,e);			//出队元素e
		printf("%c ",e);		//输出元素e
	}
	printf("\n");
	DestroyQueue(sq);
}
