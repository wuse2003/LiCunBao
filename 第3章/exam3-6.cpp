#include "Sqstack.cpp"				//����ǰ���˳��ջ�������㺯��
int Judge(char str[],int n)
{
	int i; ElemType x;
	SqStack st;						//����һ��˳��ջst
	InitStack(st);					//ջ��ʼ��
	for (i=0;i<n;i++)				//����str�������ַ�
	{	if (str[i]=='I')			//Ϊ'I'ʱ��ջ
			Push(st,str[i]);
		else if (str[i]=='O')		//Ϊ'O'ʱ��ջ
			if (!Pop(st,x))			//��ջ��������򷵻�0
			{	DestroyStack(st);
				return 0;
			}
	}
	DestroyStack(st);
	return StackEmpty(st);		//ջΪ��ʱ����1�����򷵻�0
}
void main()
{
	char A[]="IOIIOIOO";
	char B[]="IOOIOIIO";
	char C[]="IIIOIOIO";
	char D[]="IIIOOIOO";
	if (Judge(A,8))
		printf("A�ǺϷ���������\n");
	else
		printf("A�ǲ��Ϸ���������\n");
	if (Judge(B,8))
		printf("B�ǺϷ���������\n");
	else
		printf("B�ǲ��Ϸ���������\n");
	if (Judge(C,8))
		printf("C�ǺϷ���������\n");
	else
		printf("C�ǲ��Ϸ���������\n");
	if (Judge(D,8))
		printf("D�ǺϷ���������\n");
	else
		printf("D�ǲ��Ϸ���������\n");
}
