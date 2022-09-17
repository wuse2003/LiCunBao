#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;					//������
	struct node *next;				//ָ����
} SLinkNode;						//����������
void InitList(SLinkNode *&L)		//LΪ�����Ͳ���
{	L=(SLinkNode *)malloc(sizeof(SLinkNode));
	L->next=L;
}
void DestroyList(SLinkNode *&L)
{	SLinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{	free(pre);
		pre=p; p=p->next;			//pre��pͬ������
	}
	free(pre);
}
int GetLength(SLinkNode *L)
{	int i=0;
	SLinkNode *p=L->next;
	while (p!=L)
	{	i++;
		p=p->next;
	}
	return i;
}
int GetElem(SLinkNode *L,int i,ElemType &e)
{	int j=1;
	SLinkNode *p=L->next;			//pָ���һ�����ݽ�㣬������j��Ϊ1
	if (i<=0) return 0;				//����i���󷵻�0
	while (p!=L && j<i)				//�ҵ�i�����p
	{	j++;
		p=p->next;
	}
	if (p==L) return 0;				//δ�ҵ�����0
	else
	{	e=p->data;
		return 1;					//�ҵ��󷵻�1
	}
}
int Locate(SLinkNode *L,ElemType x)	
{	int i=1;
	SLinkNode *p=L->next;
	while (p!=L && p->data!=x)		//�ӵ�1�����ݽ�㿪ʼ����data��Ϊx�Ľ��
	{	p=p->next;
		i++;
	}
	if (p==L) return 0;				//δ�ҵ�ֵΪx�Ľ�㷵��0
	else return i;					//�ҵ���һ��ֵΪx�Ľ�㷵�������
}
int InsElem(SLinkNode *&L,ElemType x,int i)	//�������㷨
{	int j=1;
	SLinkNode *pre=L,*p=pre->next,*s;
	if (i<=0) return 0;				//����i���󷵻�0
	while (p!=L && j<i)				//���ҵ�i�����p����ǰ�����pre
	{
		j++;
		pre=p; p=p->next;			//pre��pͬ������һ�����
	}
	if (p==L && i>j+1) return 0;	//����i>n+1ʱ���󷵻�0
	else							//�ɹ����ҵ���i������ǰ�����pre
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=x;					//�����½�����ڴ��Ԫ��x
		s->next=pre->next;			//��s�����뵽pre���֮��
		pre->next=s;
		return 1;					//��������ɹ�,����1
	}
}
int DelElem(SLinkNode *&L,int i)
{	int j=0;
	SLinkNode *p=L,*post;			//pָ��ͷ���
	if (i<=0) return 0;				//����i���󷵻�0
	while (p->next!=L && j<i-1)		//���ҵ�i-1�����p
	{	j++;
		p=p->next;
	}
	if (p->next==L) return 0;		//δ�ҵ�����0
	else
	{
		post=p->next;				//postָ��ɾ���
		if (post==L)
			return 0;				//û�е�i�����ʱ����0
		else
		{	p->next=post->next;		//�ӵ�������ɾ��post���
			free(post);				//�ͷ���ռ�
			return 1;				//�ɹ�ɾ������1
		}
	}
}
void DispList(SLinkNode *L)			//������Ա�
{	SLinkNode *p=L->next;
	while (p!=L)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//����ͷ�巨������㷨
void CreateListF(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//����ͷ���
	L->next=L;						//��Ϊһ���յ�ѭ��������
	for (i=0;i<n;i++)				//����a��������Ԫ��
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];				//�������a[i]Ԫ�ص��½��s
		s->next=L->next;			//�����s����ͷ���֮��
		L->next=s;
	}
}
//����β�巨������㷨
void CreateListR(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s,*tc;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//����ͷ���
	tc=L;							//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];				//�������a[i]Ԫ�ص��½��s
		tc->next=s;					//�����s����tc���֮��
		tc=s;
	}
	tc->next=L;						//��Ϊѭ��������
}
