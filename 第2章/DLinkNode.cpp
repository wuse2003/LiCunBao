#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;				//������
	struct node *prior,*next;	//�ֱ�ָ��ǰ�����ͺ�̽���ָ��
} DLinkNode;						//˫����������

void InitList(DLinkNode *&L)
{	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//����ͷ���*L
	L->prior=L->next=NULL;
}
void DestroyList(DLinkNode *&L)
{	DLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre��pͬ������
	}
	free(pre);
}
int GetLength(DLinkNode *L)	
{	int i=0;
	DLinkNode *p=L->next;		//pָ���һ�����ݽ��
	while (p!=NULL)
	{	i++;				//i�ۼ����ݽ�����
		p=p->next;
	}
	return i;
}
int GetElem(DLinkNode *L,int i,ElemType &e)
{	int j=0;
	DLinkNode *p=L;					//pָ��ͷ��㣬������j��Ϊ0
	if (i<=0) return 0;			//����i���󷵻�0
	while (p!=NULL && j<i)
	{	j++;
		p=p->next;
	}
	if (p==NULL) return 0;		//δ�ҵ�����0
	else
	{	e=p->data;
		return 1;				//�ҵ��󷵻�1
	}
}
int Locate(DLinkNode *L,ElemType e)	
{	DLinkNode *p=L->next;
	int i=1;						//pָ��3��һ�����ݽ�㣬i��Ϊ�����1
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		i++;
	}
	if (p==NULL) return 0;			//δ�ҵ�����0
	else return i;					//�ҵ��󷵻������
}
int InsElem(DLinkNode *&L,ElemType x,int i)
{	int j=0;
	DLinkNode *p=L,*s;
	if (i<=0) return 0;			//����i���󷵻�0
	while (p!=NULL && j<i-1)	//���ҵ�i-1�����*p
	{	j++;
		p=p->next;
	}
	if (p==NULL) return 0;		//δ�ҵ�����0
	else
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=x;				//����һ�����Ԫ��x���½��
		s->next=p->next;		//��Ӧ��������Ĳ����
		if (p->next!=NULL)		//��Ӧ��������Ĳ����
			p->next->prior=s;
		s->prior=p;				//��Ӧ��������Ĳ����
		p->next=s;				//��Ӧ��������Ĳ����
		return 1;				//��������ɹ�,����1
	}
}
int DelElem(DLinkNode *&L,int i)		//ɾ�����
{	int j=0;
	DLinkNode *p=L,*pre;
	if (i<=0) return 0;				//����i���󷵻�0
	while (p!=NULL && j<i)			//���ҵ�i�����*p
	{	j++;
		p=p->next;
	}
	if (p==NULL) return 0;			//δ�ҵ�����0
	else
	{	pre=p->prior;				//preָ��ɾ����ǰ�����
		if (p->next!=NULL)			//�ӵ�������ɾ��*p���
			p->next->prior=pre;
		pre->next=p->next;
		free(p);					//�ͷ���ռ�
		return 1;
	}
}
void DispList(DLinkNode *L)
{	DLinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
//����ͷ�巨������㷨
void CreateListF(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));		//����ͷ���
	L->next=NULL;
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��
		s->data=a[i];
		s->next=L->next;							//�����s����ͷ���֮��
		s->prior=L;
		if (s->next!=NULL)
			s->next->prior=s;
		L->next=s;
	}
}
//����β�巨������㷨
void CreateListR(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s,*tc;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//����ͷ���
	tc=L;										//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��
		s->data=a[i];
		tc->next=s;								//��s����tc֮��
		s->prior=tc;
		tc=s;
	}
	tc->next=NULL;								//β���next����ΪNULL
}

