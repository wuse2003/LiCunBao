#include "SqString.cpp"				//����˳�򴮵Ļ������㺯��
int Count(SqString s,SqString t)
{
	int num=0,i,j,k;				//i��j�ֱ�ɨ������s���Ӵ�t
	i=0;
	while (i<=s.length-t.length)
	{
		for (k=i,j=0;j<t.length && s.data[k]==t.data[j];k++,j++);
		if (j==t.length)			//j�����Ӵ�t�ĳ���
		{	num++;					//�ҵ�һ���Ӵ�
			i+=t.length;			//i����t.length���ַ�
		}
		else
			i++;					//i����һ���ַ�
	}
	return(num);
}

void main()
{
	SqString s,t;
	Assign(s,"aababababc");
	Assign(t,"abab");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("Count:%d\n",Count(s,t));
}

