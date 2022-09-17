#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct node
{	ElemType data;				//������
	struct node *next;			//ָ����
} QNode;						//���ӽ������
void InitQueue(QNode *&lq)		//��ʼ�����������㷨
{
	lq=NULL;
}
void DestroyQueue(QNode *&lq)	//��������
{	QNode *pre,*p;
	if (lq!=NULL)
	{	if (lq->next==lq)		//ԭ����ֻ��һ�����
			free(lq);
		else					//ԭ���������������ϵĽ��
		{	pre=lq;
			p=pre->next;
			while (p!=lq)
			{	free(pre);
				pre=p;
				p=p->next;		//pre��pͬ������
			}
			free(pre);			//�ͷ����һ�����
		}
	}
}
void EnQueue(QNode *&lq,ElemType x)	//���������㷨
{	QNode *s;
	s=(QNode *)malloc(sizeof(QNode));
	s->data=x;				//�������x�Ľ��*s
	if (lq==NULL)			//ԭΪ�ն�
	{	lq=s;
		lq->next=lq;		//����ѭ��������
	}
	else					//ԭ�Ӳ���,���s�嵽��β,����lqָ����
	{	s->next=lq->next;
		lq->next=s;
		lq=s;				//lqָ����s
	}
}
int DeQueue(QNode *&lq,ElemType &x)	//���������㷨
{	QNode *s;
	if (lq==NULL) return 0;		//ԭΪ�ӿ�
	if (lq->next==lq)			//ԭ��ֻ��һ�����
	{	x=lq->data;
		free(lq);
		lq=NULL;
	}
	else						//ԭ�������������ϵĽ��,ɾ����ͷ���
	{	s=lq->next;				//��lq֮����sɾ��
		x=s->data;
		lq->next=s->next;
		free(s);
	}
	return 1;
}
int GetHead(QNode *lq,ElemType &x) 	//ȡ��ͷԪ�������㷨
{	if (lq==NULL) return 0;			//ԭΪ�ӿ�
	x=lq->next->data;
	return 1;
}
int QueueEmpty(QNode *lq)	//�ж϶ӿ������㷨
{	if (lq==NULL) return 1;	//�ӿշ���1
	else return 0;			//�Ӳ��շ���0
}

void main()
{	QNode *sq;
	ElemType e;
	printf("��ʼ������\n");
	InitQueue(sq);
	printf("��%s\n",(QueueEmpty(sq)==1?"��":"����"));
	printf("a����\n");EnQueue(sq,'a');
	printf("b����\n");EnQueue(sq,'b');
	printf("c����\n");EnQueue(sq,'c');
	printf("d����\n");EnQueue(sq,'d');
	printf("��%s\n",(QueueEmpty(sq)==1?"��":"����"));
	GetHead(sq,e);
	printf("��ͷԪ��:%c\n",e);
	printf("���Ӵ���:");
	while (!QueueEmpty(sq))		//�Ӳ���ѭ��
	{	DeQueue(sq,e);			//����Ԫ��e
		printf("%c ",e);		//���Ԫ��e
	}
	printf("\n");
	DestroyQueue(sq);
}
