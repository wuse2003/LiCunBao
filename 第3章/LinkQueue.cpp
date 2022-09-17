#include <stdio.h>
#include <malloc.h>
typedef char ElemType;			//假设链队中所有元素为char类型
typedef struct QNode 
{	ElemType data;
	struct QNode *next;
} QType;
						//链队中结点的类型
typedef struct qptr
{	QType *front;		//队头指针
	QType *rear;		//队尾指针
} LinkQueue;			//链队结点类型


void InitQueue(LinkQueue *&lq)		//lq为引用型参数
{	lq=(LinkQueue *)malloc(sizeof(LinkQueue));
	lq->rear=lq->front=NULL;		//初始时队头和队尾指针均为空
}

void DestroyQueue(LinkQueue *&lq)
{
	QType *pre=lq->front,*p;
	if (pre!=NULL)					//非空队的情况
	{
		if (pre==lq->rear)			//只有一个数据结点的情况
			free(pre);				//释放pre结点
		else						//有两个或多个数据结点的情况
		{	p=pre->next;
			while (p!=NULL)
			{	free(pre);			//释放pre结点
				pre=p; p=p->next;	//pre、p同步后移
			}
			free(pre);				//释放尾结点
		}
		free(lq);					//释放链队结点
	}
}

int EnQueue(LinkQueue *&lq,ElemType x)	//lq为引用型参数
{
	QType *s;
	s=(QType *)malloc(sizeof(QType));	//创建新结点，插入到链队的末尾
	s->data=x;s->next=NULL;
	if (lq->front==NULL)				//原队为空队的情况
		lq->rear=lq->front=s;			//front和rear均指向s结点
	else								//原队不为空队的情况
	{	lq->rear->next=s;				//将s链到队尾
		lq->rear=s;						//rear指向它
	}
	return 1;
}

int DeQueue(LinkQueue *&lq,ElemType &x)	//lq,x均为引用型参数
{	QType *p;
	if (lq->front==NULL)				//原队为空队的情况
		return 0;
	p=lq->front;						//p指向队头结点
	x=p->data;							//取队头元素值
	if (lq->rear==lq->front)			//若原队列中只有一个结点,删除后队列变空
		lq->rear=lq->front=NULL;
	else								//原队有两个或以上结点的情况
		lq->front=lq->front->next;
	free(p);
	return 1;
}

int GetHead(LinkQueue *lq,ElemType &x)	//x为引用型参数
{	if (lq->front==NULL)				//原队为队空的情况
		return 0;
	x=lq->front->data;
	return 1;
}

int QueueEmpty(LinkQueue *lq)
{	if (lq->front==NULL) return 1;		//队空返回1
	else return 0;						//队不空返回0
}
