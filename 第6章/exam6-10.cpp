#include <stdio.h>
#include "BTree.cpp"
int twonodes(BTNode *bt)
{	if (bt==NULL)	//��������0
		return 0;
	if (bt->lchild!=NULL && bt->rchild!=NULL)	//˫��֧���
		return 1+twonodes(bt->lchild)+twonodes(bt->rchild);
	else										//�������
		return twonodes(bt->lchild)+twonodes(bt->rchild);
}
void main()
{	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//����ͼ6.14��ʾ�Ķ�����
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("˫��֧������:%d\n",twonodes(bt));
}