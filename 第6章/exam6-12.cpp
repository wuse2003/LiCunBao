#include <stdio.h>
#include "BTree.cpp"
typedef ElemType SqBinTree[MaxSize];
void trans1(BTNode *bt, SqBinTree &sb,int i)
{	//i的初值为根结点编号1
	if (bt!=NULL)
	{	sb[i]=bt->data;					//创建根结点
		trans1(bt->lchild,sb,2*i);		//递归建立左子树
		trans1(bt->rchild,sb,2*i+1);	//递归建立右子树
	}
	else sb[i]='#';						//不存在的结点的对应位置值为'#'
}
void main()
{	int i,N=15;
	BTNode *bt;
	SqBinTree sb;
	for (i=1;i<N;i++)
		sb[i]='#';
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//构造图6.14所示的二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("建立对应的顺序存储结构sb\n");
	trans1(bt,sb,1);
	printf("二叉树nt:\n");
	for (i=1;i<N;i++)
		printf("%d\t",i);
	printf("\n");
	for (i=1;i<N;i++)
		printf("%c\t",sb[i]);
	printf("\n");
}