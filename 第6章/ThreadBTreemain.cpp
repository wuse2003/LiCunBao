#include "ThreadBTree.cpp"
void main()
{
	BthNode *bt,*tb;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(I)))");//����ͼ5.14��ʾ�Ķ�����
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("������������������tb\n");
	tb=CreaThread(bt);
	printf("�����������:"); ThInOrder(tb);
	printf("�������������:"); ThInOrder1(tb);
	DestroyBTree(bt);						//������������������
}
