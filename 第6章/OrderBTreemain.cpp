#include "OrderBTree.cpp"		//�����������ĸ��ֱ�������
void main()
{
	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");//����ͼ5.14��ʾ�Ķ�����
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("�����������:");PreOrder(bt);printf("\n");
	printf("�����������:");InOrder(bt);printf("\n");
	printf("�����������:");PostOrder(bt);printf("\n");
	printf("��α�������:");LevelOrder(bt);printf("\n");
	DestroyBTree(bt);
}
