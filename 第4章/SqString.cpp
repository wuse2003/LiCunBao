#include <stdio.h>
#define MaxSize 100		//��������ַ�����
typedef struct
{	char data[MaxSize];	//��Ŵ��ַ�
	int length;			//��Ŵ���ʵ�ʳ���
} SqString;				//˳������
void Assign(SqString &s,char str[])
{	int i=0;
	while (str[i]!='\0')	//����str�������ַ�
	{	s.data[i]=str[i];
		i++;
	}
	s.length=i;
}
void DestroyStr(SqString s)
{    }
void StrCopy(SqString &s,SqString t)
{	int i;
	for (i=0;i<t.length;i++)
		s.data[i]=t.data[i];
	s.length=t.length;
}
int StrLength(SqString s)
{
	return(s.length);
}
int StrEqual(SqString s,SqString t)
{	int i=0;
	if (s.length!=t.length)				//������ͬʱ����0
		return(0);
	else
	{	for (i=0;i<s.length;i++)
			if (s.data[i]!=t.data[i])	//��һ����Ӧ�ַ���ͬʱ����0
				return 0;
		return 1;
	}
}
SqString Concat(SqString s,SqString t)
{	SqString r;
	int i,j;
	for (i=0;i<s.length;i++)		//��s���Ƶ�r
		r.data[i]=s.data[i];
	for (j=0;j<t.length;j++)		//��t���Ƶ�r
		r.data[s.length+j]=t.data[j];
	r.length=i+j;
	return r;						//����r
}
SqString SubStr(SqString s,int i,int j)
{	SqString t;
	int k;
	if (i<1 || i>s.length || j<1 || i+j>s.length+1)
		t.length=0;			//��������ʱ���ؿմ�
	else
	{	for (k=i-1;k<i+j;k++)
			t.data[k-i+1]=s.data[k];
		t.length=j;
	}
	return t;
}
int Index(SqString s,SqString t)
{	int i=0,j=0;					//i��j�ֱ�ɨ������s���Ӵ�t
	while (i<s.length && j<t.length)
	{	if (s.data[i]==t.data[j])	//��Ӧ�ַ���ͬʱ,�����Ƚ���һ���ַ�
		{	i++;
			j++;
		}
		else				//����,���Ӵ�ָ��������¿�ʼ��һ��ƥ��
		{	i=i-j+1;
			j=0;
		}
	}
	if (j>=t.length) return i-t.length+1;	//���ص�һ���ַ���λ��
	else return 0;							//����0
}
int InsStr(SqString &s,int i,SqString t)
{	int j;
	if (i<1 || i>s.length+1)
		return 0;							//λ�ò������󷵻�0
	else
	{	for (j=s.length-1;j>=i-1;j--)		//��s.data[i-1..s.length-1]
			s.data[j+t.length]=s.data[j];	//����t.length��λ��
		for (j=0;j<t.length;j++)			//�����Ӵ�t
			s.data[i+j-1]=t.data[j];
		s.length=s.length+t.length;			//�޸�s������
		return 1;							//�ɹ����뷵��1
	}
}
int DelStr(SqString &s,int i,int j)
{	int k;
	if (i<1 || i>s.length || j<1 || i+j>s.length+1)
		return 0;						//λ�ò���ֵ����
	else
	{	for (k=i+j-1;k<s.length;k++)	//��s�ĵ�i+jλ��֮����ַ�ǰ��jλ
			s.data[k-j]=s.data[k];
		s.length=s.length-j;			//�޸�s�ĳ���
		return 1;						//�ɹ�ɾ������1
	}
}
SqString RepStrAll(SqString s,SqString s1,SqString s2)
{	int i;
	i=Index(s,s1);
	while (i>0)
	{	DelStr(s,i,s1.length);	//ɾ���Ӵ�s1
		InsStr(s,i,s2);			//�����Ӵ�s2
		i=Index(s,s1);
	}
	return(s);
}
void DispStr(SqString s)
{	int i;
	for (i=0;i<s.length;i++)
		printf("%c",s.data[i]);
	printf("\n");
}
