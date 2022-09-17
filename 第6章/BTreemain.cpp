#include "BTree.cpp"		//包含二叉链的基本运算函数
void main()
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");//构造图6.14所示的二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("bt的高度:%d\n",BTHeight(bt));
	printf("bt的结点数:%d\n",NodeCount(bt));
	printf("bt的叶子结点数:%d\n",LeafCount(bt));
}

