#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;					//������
	struct node *prior,*next;		//�ֱ�ָ��ǰ�����ͺ�̽���ָ��
} DLinkNode;						//˫����������

void InitList(DLinkNode *&L)
{	L=(DLinkNode *)malloc(sizeof(DLinkNode));
	L->prior=L->next=L;
}

void DestroyList(DLinkNode *&L)
{	DLinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{	free(pre);
		pre=p; p=p->next;			//pre��pͬ������
	}
	free(pre);
}
int GetLength(DLinkNode *L)			//�������
{	int i=0;
	DLinkNode *p=L->next;
	while (p!=L)
	{	i++;
		p=p->next;
	}
	return i;
}

int GetElem(DLinkNode *L,int i,ElemType &e)
{	int j=1;
	DLinkNode *p=L->next;			//pָ���һ�����ݽ�㣬������j��Ϊ1
	if (i<=0) return 0;				//����i���󷵻�0
	while (p!=L && j<i)
	{	j++;
		p=p->next;
	}
	if (p==L) return 0;				//δ�ҵ�����0
	else
	{	e=p->data;
		return 1;					//�ҵ��󷵻�1
	}
}

int Locate(DLinkNode *L,ElemType x)	
{	int i=1;
	DLinkNode *p=L->next;
	while (p!=L && p->data!=x)		//�ӵ�1����㿪ʼ����data��Ϊx�Ľ��
	{	p=p->next;
		i++;
	}
	if (p==L) return 0;
	else return i;
}

int InsElem(DLinkNode *&L,ElemType x,int i)	//�������㷨
{	int j=1;
	DLinkNode *p=L->next,*pre,*s;	//p�ӵ�һ�����ݽ�㿪ʼ
	if (i<=0) return 0;				//����i���󷵻�0
	while (p!=L && j<i)				//���ҵ�i�����p
	{
		j++;
		p=p->next;
	}
	if (p==L && i>j+1) return 0;	//����i���󷵻�0
	else							//�ɹ����ҵ���i�����p
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=x;					//�����½��s���ڴ��Ԫ��x
		pre=p->prior;				//��s�����뵽pre���֮��
		s->prior=pre;
		pre->next=s;
		p->prior=s;
		s->next=p;
		return 1;					//��������ɹ�,����1
	}
}
int DelElem(DLinkNode *&L,int i)	//ɾ�����
{	int j=1;
	DLinkNode *p=L->next,*pre;		//p�ӵ�һ�����ݽ�㿪ʼ
	if (i<=0) return 0;				//����i���󷵻�0
	if (L->next==L) return 0;		//�ձ���ɾ��������0
	while (p!=L && j<i)				//���ҵ�i�����p
	{	j++;
		p=p->next;
	}
	if (p==L) return 0;				//δ�ҵ���i����㷵��0
	else
	{	pre=p->prior;				//preָ��ɾ����ǰ�����
		p->next->prior=pre;
		pre->next=p->next;
		free(p);					//�ͷ���ռ�
		return 1;
	}
}
void DispList(DLinkNode *L)
{	DLinkNode *p=L->next;
	while (p!=L)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//����ͷ�巨������㷨
void CreateListF(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));		//����ͷ���
	L->next=L;
	L->prior=L;
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��
		s->data=a[i];
		s->next=L->next;					//�����s����ͷ���֮��
		L->next->prior=s;
		L->next=s;
		s->prior=L;
	}
}
//����β�巨������㷨
void CreateListR(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s,*tc;
	int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//����ͷ���
	tc=L;									//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½��
		s->data=a[i];
		tc->next=s;							//�����s����tc֮��
		s->prior=tc;
		tc=s;
	}
	tc->next=L;								//��Ϊѭ��˫����
	L->prior=tc;
}

