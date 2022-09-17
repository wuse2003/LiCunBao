#include "Sqstack.cpp"				//包含前面的顺序栈基本运算函数
int Judge(char str[],int n)
{
	int i; ElemType x;
	SqStack st;						//定义一个顺序栈st
	InitStack(st);					//栈初始化
	for (i=0;i<n;i++)				//遍历str的所有字符
	{	if (str[i]=='I')			//为'I'时进栈
			Push(st,str[i]);
		else if (str[i]=='O')		//为'O'时出栈
			if (!Pop(st,x))			//若栈下溢出，则返回0
			{	DestroyStack(st);
				return 0;
			}
	}
	DestroyStack(st);
	return StackEmpty(st);		//栈为空时返回1；否则返回0
}
void main()
{
	char A[]="IOIIOIOO";
	char B[]="IOOIOIIO";
	char C[]="IIIOIOIO";
	char D[]="IIIOOIOO";
	if (Judge(A,8))
		printf("A是合法操作序列\n");
	else
		printf("A是不合法操作序列\n");
	if (Judge(B,8))
		printf("B是合法操作序列\n");
	else
		printf("B是不合法操作序列\n");
	if (Judge(C,8))
		printf("C是合法操作序列\n");
	else
		printf("C是不合法操作序列\n");
	if (Judge(D,8))
		printf("D是合法操作序列\n");
	else
		printf("D是不合法操作序列\n");
}
