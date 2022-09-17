#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct node
{	ElemType data;				//数据域
	struct node *next;			//指针域
} QNode;						//链队结点类型
void InitQueue(QNode *&lq)		//初始化队列运算算法
{
	lq=NULL;
}
void DestroyQueue(QNode *&lq)	//销毁链队
{	QNode *pre,*p;
	if (lq!=NULL)
	{	if (lq->next==lq)		//原队中只有一个结点
			free(lq);
		else					//原队中有两个或以上的结点
		{	pre=lq;
			p=pre->next;
			while (p!=lq)
			{	free(pre);
				pre=p;
				p=p->next;		//pre和p同步后移
			}
			free(pre);			//释放最后一个结点
		}
	}
}
void EnQueue(QNode *&lq,ElemType x)	//进队运算算法
{	QNode *s;
	s=(QNode *)malloc(sizeof(QNode));
	s->data=x;				//创建存放x的结点*s
	if (lq==NULL)			//原为空队
	{	lq=s;
		lq->next=lq;		//构成循环单链表
	}
	else					//原队不空,结点s插到队尾,并由lq指向它
	{	s->next=lq->next;
		lq->next=s;
		lq=s;				//lq指向结点s
	}
}
int DeQueue(QNode *&lq,ElemType &x)	//出队运算算法
{	QNode *s;
	if (lq==NULL) return 0;		//原为队空
	if (lq->next==lq)			//原队只有一个结点
	{	x=lq->data;
		free(lq);
		lq=NULL;
	}
	else						//原队有两个或以上的结点,删除队头结点
	{	s=lq->next;				//将lq之后结点s删除
		x=s->data;
		lq->next=s->next;
		free(s);
	}
	return 1;
}
int GetHead(QNode *lq,ElemType &x) 	//取队头元素运算算法
{	if (lq==NULL) return 0;			//原为队空
	x=lq->next->data;
	return 1;
}
int QueueEmpty(QNode *lq)	//判断队空运算算法
{	if (lq==NULL) return 1;	//队空返回1
	else return 0;			//队不空返回0
}

void main()
{	QNode *sq;
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
