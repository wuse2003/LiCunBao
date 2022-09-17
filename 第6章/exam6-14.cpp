#include <stdio.h>
#include "BTree.cpp"
void ancestor1(BTNode *bt,ElemType path[],int pathlen)
{	int i;
	if (bt!=NULL)
	{	if (bt->lchild==NULL && bt->rchild==NULL)	//*btΪҶ�ӽ��
		{	printf("  %c�����������Ƚ��: ",bt->data);
			for (i=pathlen-1;i>=0;i--)
				printf("%c ",path[i]);
			printf("\n");
		}
		else
		{	path[pathlen]=bt->data;					//����ǰ������·����
			pathlen++;								//path��Ԫ�ظ�����1
			ancestor1(bt->lchild,path,pathlen);	//�ݹ�ɨ��������
			ancestor1(bt->rchild,path,pathlen);	//�ݹ�ɨ��������
		}
	}
}
void ancestor2(BTNode *bt)
{
	BTNode *p;
	int i;
	struct 
	{	BTNode *s;					//��Ž��ָ��
		int parent;					//�����˫�׽����qu�е��±�
	} qu[MaxSize];					//qu��Ŷ���Ԫ��
	int front=-1,rear=-1;			//��ͷ��βָ��
	rear++;
	qu[rear].s=bt;					//��������
	qu[rear].parent=-1;				//�����û��˫��,��parent��Ϊ-1
	while (front!=rear)				//�Ӳ���ѭ��
	{
		front++;
		p=qu[front].s;				//����һ�����*p,����qu�е��±�Ϊfront
		if (p->lchild==NULL && p->rchild==NULL)	//��*pΪҶ�ӽ��
		{	printf("  %c�����������Ƚ��: ",p->data);
			i=qu[front].parent;
			while (i!=-1)
			{
				printf("%c ",qu[i].s->data);
				i=qu[i].parent;
			}
			printf("\n");
		}
		if (p->lchild!=NULL)		//*p������,�����ӽ���
		{
			rear++;
			qu[rear].s=p->lchild;
			qu[rear].parent=front;	//���ӵ�˫��Ϊqu[front]���
		}
		if (p->rchild!=NULL)		//*p���Һ���,���Һ��ӽ���
		{
			rear++;
			qu[rear].s=p->rchild;
			qu[rear].parent=front;	//�Һ��ӵ�˫��Ϊqu[front]���
		}
	}
}
void main()
{	BTNode *bt;
	ElemType path[MaxSize];
	CreateBTree(bt,"A(B(D,E(G,H)),C(,F(K)))");//����ͼ6.14�Ķ�����
	printf("bt���ű�ʾ��:"); DispBTree(bt); printf("\n");
	printf("�ⷨ1:\n");
	printf("���ÿ��Ҷ�����������Ƚ��:\n");
	ancestor1(bt,path,0);
	printf("�ⷨ2:\n");
	printf("���ÿ��Ҷ�����������Ƚ��:\n");
	ancestor2(bt);
}
