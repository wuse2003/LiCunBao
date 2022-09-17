#include <string.h>
#include "SqStack.cpp"					//包含前面的顺序栈基本运算函数
int Match(char exp[],int n)				//exp存放表达式
{	SqStack st;							//定义一个顺序栈st
	InitStack(st);						//栈初始化
	int flag=1,i=0;
	char ch;
	while (i<n && flag==1)				//遍历表达式exp
	{	switch(exp[i])
		{
		case '(': case '[': case '{':	//各种左括号进栈
			Push(st,exp[i]); break;
		case ')':						//判断栈顶是否为'('
			if (!Pop(st,ch) || ch!='(')	//出栈操作失败或者不w匹配
				flag=0;
			break;
		case ']':						//判断栈顶是否为'['
			if (!Pop(st,ch) || ch!='[')	//出栈操作失败或者不w匹配
				flag=0;
			break;
		case '}':						//判断栈顶是否为'{'
			if (!Pop(st,ch) || ch!='{')	//出栈操作失败或者不w匹配
				flag=0;
			break;
		}
		i++;
	}
	if (StackEmpty(st) && flag==1)		//栈空且符号匹配则返回1
	{
		DestroyStack(st);				//销毁栈st
		return 1;
	}
	else
	{
		DestroyStack(st);				//销毁栈st
		return 0;						//否则返回0
	}
}
void display(char exp[])
{
	int n=strlen(exp);
	if (Match(exp,n))
		printf("  %s是匹配的表达式\n",exp);
	else
		printf("  %s不是匹配的表达式\n",exp);
}
void main()
{
	char str1[]="[(])";
	char str2[]="[()]";
	char str3[]="[()])";
	char str4[]="([()]";
	printf("判断结果如下:\n");
	display(str1);
	display(str2);
	display(str3);
	display(str4);

}
