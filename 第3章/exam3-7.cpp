#include <string.h>
#include "SqStack.cpp"			//����ǰ���˳��ջ�������㺯��
int Palindrome(char str[],int n)
{	SqStack st;					//����һ��˳��ջst
	InitStack(st);				//ջ��ʼ��
	int i;
	char ch;
	for (i=0;i<n;i++)			//�����ַ����ν�ջ
		Push(st,str[i]);
	i=0;						//��ͷ��ʼ����str
	while (!StackEmpty(st))		//ջ����ѭ��
	{	Pop(st,ch);				//��ջԪ��ch
		if (ch!=str[i++])		//���ַ�����ͬʱ����0
		{	DestroyStack(st);
			return 0;
		}
	}
	DestroyStack(st);
	return 1;					//������Ӧ�ַ�����ͬʱ����1
}
void display(char exp[])
{
	int n=strlen(exp);
	printf("�ַ���%s",exp);
	if (Palindrome(exp,n))
		printf("�ǻ���\n");
	else
		printf("���ǻ���\n");
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
