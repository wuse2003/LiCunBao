#include <stdio.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{	ElemType data[MaxSize];		//��Ŷ����е�Ԫ��
	int front;					//��ͷָ��
	int count;					//������Ԫ�ظ���
} SQueue;
void InitQueue(SQueue &qu)				//�ӳ�ʼ���㷨
{
	qu.front=qu.count=0;
}
void DestroyQueue(SQueue sq)			//���ٶ���
{  }
int EnQueue(SQueue &sq,ElemType x)		//Ԫ�ؽ����㷨
{	if (sq.count==MaxSize) return 0;	//����
	sq.count++;							//����Ԫ�ظ�����1
	sq.data[(sq.front+sq.count)%MaxSize]=x;
	return 1;
}
int DeQueue(SQueue &sq,ElemType &x)	//����Ԫ���㷨
{	if (sq.count==0) return 0;			//�ӿ�
	sq.count--;							//����Ԫ�ظ�����1
	sq.front=(sq.front+1)%MaxSize;
	x=sq.data[sq.front];
	return 1;
}
int GetHead(SQueue sq,ElemType &x)		//ȡ��ͷԪ���㷨
{	if (sq.count==0) return 0;			//�ӿ�
	x=sq.data[(sq.front+1)%MaxSize];
	return 1;
}
int QueueEmpty(SQueue sq)				//�жӿ��㷨
{	if (sq.count==0) return 1;			//�ӿշ���1
	else return 0;						//�Ӳ��շ���0
}
void main()
{	SQueue sq;
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
