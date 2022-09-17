#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;				//数据域
	struct node *prior,*next;	//分别指向前趋结点和后继结点的指针
} DLinkNode;						//双链表结点类型

void InitList(DLinkNode *&L)
{	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建头结点*L
	L->prior=L->next=NULL;
}
void DestroyList(DLinkNode *&L)
{	DLinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre、p同步后移
	}
	free(pre);
}
int GetLength(DLinkNode *L)	
{	int i=0;
	DLinkNode *p=L->next;		//p指向第一个数据结点
	while (p!=NULL)
	{	i++;				//i累加数据结点个数
		p=p->next;
	}
	return i;
}
int GetElem(DLinkNode *L,int i,ElemType &e)
{	int j=0;
	DLinkNode *p=L;					//p指向头结点，计数器j置为0
	if (i<=0) return 0;			//参数i错误返回0
	while (p!=NULL && j<i)
	{	j++;
		p=p->next;
	}
	if (p==NULL) return 0;		//未找到返回0
	else
	{	e=p->data;
		return 1;				//找到后返回1
	}
}
int Locate(DLinkNode *L,ElemType e)	
{	DLinkNode *p=L->next;
	int i=1;						//p指向3第一个数据结点，i置为其序号1
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		i++;
	}
	if (p==NULL) return 0;			//未找到返回0
	else return i;					//找到后返回其序号
}
int InsElem(DLinkNode *&L,ElemType x,int i)
{	int j=0;
	DLinkNode *p=L,*s;
	if (i<=0) return 0;			//参数i错误返回0
	while (p!=NULL && j<i-1)	//查找第i-1个结点*p
	{	j++;
		p=p->next;
	}
	if (p==NULL) return 0;		//未找到返回0
	else
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));
		s->data=x;				//创建一个存放元素x的新结点
		s->next=p->next;		//对应插入操作的步骤①
		if (p->next!=NULL)		//对应插入操作的步骤②
			p->next->prior=s;
		s->prior=p;				//对应插入操作的步骤③
		p->next=s;				//对应插入操作的步骤④
		return 1;				//插入运算成功,返回1
	}
}
int DelElem(DLinkNode *&L,int i)		//删除结点
{	int j=0;
	DLinkNode *p=L,*pre;
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=NULL && j<i)			//查找第i个结点*p
	{	j++;
		p=p->next;
	}
	if (p==NULL) return 0;			//未找到返回0
	else
	{	pre=p->prior;				//pre指向被删结点的前趋结点
		if (p->next!=NULL)			//从单链表中删除*p结点
			p->next->prior=pre;
		pre->next=p->next;
		free(p);					//释放其空间
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
//采用头插法建表的算法
void CreateListF(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));		//创建头结点
	L->next=NULL;
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新结点
		s->data=a[i];
		s->next=L->next;							//将结点s插在头结点之后
		s->prior=L;
		if (s->next!=NULL)
			s->next->prior=s;
		L->next=s;
	}
}
//采用尾插法建表的算法
void CreateListR(DLinkNode *&L,ElemType a[],int n)
{	DLinkNode *s,*tc;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建头结点
	tc=L;										//tc始终指向尾结点,开始时指向头结点
	for (i=0;i<n;i++)
	{	s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新结点
		s->data=a[i];
		tc->next=s;								//将s插入tc之后
		s->prior=tc;
		tc=s;
	}
	tc->next=NULL;								//尾结点next域置为NULL
}

