#include <stdio.h>
#include "BTree.cpp"
typedef ElemType SqBinTree[MaxSize];
void trans1(BTNode *bt, SqBinTree &sb,int i)
{	//i�ĳ�ֵΪ�������1
	if (bt!=NULL)
	{	sb[i]=bt->data;					//���������
		trans1(bt->lchild,sb,2*i);		//�ݹ齨��������
		trans1(bt->rchild,sb,2*i+1);	//�ݹ齨��������
	}
	else sb[i]='#';						//�����ڵĽ��Ķ�Ӧλ��ֵΪ'#'
}
void main()
{	int i,N=15;
	BTNode *bt;
	SqBinTree sb;
	for (i=1;i<N;i++)
		sb[i]='#';
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//����ͼ6.14��ʾ�Ķ�����
	printf("������bt:");DispBTree(bt);printf("\n");
	printf("������Ӧ��˳��洢�ṹsb\n");
	trans1(bt,sb,1);
	printf("������nt:\n");
	for (i=1;i<N;i++)
		printf("%d\t",i);
	printf("\n");
	for (i=1;i<N;i++)
		printf("%c\t",sb[i]);
	printf("\n");
}