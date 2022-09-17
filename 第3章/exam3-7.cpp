#include <string.h>
#include "SqStack.cpp"			//包含前面的顺序栈基本运算函数
int Palindrome(char str[],int n)
{	SqStack st;					//定义一个顺序栈st
	InitStack(st);				//栈初始化
	int i;
	char ch;
	for (i=0;i<n;i++)			//所有字符依次进栈
		Push(st,str[i]);
	i=0;						//从头开始遍历str
	while (!StackEmpty(st))		//栈不空循环
	{	Pop(st,ch);				//出栈元素ch
		if (ch!=str[i++])		//两字符不相同时返回0
		{	DestroyStack(st);
			return 0;
		}
	}
	DestroyStack(st);
	return 1;					//所有相应字符都相同时返回1
}
void display(char exp[])
{
	int n=strlen(exp);
	printf("字符串%s",exp);
	if (Palindrome(exp,n))
		printf("是回文\n");
	else
		printf("不是回文\n");
}
void main()
{
	char exp1[]="abba";
	display(exp1);
	char exp2[]="abcba";
	display(exp2);
	char exp3[]="abc";
	display(exp3);
	char exp4[]="abcb";
	display(exp4);
	char exp5[]="bbb";
	display(exp5);
}
