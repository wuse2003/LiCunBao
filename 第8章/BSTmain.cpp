#include "BST.cpp"
void main()
{
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11},k=25;
	int n=12;
	BSTNode *bt;
	CreateBST(bt,a,n);
	printf("BST:"); DispBST(bt); printf("\n");
	printf("删除关键字%d\n",k);
	if (BSTDelete(bt,k))
	{
		printf("BST:"); DispBST(bt); printf("\n");
	}
	else
		printf("未找到关键字为%d的结点\n",k);
	printf("插入关键字%d\n",k);
	if (BSTInsert(bt,k))
	{
		printf("BST:"); DispBST(bt); printf("\n");
	}
	else
		printf("存在重复的关键字%d\n",k);
	DestroyBST(bt);
}

