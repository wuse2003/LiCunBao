#include "SqStack.cpp"	//包含前面的顺序栈基本运算函数
void main()
{	SqStack st;
	ElemType e;
	printf("初始化栈st\n");
	InitStack(st);
	printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
	printf("a进栈\n");Push(st,'a');
	printf("b进栈\n");Push(st,'b');
	printf("c进栈\n");Push(st,'c');
	printf("d进栈\n");Push(st,'d');
	printf("栈%s\n",(StackEmpty(st)==1?"空":"不空"));
	GetTop(st,e);
	printf("栈顶元素:%c\n",e);
	printf("出栈次序:");
	while (!StackEmpty(st))		//栈不空循环
	{	Pop(st,e);				//出栈元素e并输出
		printf("%c ",e);
	}
	printf("\n");
	DestroyStack(st);
}
