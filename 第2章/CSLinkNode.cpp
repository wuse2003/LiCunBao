#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{	ElemType data;					//数据域
	struct node *next;				//指针域
} SLinkNode;						//单链表类型
void InitList(SLinkNode *&L)		//L为引用型参数
{	L=(SLinkNode *)malloc(sizeof(SLinkNode));
	L->next=L;
}
void DestroyList(SLinkNode *&L)
{	SLinkNode *pre=L,*p=pre->next;
	while (p!=L)
	{	free(pre);
		pre=p; p=p->next;			//pre、p同步后移
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
	SLinkNode *p=L->next;			//p指向第一个数据结点，计数器j置为1
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=L && j<i)				//找第i个结点p
	{	j++;
		p=p->next;
	}
	if (p==L) return 0;				//未找到返回0
	else
	{	e=p->data;
		return 1;					//找到后返回1
	}
}
int Locate(SLinkNode *L,ElemType x)	
{	int i=1;
	SLinkNode *p=L->next;
	while (p!=L && p->data!=x)		//从第1个数据结点开始查找data域为x的结点
	{	p=p->next;
		i++;
	}
	if (p==L) return 0;				//未找到值为x的结点返回0
	else return i;					//找到第一个值为x的结点返回其序号
}
int InsElem(SLinkNode *&L,ElemType x,int i)	//插入结点算法
{	int j=1;
	SLinkNode *pre=L,*p=pre->next,*s;
	if (i<=0) return 0;				//参数i错误返回0
	while (p!=L && j<i)				//查找第i个结点p和其前驱结点pre
	{
		j++;
		pre=p; p=p->next;			//pre、p同步后移一个结点
	}
	if (p==L && i>j+1) return 0;	//参数i>n+1时错误返回0
	else							//成功查找到第i个结点的前驱结点pre
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=x;					//创建新结点用于存放元素x
		s->next=pre->next;			//将s结点插入到pre结点之后
		pre->next=s;
		return 1;					//插入运算成功,返回1
	}
}
int DelElem(SLinkNode *&L,int i)
{	int j=0;
	SLinkNode *p=L,*post;			//p指向头结点
	if (i<=0) return 0;				//参数i错误返回0
	while (p->next!=L && j<i-1)		//查找第i-1个结点p
	{	j++;
		p=p->next;
	}
	if (p->next==L) return 0;		//未找到返回0
	else
	{
		post=p->next;				//post指向被删结点
		if (post==L)
			return 0;				//没有第i个结点时返回0
		else
		{	p->next=post->next;		//从单链表中删除post结点
			free(post);				//释放其空间
			return 1;				//成功删除返回1
		}
	}
}
void DispList(SLinkNode *L)			//输出线性表
{	SLinkNode *p=L->next;
	while (p!=L)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//采用头插法建表的算法
void CreateListF(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));		//创建头结点
	L->next=L;						//置为一个空的循环单链表
	for (i=0;i<n;i++)				//遍历a数组所有元素
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];				//创建存放a[i]元素的新结点s
		s->next=L->next;			//将结点s插在头结点之后
		L->next=s;
	}
}
//采用尾插法建表的算法
void CreateListR(SLinkNode *&L,ElemType a[],int n)
{	SLinkNode *s,*tc;  int i;
	L=(SLinkNode *)malloc(sizeof(SLinkNode));	//创建头结点
	tc=L;							//tc始终指向尾结点,开始时指向头结点
	for (i=0;i<n;i++)
	{	s=(SLinkNode *)malloc(sizeof(SLinkNode));
		s->data=a[i];				//创建存放a[i]元素的新结点s
		tc->next=s;					//将结点s插入tc结点之后
		tc=s;
	}
	tc->next=L;						//置为循环单链表
}
