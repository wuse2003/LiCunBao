#include <stdio.h>
#include "BTree.cpp"
void ancestor1(BTNode *bt,ElemType path[],int pathlen)
{	int i;
	if (bt!=NULL)
	{	if (bt->lchild==NULL && bt->rchild==NULL)	//*bt为叶子结点
		{	printf("  %c结点的所有祖先结点: ",bt->data);
			for (i=pathlen-1;i>=0;i--)
				printf("%c ",path[i]);
			printf("\n");
		}
		else
		{	path[pathlen]=bt->data;					//将当前结点放入路径中
			pathlen++;								//path中元素个数增1
			ancestor1(bt->lchild,path,pathlen);	//递归扫描左子树
			ancestor1(bt->rchild,path,pathlen);	//递归扫描右子树
		}
	}
}
void ancestor2(BTNode *bt)
{
	BTNode *p;
	int i;
	struct 
	{	BTNode *s;					//存放结点指针
		int parent;					//存放其双亲结点在qu中的下标
	} qu[MaxSize];					//qu存放队中元素
	int front=-1,rear=-1;			//队头队尾指针
	rear++;
	qu[rear].s=bt;					//根结点进队
	qu[rear].parent=-1;				//根结点没有双亲,其parent置为-1
	while (front!=rear)				//队不空循环
	{
		front++;
		p=qu[front].s;				//出队一个结点*p,它在qu中的下标为front
		if (p->lchild==NULL && p->rchild==NULL)	//若*p为叶子结点
		{	printf("  %c结点的所有祖先结点: ",p->data);
			i=qu[front].parent;
			while (i!=-1)
			{
				printf("%c ",qu[i].s->data);
				i=qu[i].parent;
			}
			printf("\n");
		}
		if (p->lchild!=NULL)		//*p有左孩子,将左孩子进队
		{
			rear++;
			qu[rear].s=p->lchild;
			qu[rear].parent=front;	//左孩子的双亲为qu[front]结点
		}
		if (p->rchild!=NULL)		//*p有右孩子,将右孩子进队
		{
			rear++;
			qu[rear].s=p->rchild;
			qu[rear].parent=front;	//右孩子的双亲为qu[front]结点
		}
	}
}
void main()
{	BTNode *bt;
	ElemType path[MaxSize];
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//建立图6.14的二叉链
	printf("bt括号表示法:"); DispBTree(bt); printf("\n");
	printf("解法1:\n");
	printf("输出每个叶结点的所有祖先结点:\n");
	ancestor1(bt,path,0);
	printf("解法2:\n");
	printf("输出每个叶结点的所有祖先结点:\n");
	ancestor2(bt);
}
