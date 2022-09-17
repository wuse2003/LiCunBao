#include <string.h>
#include "SqStack.cpp"					//����ǰ���˳��ջ�������㺯��
int Match(char exp[],int n)				//exp��ű��ʽ
{	SqStack st;							//����һ��˳��ջst
	InitStack(st);						//ջ��ʼ��
	int flag=1,i=0;
	char ch;
	while (i<n && flag==1)				//�������ʽexp
	{	switch(exp[i])
		{
		case '(': case '[': case '{':	//���������Ž�ջ
			Push(st,exp[i]); break;
		case ')':						//�ж�ջ���Ƿ�Ϊ'('
			if (!Pop(st,ch) || ch!='(')	//��ջ����ʧ�ܻ��߲�wƥ��
				flag=0;
			break;
		case ']':						//�ж�ջ���Ƿ�Ϊ'['
			if (!Pop(st,ch) || ch!='[')	//��ջ����ʧ�ܻ��߲�wƥ��
				flag=0;
			break;
		case '}':						//�ж�ջ���Ƿ�Ϊ'{'
			if (!Pop(st,ch) || ch!='{')	//��ջ����ʧ�ܻ��߲�wƥ��
				flag=0;
			break;
		}
		i++;
	}
	if (StackEmpty(st) && flag==1)		//ջ���ҷ���ƥ���򷵻�1
	{
		DestroyStack(st);				//����ջst
		return 1;
	}
	else
	{
		DestroyStack(st);				//����ջst
		return 0;						//���򷵻�0
	}
}
void display(char exp[])
{
	int n=strlen(exp);
	if (Match(exp,n))
		printf("  %s��ƥ��ı��ʽ\n",exp);
	else
		printf("  %s����ƥ��ı��ʽ\n",exp);
}
void main()
{
	char str1[]="[(])";
	char str2[]="[()]";
	char str3[]="[()])";
	char str4[]="([()]";
	printf("�жϽ������:\n");
	display(str1);
	display(str2);
	display(str3);
	display(str4);

}
