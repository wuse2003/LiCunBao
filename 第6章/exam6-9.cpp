#include <stdio.h>
#include "BTree.cpp"
int onenodes(BTNode *bt)
{	if (bt==NULL)									//��������0
		return 0;
	if ((bt->lchild==NULL && bt->rchild!=NULL)		//����֧���
		|| (bt->lchild!=NULL && bt->rchild==NULL))
		return 1+onenodes(bt->lchild)+onenodes(bt->rchild);
	else											//�������
		return onenodes(bt->lchild)+onenodes(bt->rchild);
}
void main()
{	BTNode *bt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//����ͼ6.14��ʾ�Ķ�����
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("����֧������:%d\n",onenodes(bt));
}