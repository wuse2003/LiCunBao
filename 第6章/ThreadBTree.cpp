#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct bthnode
{	ElemType data;
	struct bthnode *lchild,*rchild;
	int ltag,rtag;
} BthNode;
//-------二叉链的基本运算算法-----------
void CreateBTree(BthNode * &bt,char *str)
{	BthNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;			//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')	//str未扫描完时循环
	{	switch(ch)
		{
		case '(':top++;St[top]=p;k=1; break;	//为左孩子结点
		case ')':top--;break;
		case ',':k=2; break;					//为右孩子结点
		default:p=(BthNode *)malloc(sizeof(BthNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (bt==NULL)					//*p为二叉树的根结点
					bt=p;
				else							//已建立二叉树根结点
				{	switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void DispBTree(BthNode *bt) 
{	if (bt!=NULL)
	{	printf("%c",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");			//有子树时输入'('
			DispBTree(bt->lchild);	//递归处理左子树
			if (bt->rchild!=NULL)	//有右子树时输入'.'
				printf(",");
			DispBTree(bt->rchild);	//递归处理右子树
			printf(")");			//子树输出完毕，再输入一个')'
		}
	}
}
//-------中序线索二叉树的基本运算算法-----------
BthNode *pre;						//定义pre为全局变量
void Thread(BthNode *&p)
//对以*p为根结点的二叉树进行中序线索化
{	if (p!=NULL)
	{	Thread(p->lchild);			//左子树线索化
		if (p->lchild==NULL)		//前驱线索
		{	p->lchild=pre;			//给结点*p添加前驱线索
			p->ltag=1;
		}
		else p->ltag=0;
		if (pre->rchild==NULL)
		{	pre->rchild=p;			//给结点*pre添加后继线索
			pre->rtag=1;
		}
		else pre->rtag=0;
		pre=p;
		Thread(p->rchild);			//右子树线索化
	}
}
BthNode *CreaThread(BthNode *bt)
//对以*bt为根结点的二叉树中序线索化,并增加一个头结点head
{	BthNode *head;
	head=(BthNode *)malloc(sizeof(BthNode));	//创建头结点
	head->ltag=0;head->rtag=1;
	head->rchild=bt;
	if (bt==NULL)				//bt为空树时
		head->lchild=head;
	else
	{	head->lchild=bt;
		pre=head;				//pre是*p的前驱结点,供加线索用
		Thread(bt);				//中序遍历线索化二叉树
		pre->rchild=head;		//最后处理,加入指向根结点的线索
		pre->rtag=1;
		head->rchild=pre;		//根结点右线索化
	}
	return head;
}
BthNode *FirstNode(BthNode *tb)	//在中序线索树中查找中序序列的第1个结点
{	BthNode *p=tb->lchild;
	while (p->ltag==0)
		p=p->lchild;
	return(p);
}
BthNode *LastNode(BthNode *tb)	//在中序线索树中查找中序序列的最后1个结点
{
	return(tb->rchild);
}
BthNode *PreNode(BthNode *p)
//在中序线索二叉树上,查找*p结点的前驱结点
{	BthNode *pre;
	pre=p->lchild;
	if (p->ltag!=1)
		while (pre->rtag==0)
			pre=pre->rchild;
	return(pre);
}
BthNode *PostNode(BthNode *p)
//在中序线索二叉树上,查找*p结点的后继结点
{	BthNode *post;
	post=p->rchild;
	if (p->rtag!=1)
		while (post->ltag==0)
			post=post->lchild;
	return(post);
}
void ThInOrder(BthNode *tb)		//中序遍历线索二叉树,输出中序遍历序列
{	BthNode *p;
	p=FirstNode(tb);
	while (p!=tb)
	{	printf("%c ",p->data);
		p=PostNode(p);
	}
	printf("\n");
}
void ThInOrder1(BthNode *tb)	//中序遍历线索二叉树,输出逆中序遍历序列
{	BthNode *p;
	p=LastNode(tb);
	while (p!=tb)
	{	printf("%c ",p->data);
		p=PreNode(p);
	}
	printf("\n");
}
void DestroyBTree1(BthNode *&b)
{
	if (b->ltag==0)			//*b有左孩子,释放左子树
		DestroyBTree1(b->lchild);
	if (b->rtag==0)			//*b有右孩子,释放右子树
		DestroyBTree1(b->rchild);
	free(b);
}
void DestroyBTree(BthNode *&tb)
{
	DestroyBTree1(tb->lchild);	//释放以tb->lchild为根结点的树
	free(tb);					//释放头结点
}
