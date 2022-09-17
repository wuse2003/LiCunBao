#include "OrderBTree.cpp"		//包含二叉树的各种遍历函数
void main()
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");//构造图5.14所示的二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("先序遍历序列:");PreOrder(bt);printf("\n");
	printf("中序遍历序列:");InOrder(bt);printf("\n");
	printf("后序遍历序列:");PostOrder(bt);printf("\n");
	printf("层次遍历序列:");LevelOrder(bt);printf("\n");
	DestroyBTree(bt);
}
