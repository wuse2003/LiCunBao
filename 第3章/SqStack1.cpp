#include <stdio.h>
#define MaxSize 100				//顺序栈的初始分配空间大小
typedef int ElemType;			//假设顺序栈中所有元素为int类型
typedef struct
{	ElemType data[MaxSize];		//保存栈中元素
	int top;					//栈顶指针
} SqStack;

void InitStack(SqStack &st)		//st为引用型参数
{
	st.top=-1;
}
void DestroyStack(SqStack st)
{    }

int Push(SqStack &st,ElemType x)
{	if (st.top==MaxSize-1)	//栈满
		return 0;
	else
	{	st.top++;
		st.data[st.top]=x;
		return 1;
	}
}

int Pop(SqStack &st,ElemType &x)	//x为引用型参数
{	if (st.top==-1)					//栈空
		return 0;
	else 
	{	x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st,ElemType &x)	//x为引用型参数
{	if (st.top==-1)					//栈空
		return 0;
	else 
	{	x=st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st)
{	if (st.top==-1) return 1;
	else return 0;
}
