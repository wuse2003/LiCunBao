#include "ThreadBTree.cpp"
void main()
{
	BthNode *bt,*tb;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");//构造图5.14所示的二叉链
	printf("二叉树bt:");DispBTree(bt);printf("\n");
	printf("构造中序线索二叉树tb\n");
	tb=CreaThread(bt);
	printf("中序遍历序列:"); ThInOrder(tb);
	printf("逆中序遍历序列:"); ThInOrder1(tb);
	DestroyBTree(bt);						//销毁中序线索二叉树
}
