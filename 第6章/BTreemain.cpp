#include "BTree.cpp"		//�����������Ļ������㺯��
void main()
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");//����ͼ6.14��ʾ�Ķ�����
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("bt�ĸ߶�:%d\n",BTHeight(bt));
	printf("bt�Ľ����:%d\n",NodeCount(bt));
	printf("bt��Ҷ�ӽ����:%d\n",LeafCount(bt));
}

