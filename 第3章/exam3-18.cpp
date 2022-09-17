#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct Lnode 
{	char data[10];			//��Ż�������
	struct Lnode *next;		//ָ����
} QType;					//���ӽ������
typedef struct 
{	QType *front;			//ָ���ͷ���˽��
	QType *rear;			//ָ���β���˽��
} LQueue;					//������������
//---��ʼ�����������㷨---
void InitQueue(LQueue *&lq)
{	lq=(LQueue *)malloc(sizeof(LQueue));
	lq->rear=lq->front=NULL;		//��ʼʱ��ͷ�Ͷ�βָ���Ϊ��
}
//----��������----
void DestroyQueue(LQueue *&lq)
{	QType *pre=lq->front,*p;
	if (pre!=NULL)					//�ǿնӵ����
	{	if (pre==lq->rear)			//ֻ��һ�����ݽ������
			free(pre);				//�ͷ�*pre���
		else						//�������������ݽ������
		{	p=pre->next;
			while (p!=NULL)
			{	free(pre);			//�ͷ�*pre���
				pre=p; p=p->next;	//pre��pͬ������
			}
			free(pre);				//�ͷ�β���
		}
	}
	free(lq);						//�ͷ����ӽ��
}
//----���������㷨----
void EnQueue(LQueue *&lq,char x[])
{	QType *s;
	s=(QType *)malloc(sizeof(QType));	//�����½�㣬���뵽���ӵ�ĩβ
	strcpy(s->data,x);s->next=NULL;
	if (lq->front==NULL)				//ԭ��Ϊ�նӵ����
		lq->rear=lq->front=s;			//front��rear��ָ��*s���
	else								//ԭ�Ӳ�Ϊ�նӵ����
	{	lq->rear->next=s;				//��*s������β
		lq->rear=s;						//rearָ����
	}
}
//-----���������㷨-----
int DeQueue(LQueue *&lq,char x[])
{	QType *p;
	if (lq->front==NULL)		//ԭ��Ϊ�նӵ����
		return 0;
	p=lq->front;				//pָ���ͷ���
	strcpy(x,p->data);			//ȡ��ͷԪ��ֵ
	if (lq->rear==lq->front)	//��ԭ������ֻ��һ�����,ɾ������б��
		lq->rear=lq->front=NULL;
	else						//ԭ�������������Ͻ������
		lq->front=lq->front->next;
	free(p);
	return 1;
}
//----�ж϶ӿ������㷨----
int QueueEmpty(LQueue *lq)
{	if (lq->front==NULL) return 1;	//�ӿշ���1
	else return 0;					//�Ӳ��շ���0
}
//----�����������Ԫ�ص��㷨----
int DispQueue(LQueue *lq)
{	QType *p;
	if (QueueEmpty(lq))				//�ӿշ���0
		return 0;
	else
	{	p=lq->front;
		while (p!=NULL)
		{	printf("%s ",p->data);
			p=p->next;
		}
		printf("\n");
		return 1;			//�Ӳ��շ���1
	}
}

void main()
{	int sel,flag=1;
	LQueue *lq;
	char name[10];
	InitQueue(lq);			//��ʼ�����˶���
	while (flag==1) 		//δ�°�ʱѭ��ִ��
	{	printf("1:�Ŷ� 2:��ҽ�� 3:�鿴�Ŷ� 0:�°�  ��ѡ��:");
		scanf("%d",&sel);	//ѡ��һ�����
		switch(sel) 
		{
		case 0:				//ҽ���°�
			if (!QueueEmpty(lq))
				printf("  >>���ŶӵĻ��������ҽ\n");
			DestroyQueue(lq);
			flag=0;
			break;
		case 1:				//һ�������Ŷ�
			printf("  >>���뻼������:");
			scanf("%s",name);
			EnQueue(lq,name);
			break;
		case 2:				//һ�����˿�ҽ��
			if (!DeQueue(lq,name))
				printf("  >>û���ŶӵĻ���\n");
			else
				printf("  >>����%s��ҽ��\n",name);
			break;
		case 3:				//�鿴Ŀǰ�����Ŷ����
			printf("  >>�Ŷӻ���:");
			if (!DispQueue(lq))
				printf("  >>û���ŶӵĻ���\n");
			break;
		}
	}
}
