#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct tnode
{	ElemType data;					//数据域
	struct tnode *lchild,*rchild;	//指针域
} BTNode;

void CreateBTree(BTNode * &bt,char *str)
{	BTNode *St[MaxSize],*p=NULL;
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
		default:p=(BTNode *)malloc(sizeof(BTNode));
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
void DestroyBTree(BTNode *&bt)
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}
int BTHeight(BTNode *bt) 
{	int lchilddep,rchilddep;
	if (bt==NULL) return(0); 			//空树的高度为0
	else
	{	lchilddep=BTHeight(bt->lchild);	//求左子树的高度为lchilddep
		rchilddep=BTHeight(bt->rchild);	//求右子树的高度为rchilddep
		return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
	}
}
int NodeCount(BTNode *bt)			//求二叉树bt的结点个数
{	int num1,num2;
	if (bt==NULL)					//空树返回0
		return 0;
	else
	{	num1=NodeCount(bt->lchild);	//求左子树结点个数
		num2=NodeCount(bt->rchild);	//求右子树结点个数
		return (num1+num2+1);		//返回和加上1
	}
}
int LeafCount(BTNode *bt)				//求二叉树bt的叶子结点个数
{	int num1,num2;
	if (bt==NULL)						//空树返回0
		return 0;
	else if (bt->lchild==NULL && bt->rchild==NULL) 
		return 1;						//叶子结点时返回1
	else
	{	num1=LeafCount(bt->lchild);		//求左子树叶子结点个数
		num2=LeafCount(bt->rchild); 	//求右子树叶子结点个数
		return (num1+num2);				//返回和
	}
}
void DispBTree(BTNode *bt) 
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
