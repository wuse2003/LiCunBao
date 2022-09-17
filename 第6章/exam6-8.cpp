#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node *next;
} SLinkNode;
void CreateLink(SLinkNode *&L,int a[],int n)	//����β�巨��������ͷ���ĵ�����L
{
	int i;
	SLinkNode *p,*tc;
	if (n>=1)		//���ٽ���һ�����
	{
		L=(SLinkNode *)malloc(sizeof(SLinkNode));
		L->data=a[0];
		tc=L;
		for (i=1;i<n;i++)
		{
			p=(SLinkNode *)malloc(sizeof(SLinkNode));
			p->data=a[i];
			tc->next=p;
			tc=p;
		}
		tc->next=NULL;
	}
	else L=NULL;
}
void DispLink(SLinkNode *L)		//�������ͷ���ĵ�����L
{
	SLinkNode *p=L;
	while (p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void DestroyLink(SLinkNode *L)		//���ٲ���ͷ���ĵ�����L
{
	SLinkNode *pre=L,*p;
	if (pre!=NULL)
	{
		if (pre->next==NULL)	//ֻ��һ�����
			free(pre);
		else
		{
			p=pre->next;
			while (p!=NULL)
			{
				free(pre);
				pre=p;
				p=p->next;
			}
			free(pre);
		}
	}
}
int f1(SLinkNode *L)
{	int m;
	if (L->next==NULL)
		return L->data;
	else
	{	m=f1(L->next);			//�ݹ���С����Ľ�
		if (m>L->data) return m;
		else return L->data;
	}
}
int f2(SLinkNode *L)
{	int m;
	if (L->next==NULL)
		return L->data;
	else
	{	m=f1(L->next);		//�ݹ���С����Ľ�
		if (m<L->data) return m;
		else return L->data;
	}
}
void f3(SLinkNode *L)
{	if (L!=NULL)
	{	printf("%d ",L->data);
		f3(L->next);
	}
}
void f4(SLinkNode *L)
{	if (L!=NULL)
	{	f4(L->next);
		printf("%d ",L->data);
	}
}
void main()
{
	SLinkNode *L;
	int a[]={1,2,3,4,5};
	int n=5;
	CreateLink(L,a,n);
	printf("������L:"); DispLink(L);
	printf("��1�������Ľ��ֵ:%d\n",f1(L));
	printf("��2������С�Ľ��ֵ:%d\n",f2(L));
	printf("��3������������н��ֵ:");f3(L);printf("\n");
	printf("��4������������н��ֵ:");f4(L);printf("\n");
	DestroyLink(L);
}