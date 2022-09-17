#include <stdio.h>
#include <malloc.h>
typedef char ElemType;			//������ջ������Ԫ��Ϊchar����
typedef struct node
{	ElemType data;				//�洢�������
	struct node *next;			//ָ����
} LinkStack;


void InitStack(LinkStack *&ls)	//lsΪ�����Ͳ���
{
	ls=NULL;
}

void DestroyStack(LinkStack *&ls)
{	LinkStack *pre=ls,*p;
	if (pre==NULL) return;
	p=pre->next;
	while (p!=NULL)
	{	free(pre);				//�ͷ�pre���
		pre=p;p=p->next;		//pre��pͬ������
	}
	free(pre);					//�ͷ�β���
}

int Push(LinkStack *&ls,ElemType x)	//lsΪ�����Ͳ���
{	LinkStack *p;
	p=(LinkStack *)malloc(sizeof(LinkStack));
	p->data=x;					//�������p���ڴ��x
	p->next=ls;					//����p�����Ϊջ�����
	ls=p;
	return 1;
}

int Pop(LinkStack *&ls,ElemType &x)	//lsΪ�����Ͳ���
{	LinkStack *p;
	if (ls==NULL) 				//ջ��,���������0
		return 0;
	else						//ջ����ʱ��ջԪ��x������1
	{	p=ls;					//pָ��ջ�����
		x=p->data;				//ȡջ��Ԫ��x
		ls=p->next;				//ɾ�����p
		free(p);				//�ͷ�p���
		return 1;
	}
}

int GetTop(LinkStack *ls,ElemType &x)
{	if (ls==NULL)				//ջ��,�����ʱ����0
		return 0;
	else						//ջ����,ȡջ��Ԫ��x������1
	{	x=ls->data;
		return 1;
	}
}

int StackEmpty(LinkStack *ls)
{	if (ls==NULL) return 1;
	else return 0;
}
