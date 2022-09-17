#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;					//数据域
	struct node *prior,*next;		//分别指向前驱结点和后继结点的指针
} DLinkNode;						//双链表结点类型

void InitList(DLinkNode *&L)
{	L=(DLinkNode *)malloc(sizeof(DLinkNode));
	L->prior=L->next=L;
}

void DestroyList(DLinkNode *&L)
{	DLinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{	free(pre);
		pre=p; p=p->next;			//pre、p同步后移
	}
	free(pre);
}
int GetLength(DLinkNode *L)			//求表长运算
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
	DLinkNode *p=L->next;			//p指向第一个数据结点，计数器j置为1
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=L && j<i)
	{	j++;
		p=p->next;
	}
	if (p==L) return 0;				//未找到返回0
	else
	{	e=p->data;
		return 1;					//找到后返回1
	}
}

int Locate(DLinkNode *L,ElemType x)	
{	int i=1;
	DLinkNode *p=L->next;
	while (p!=L && p->data!=x)		//从第1个结点开始查找data域为x的结点
	{	p=p->next;
		i++;
	}
	if (p==L) return 0;
	else return i;
}

int InsElem(DLinkNode *&L,ElemType x,int i)	//插入结点算法
{	int j=1;
	DLinkNode *p=L->next,*pre,*s;	//p从第一个数据结点开始
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=L && j<i)				//查找第i个结点p
	{
		j++;
		p=p->next;
	}
	if (p==L && i>j+1) return 0;	//参数i错误返回0
	else							//成功查找到第i个结点p
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=x;					//创建新结点s用于存放元素x
		pre=p->prior;				//将s结点插入到pre结点之后
		s->prior=pre;
		pre->next=s;
		p->prior=s;
		s->next=p;
		return 1;					//插入运算成功,返回1
	}
}
int DelElem(DLinkNode *&L,int i)	//删除结点
{	int j=1;
	DLinkNode *p=L->next,*pre;		//p从第一个数据结点开始
	if (i<=0) return 0;				//参数i错误返回0
	if (L->next==L) return 0;		//空表不能删除，返回0
	while (p!=L && j<i)				//查找第i个结点p
	{	j++;
		p=p->next;
	}
	if (p==L) return 0;				//未找到第i个结点返回0
	else
	{	pre=p->prior;				//pre指向被删结点的前驱结点
		p->next->prior=pre;
		pre->next=p->next;
		free(p);					//释放其空间
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

//采用头插法建表的算法
void CreateListF(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));		//创建头结点
	L->next=L;
	L->prior=L;
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新结点
		s->data=a[i];
		s->next=L->next;					//将结点s插在头结点之后
		L->next->prior=s;
		L->next=s;
		s->prior=L;
	}
}
//采用尾插法建表的算法
void CreateListR(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s,*tc;
	int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建头结点
	tc=L;									//tc始终指向尾结点,开始时指向头结点
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新结点
		s->data=a[i];
		tc->next=s;							//将结点s插入tc之后
		s->prior=tc;
		tc=s;
	}
	tc->next=L;								//置为循环双链表
	L->prior=tc;
}

