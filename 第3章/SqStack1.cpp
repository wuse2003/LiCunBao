#include <stdio.h>
#define MaxSize 100				//˳��ջ�ĳ�ʼ����ռ��С
typedef int ElemType;			//����˳��ջ������Ԫ��Ϊint����
typedef struct
{	ElemType data[MaxSize];		//����ջ��Ԫ��
	int top;					//ջ��ָ��
} SqStack;

void InitStack(SqStack &st)		//stΪ�����Ͳ���
{
	st.top=-1;
}
void DestroyStack(SqStack st)
{    }

int Push(SqStack &st,ElemType x)
{	if (st.top==MaxSize-1)	//ջ��
		return 0;
	else
	{	st.top++;
		st.data[st.top]=x;
		return 1;
	}
}

int Pop(SqStack &st,ElemType &x)	//xΪ�����Ͳ���
{	if (st.top==-1)					//ջ��
		return 0;
	else 
	{	x=st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st,ElemType &x)	//xΪ�����Ͳ���
{	if (st.top==-1)					//ջ��
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
