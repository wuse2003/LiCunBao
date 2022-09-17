#include <stdio.h>
#include <malloc.h>
typedef char ElemType;			//��������������Ԫ��Ϊchar����
typedef struct QNode 
{	ElemType data;
	struct QNode *next;
} QType;
						//�����н�������
typedef struct qptr
{	QType *front;		//��ͷָ��
	QType *rear;		//��βָ��
} LinkQueue;			//���ӽ������


void InitQueue(LinkQueue *&lq)		//lqΪ�����Ͳ���
{	lq=(LinkQueue *)malloc(sizeof(LinkQueue));
	lq->rear=lq->front=NULL;		//��ʼʱ��ͷ�Ͷ�βָ���Ϊ��
}

void DestroyQueue(LinkQueue *&lq)
{
	QType *pre=lq->front,*p;
	if (pre!=NULL)					//�ǿնӵ����
	{
		if (pre==lq->rear)			//ֻ��һ�����ݽ������
			free(pre);				//�ͷ�pre���
		else						//�������������ݽ������
		{	p=pre->next;
			while (p!=NULL)
			{	free(pre);			//�ͷ�pre���
				pre=p; p=p->next;	//pre��pͬ������
			}
			free(pre);				//�ͷ�β���
		}
		free(lq);					//�ͷ����ӽ��
	}
}

int EnQueue(LinkQueue *&lq,ElemType x)	//lqΪ�����Ͳ���
{
	QType *s;
	s=(QType *)malloc(sizeof(QType));	//�����½�㣬���뵽���ӵ�ĩβ
	s->data=x;s->next=NULL;
	if (lq->front==NULL)				//ԭ��Ϊ�նӵ����
		lq->rear=lq->front=s;			//front��rear��ָ��s���
	else								//ԭ�Ӳ�Ϊ�նӵ����
	{	lq->rear->next=s;				//��s������β
		lq->rear=s;						//rearָ����
	}
	return 1;
}

int DeQueue(LinkQueue *&lq,ElemType &x)	//lq,x��Ϊ�����Ͳ���
{	QType *p;
	if (lq->front==NULL)				//ԭ��Ϊ�նӵ����
		return 0;
	p=lq->front;						//pָ���ͷ���
	x=p->data;							//ȡ��ͷԪ��ֵ
	if (lq->rear==lq->front)			//��ԭ������ֻ��һ�����,ɾ������б��
		lq->rear=lq->front=NULL;
	else								//ԭ�������������Ͻ������
		lq->front=lq->front->next;
	free(p);
	return 1;
}

int GetHead(LinkQueue *lq,ElemType &x)	//xΪ�����Ͳ���
{	if (lq->front==NULL)				//ԭ��Ϊ�ӿյ����
		return 0;
	x=lq->front->data;
	return 1;
}

int QueueEmpty(LinkQueue *lq)
{	if (lq->front==NULL) return 1;		//�ӿշ���1
	else return 0;						//�Ӳ��շ���0
}
