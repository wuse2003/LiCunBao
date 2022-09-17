#include <stdio.h>
#include <malloc.h>
typedef char ElemType;			//假设链栈中所有元素为char类型
typedef struct node
{	ElemType data;				//存储结点数据
	struct node *next;			//指针域
} LinkStack;


void InitStack(LinkStack *&ls)	//ls为引用型参数
{
	ls=NULL;
}

void DestroyStack(LinkStack *&ls)
{	LinkStack *pre=ls,*p;
	if (pre==NULL) return;
	p=pre->next;
	while (p!=NULL)
	{	free(pre);				//释放pre结点
		pre=p;p=p->next;		//pre、p同步后移
	}
	free(pre);					//释放尾结点
}

int Push(LinkStack *&ls,ElemType x)	//ls为引用型参数
{	LinkStack *p;
	p=(LinkStack *)malloc(sizeof(LinkStack));
	p->data=x;					//创建结点p用于存放x
	p->next=ls;					//插入p结点作为栈顶结点
	ls=p;
	return 1;
}

int Pop(LinkStack *&ls,ElemType &x)	//ls为引用型参数
{	LinkStack *p;
	if (ls==NULL) 				//栈空,下溢出返回0
		return 0;
	else						//栈不空时出栈元素x并返回1
	{	p=ls;					//p指向栈顶结点
		x=p->data;				//取栈顶元素x
		ls=p->next;				//删除结点p
		free(p);				//释放p结点
		return 1;
	}
}

int GetTop(LinkStack *ls,ElemType &x)
{	if (ls==NULL)				//栈空,下溢出时返回0
		return 0;
	else						//栈不空,取栈顶元素x并返回1
	{	x=ls->data;
		return 1;
	}
}

int StackEmpty(LinkStack *ls)
{	if (ls==NULL) return 1;
	else return 0;
}
