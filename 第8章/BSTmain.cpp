#include "BST.cpp"
void main()
{
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11},k=25;
	int n=12;
	BSTNode *bt;
	CreateBST(bt,a,n);
	printf("BST:"); DispBST(bt); printf("\n");
	printf("ɾ���ؼ���%d\n",k);
	if (BSTDelete(bt,k))
	{
		printf("BST:"); DispBST(bt); printf("\n");
	}
	else
		printf("δ�ҵ��ؼ���Ϊ%d�Ľ��\n",k);
	printf("����ؼ���%d\n",k);
	if (BSTInsert(bt,k))
	{
		printf("BST:"); DispBST(bt); printf("\n");
	}
	else
		printf("�����ظ��Ĺؼ���%d\n",k);
	DestroyBST(bt);
}

