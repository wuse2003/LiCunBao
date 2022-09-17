#include <stdio.h>
#include "BTree.cpp"
int onenodes(BTNode *bt)
{	if (bt==NULL)									//空树返回0
		return 0;
	if ((bt->lchild==NULL && bt->rchild!=NULL)		//单分支结点
		|| (bt->lchild!=NULL && bt->rchild==NULL))
		return 1+onenodes(bt->lchild)+onenodes(bt->rchild);
	else											//其他情况
		return onenodes(bt->lchild)+onenodes(bt->rchild);
}
void main()
{	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//构造图6.14所示的二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("单分支结点个数:%d\n",onenodes(bt));
}