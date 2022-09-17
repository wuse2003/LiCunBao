#include "BTree.cpp"
#define MaxSize 100

void PreOrder(BTNode *bt)
{	if (bt!=NULL)
	{	printf("%c ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void InOrder(BTNode *bt)
{	if (bt!=NULL)
	{	InOrder(bt->lchild);
		printf("%c ",bt->data);
		InOrder(bt->rchild);
	}
}

void PostOrder(BTNode *bt)
{	if (bt!=NULL)
	{	PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c ",bt->data);
	}
}

void LevelOrder(BTNode *bt)
{	BTNode *p;
	BTNode *qu[MaxSize];			//定义循环队列,存放二叉链结点指针
	int front,rear;					//定义队头和队尾指针
	front=rear=-1;					//置队列为空队列
	rear++; qu[rear]=bt;			//根结点指针进入队列
	while (front!=rear)				//队列不为空循环
	{	front=(front+1)%MaxSize;
		p=qu[front];				//出队结点*p
		printf("%c ",p->data);		//访问该结点
		if (p->lchild!=NULL)		//有左孩子时将其进队
		{	rear=(rear+1)%MaxSize;
			qu[rear]=p->lchild;
		}
		if (p->rchild!=NULL)		//有右孩子时将其进队
		{	rear=(rear+1)%MaxSize;
			qu[rear]=p->rchild;
		}
	}
}
