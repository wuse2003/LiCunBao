#include <stdio.h>
#include "BTree.cpp"
typedef ElemType SqBinTree[MaxSize];
void trans2(BTNode *&bt,SqBinTree sb,int i)
{	//i�ĳ�ֵΪ�������1
	if (i<MaxSize && sb[i]!='#')				//������Ч���ʱ
	{	bt=(BTNode *)malloc(sizeof(BTNode));	//���������
		bt->data=sb[i];
		trans2(bt->lchild,sb,2*i);				//�ݹ齨��������
		trans2(bt->rchild,sb,2*i+1);			//�ݹ齨��������
	}
	else bt=NULL;		//��Ч����Ӧ�Ķ�����ΪNULL
}
void main()
{	
	BTNode *bt;
	SqBinTree sb=" ABCDE#F##GH##I###############";		//����ͼ5.12(a)��ʾ�Ķ�������˳��洢�ṹ
	printf("sb:%s\n",sb);
	printf("������Ӧ�Ķ������洢�ṹbt\n");
	trans2(bt,sb,1);
	printf("������bt:");DispBTree(bt);printf("\n");
}