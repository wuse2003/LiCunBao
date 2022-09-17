#include <stdio.h>
#include "BTree.cpp"
void CopyBTree(BTNode *bt,BTNode *&nt)		//由二叉树bt复制产生二叉树nt
{	if (bt!=NULL)
	{	nt=(BTNode *)malloc(sizeof(BTNode));	//复制根结点
		nt->data=bt->data;
		CopyBTree(bt->lchild,nt->lchild);		//递归复制左子树
		CopyBTree(bt->rchild,nt->rchild);		//递归复制左子树
	}
	else nt=NULL;		//bt为空树时nt也为空树
}
void main()
{	BTNode *bt,*nt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//构造图6.14所示的二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("bt=>nt\n");
	CopyBTree(bt,nt);
	printf("二叉树nt:");DispBTree(nt);printf("\n");
}