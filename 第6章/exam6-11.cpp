#include <stdio.h>
#include "BTree.cpp"
void CopyBTree(BTNode *bt,BTNode *&nt)		//�ɶ�����bt���Ʋ���������nt
{	if (bt!=NULL)
	{	nt=(BTNode *)malloc(sizeof(BTNode));	//���Ƹ����
		nt->data=bt->data;
		CopyBTree(bt->lchild,nt->lchild);		//�ݹ鸴��������
		CopyBTree(bt->rchild,nt->rchild);		//�ݹ鸴��������
	}
	else nt=NULL;		//btΪ����ʱntҲΪ����
}
void main()
{	BTNode *bt,*nt;
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//����ͼ6.14��ʾ�Ķ�����
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("bt=>nt\n");
	CopyBTree(bt,nt);
	printf("������nt:");DispBTree(nt);printf("\n");
}