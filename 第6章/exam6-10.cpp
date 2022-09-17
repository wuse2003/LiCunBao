#include <stdio.h>
#include "BTree.cpp"
int twonodes(BTNode *bt)
{	if (bt==NULL)	//空树返回0
		return 0;
	if (bt->lchild!=NULL && bt->rchild!=NULL)	//双分支结点
		return 1+twonodes(bt->lchild)+twonodes(bt->rchild);
	else										//其他情况
		return twonodes(bt->lchild)+twonodes(bt->rchild);
}
void main()
{	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//构造图6.14所示的二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("双分支结点个数:%d\n",twonodes(bt));
}