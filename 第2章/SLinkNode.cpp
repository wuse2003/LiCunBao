#include <malloc.h>
#include <stdio.h>
typedef int ElemType;
typedef struct node
{	ElemType data;		//������
	struct node *next;	//ָ����
} SLinkNode;				//����������
void InitList(SLinkNode *&L)				//L��Ϊ�����Ͳ���
{	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//����ͷ���*L
	L->next=NULL;
}
void DestroyList(SLinkNode *&L)
{	SLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre��pͬ������
	}
	free(pre);
}
int GetLength(SLinkNode *L)
{	int i=0;
	SLinkNode *p=L->next;
	while (p!=NULL)
	{	i++;
		p=p->next;
	}
	return i;
}
int GetElem(SLinkNode *L,int i,ElemType &e)
{	int j=0;
	SLinkNode *p=L;				//pָ��ͷ��㣬������j��Ϊ0
	if (i<=0) return 0;		//����i���󷵻�0
	while (p!=NULL && j<i)
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;				//δ�ҵ�����0
	else
	{	e=p->data;
		return 1;				//�ҵ��󷵻�1
	}
}
int Locate(SLinkNode *L,ElemType e)	
{	SLinkNode *p=L->next;
	int j=1;						//pָ���һ�����ݽ�㣬j��Ϊ�����1
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		j++;
	}
	if (p==NULL) return(0);			//δ�ҵ�����0
	else return(j);					//�ҵ��󷵻������
}
int InsElem(SLinkNode *&L,ElemType x,int i)	//������ֵΪx�Ľ��
{	int j=0;
	SLinkNode *p=L,*s;
	if (i<=0) return 0;			//����i���󷵻�0
	while (p!=NULL && j<i-1)	//���ҵ�i-1�����*p
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;				//δ�ҵ���i-1�����ʱ����0
	else						//�ҵ���i-1�����*p
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=x;				//�������Ԫ��x���½��*s
		s->next=p->next;		//��*s�����뵽*p���֮��
		p->next=s;
		return 1;				//��������ɹ�,����1
	}
}
int DelElem(SLinkNode *&L,int i)	//ɾ�����
{	int j=0;
	SLinkNode *p=L,*q;
	if (i<=0) return 0;			//����i���󷵻�0
	while (p!=NULL && j<i-1)	//���ҵ�i-1�����
	{	j++;
		p=p->next;
	}
	if (p==NULL)
		return 0;				//δ�ҵ���i-1�����ʱ����0
	else						//�ҵ���i-1�����*p
	{	q=p->next;				//qָ��ɾ���
		if (q==NULL)
			return 0;			//û�е�i�����ʱ����0
		else
		{	p->next=q->next;	//�ӵ�������ɾ��*q���
			free(q);			//�ͷ���ռ�
			return 1;
		}
	}
}
void DispList(SLinkNode *L)		//���������
{	SLinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
//����ͷ�巨������㷨
void CreateListF(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//����ͷ���
	L->next=NULL;			//ͷ����next���ÿգ���ʾһ���յ�����
	for (i=0;i<n;i++)		//����a��������Ԫ��
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];		//�������a[i]Ԫ�ص��½��*s
		s->next=L->next;	//��*s����ͷ���֮��
		L->next=s;
	}
}
//����β�巨������㷨
void CreateListR(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s,*tc;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//����ͷ���
	tc=L;						//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];			//�������a[i]Ԫ�ص��½��*s
		tc->next=s;				//��*s����*tc֮��
		tc=s;
	}
	tc->next=NULL;				//β���next����ΪNULL
}
