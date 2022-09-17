#include <stdio.h>
#define MaxSize 100				//˳��ӵĳ�ʼ����ռ��С
typedef int ElemType;			//����˳���������Ԫ��Ϊint����
typedef struct
{	ElemType data[MaxSize];		//�������Ԫ��
	int front,rear;				//��ͷ�Ͷ�βָ��
} SqQueue;


void InitQueue(SqQueue &sq)		//sqΪ�����Ͳ���
{
	sq.rear=sq.front=0;			//ָ���ʼ��
}

void DestroyQueue(SqQueue sq)
{    }

int EnQueue(SqQueue &sq,ElemType x)
{	if ((sq.rear+1) % MaxSize==sq.front)	//���������
		return 0;
	sq.rear=(sq.rear+1) % MaxSize;			//��βѭ����1
	sq.data[sq.rear]=x;
	return 1;
}

int DeQueue(SqQueue &sq,ElemType &x)		//xΪ�����Ͳ���
{	if (sq.rear==sq.front)					//�ӿ������
		return 0;
	sq.front=(sq.front+1) % MaxSize;		//��ͷѭ����1
	x=sq.data[sq.front];
	return 1;
}

int GetHead(SqQueue sq,ElemType &x)			//xΪ�����Ͳ���
{	if (sq.rear==sq.front)					//�ӿ������
		return 0;
	x=sq.data[(sq.front+1) % MaxSize];
	return 1;
}

int QueueEmpty(SqQueue sq)
{	if (sq.rear==sq.front) return 1;
	else return 0;
}
