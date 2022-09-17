#include <stdio.h>
#define MaxSize 100				//顺序队的初始分配空间大小
typedef int ElemType;			//假设顺序队中所有元素为int类型
typedef struct
{	ElemType data[MaxSize];		//保存队中元素
	int front,rear;				//队头和队尾指针
} SqQueue;


void InitQueue(SqQueue &sq)		//sq为引用型参数
{
	sq.rear=sq.front=0;			//指针初始化
}

void DestroyQueue(SqQueue sq)
{    }

int EnQueue(SqQueue &sq,ElemType x)
{	if ((sq.rear+1) % MaxSize==sq.front)	//队满上溢出
		return 0;
	sq.rear=(sq.rear+1) % MaxSize;			//队尾循环进1
	sq.data[sq.rear]=x;
	return 1;
}

int DeQueue(SqQueue &sq,ElemType &x)		//x为引用型参数
{	if (sq.rear==sq.front)					//队空下溢出
		return 0;
	sq.front=(sq.front+1) % MaxSize;		//队头循环进1
	x=sq.data[sq.front];
	return 1;
}

int GetHead(SqQueue sq,ElemType &x)			//x为引用型参数
{	if (sq.rear==sq.front)					//队空下溢出
		return 0;
	x=sq.data[(sq.front+1) % MaxSize];
	return 1;
}

int QueueEmpty(SqQueue sq)
{	if (sq.rear==sq.front) return 1;
	else return 0;
}
