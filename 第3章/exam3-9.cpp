#include "SqStack.cpp"				//包含前面的顺序栈基本运算函数
void trans(int d,char b[]) 
//b用于存放d转换成的二进制数的字符串
{	SqStack st;						//定义一个顺序栈st
	InitStack(st);					//栈初始化
	char ch;
	int i=0;
	while (d!=0)
	{
		ch='0'+d%2;					//求余数并转换为字符
		Push(st,ch);				//字符ch进栈
		d/=2;						//继续求更高位
	}
	while (!StackEmpty(st))
	{
		Pop(st,ch);					//出栈并存放在数组b中
		b[i]=ch;
		i++;
	}
	b[i]='\0';						//加入字符串结束标志
	DestroyStack(st);				//销毁栈st
}

void main()
{
	int d;
	char str[MaxSize];
	do
	{
		printf("输入一个正整数:");
		scanf("%d",&d);
	} while (d<0);
	trans(d,str);
	printf("对应的二进制数:%s\n",str);

}
