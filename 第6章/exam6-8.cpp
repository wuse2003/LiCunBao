#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node *next;
} SLinkNode;
void CreateLink(SLinkNode *&L,int a[],int n)	//采用尾插法建立不带头结点的单链表L
{
	int i;
	SLinkNode *p,*tc;
	if (n>=1)		//至少建立一个结点
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
void DispLink(SLinkNode *L)		//输出不带头结点的单链表L
{
	SLinkNode *p=L;
	while (p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void DestroyLink(SLinkNode *L)		//销毁不带头结点的单链表L
{
	SLinkNode *pre=L,*p;
	if (pre!=NULL)
	{
		if (pre->next==NULL)	//只有一个结点
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
	{	m=f1(L->next);			//递归求小问题的解
		if (m>L->data) return m;
		else return L->data;
	}
}
int f2(SLinkNode *L)
{	int m;
	if (L->next==NULL)
		return L->data;
	else
	{	m=f1(L->next);		//递归求小问题的解
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
	printf("单链表L:"); DispLink(L);
	printf("（1）求最大的结点值:%d\n",f1(L));
	printf("（2）求最小的结点值:%d\n",f2(L));
	printf("（3）正向输出所有结点值:");f3(L);printf("\n");
	printf("（4）反向输出所有结点值:");f4(L);printf("\n");
	DestroyLink(L);
}