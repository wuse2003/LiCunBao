#include "SqStack.cpp"				//����ǰ���˳��ջ�������㺯��
void trans(int d,char b[]) 
//b���ڴ��dת���ɵĶ����������ַ���
{	SqStack st;						//����һ��˳��ջst
	InitStack(st);					//ջ��ʼ��
	char ch;
	int i=0;
	while (d!=0)
	{
		ch='0'+d%2;					//��������ת��Ϊ�ַ�
		Push(st,ch);				//�ַ�ch��ջ
		d/=2;						//���������λ
	}
	while (!StackEmpty(st))
	{
		Pop(st,ch);					//��ջ�����������b��
		b[i]=ch;
		i++;
	}
	b[i]='\0';						//�����ַ���������־
	DestroyStack(st);				//����ջst
}

void main()
{
	int d;
	char str[MaxSize];
	do
	{
		printf("����һ��������:");
		scanf("%d",&d);
	} while (d<0);
	trans(d,str);
	printf("��Ӧ�Ķ�������:%s\n",str);

}
