#include "BTree.cpp"
#define MaxSize 100

void PreOrder(BTNode *bt)
{	if (bt!=NULL)
	{	printf("%c ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void InOrder(BTNode *bt)
{	if (bt!=NULL)
	{	InOrder(bt->lchild);
		printf("%c ",bt->data);
		InOrder(bt->rchild);
	}
}

void PostOrder(BTNode *bt)
{	if (bt!=NULL)
	{	PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c ",bt->data);
	}
}

void LevelOrder(BTNode *bt)
{	BTNode *p;
	BTNode *qu[MaxSize];			//����ѭ������,��Ŷ��������ָ��
	int front,rear;					//�����ͷ�Ͷ�βָ��
	front=rear=-1;					//�ö���Ϊ�ն���
	rear++; qu[rear]=bt;			//�����ָ��������
	while (front!=rear)				//���в�Ϊ��ѭ��
	{	front=(front+1)%MaxSize;
		p=qu[front];				//���ӽ��*p
		printf("%c ",p->data);		//���ʸý��
		if (p->lchild!=NULL)		//������ʱ�������
		{	rear=(rear+1)%MaxSize;
			qu[rear]=p->lchild;
		}
		if (p->rchild!=NULL)		//���Һ���ʱ�������
		{	rear=(rear+1)%MaxSize;
			qu[rear]=p->rchild;
		}
	}
}
