#include <stdio.h>
#include "BTree.cpp"
typedef ElemType SqBinTree[MaxSize];
void trans2(BTNode *&bt,SqBinTree sb,int i)
{	//i的初值为根结点编号1
	if (i<MaxSize && sb[i]!='#')				//存在有效结点时
	{	bt=(BTNode *)malloc(sizeof(BTNode));	//创建根结点
		bt->data=sb[i];
		trans2(bt->lchild,sb,2*i);				//递归建立左子树
		trans2(bt->rchild,sb,2*i+1);			//递归建立右子树
	}
	else bt=NULL;		//无效结点对应的二叉链为NULL
}
void main()
{	
	BTNode *bt;
	SqBinTree sb=" ABCDE#F##GH##I###############";		//构造图5.12(a)所示的二叉树的顺序存储结构
	printf("sb:%s\n",sb);
	printf("建立对应的二叉链存储结构bt\n");
	trans2(bt,sb,1);
	printf("二叉树bt:");DispBTree(bt);printf("\n");
}