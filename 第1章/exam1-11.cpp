#include <stdio.h>
#define MaxSize 100
typedef struct				//���Ͻṹ������
{	int data[MaxSize];		//��ż����е�Ԫ�أ�����MaxSizeΪ����
	int length;				//��ż�����ʵ��Ԫ�ظ���
} Set;						//�����Ͻṹ��������һ����������Set��ʾ
void cset(Set &s,int a[],int n)		//������a��������s
{	int i;
	for (i=0;i<n;i++)
		s.data[i]=a[i];
	s.length=n;
}
void dispset(Set s)					//�������s�е�����Ԫ��
{	int i;
	for (i=0;i<s.length;i++)
		printf("%d ",s.data[i]);
	printf("\n");
}
int inset(Set s,int e)		//�ж�e�Ƿ��ڼ���s��
{	int i;
	for (i=0;i<s.length;i++)
		if (s.data[i]==e)
			return 1;
	return 0;
}
void add(Set s1,Set s2,Set &s3)	//�󼯺ϵĲ���
{	int i;
	for (i=0;i<s1.length;i++)	//������s1������Ԫ�ظ��Ƶ�s3��
		s3.data[i]=s1.data[i];
	s3.length=s1.length;
	for (i=0;i<s2.length;i++)	//��s2�в���s1�г��ֵ�Ԫ�ظ��Ƶ�s3��
		if (!inset(s1,s2.data[i]))
		{	s3.data[s3.length]=s2.data[i];
			s3.length++;
		}
}
void sub(Set s1,Set s2,Set &s3)		//�󼯺ϵĲ
{	int i;
	s3.length=0;
	for (i=0;i<s1.length;i++)	//��s1�в�������s2�е�Ԫ�ظ��Ƶ�s3��
		if (!inset(s2,s1.data[i]))
		{	s3.data[s3.length]=s1.data[i];
			s3.length++;
		}
}
void intersection(Set s1,Set s2,Set &s3)	//�󼯺ϵĽ���
{	int i;
	s3.length=0;
	for (i=0;i<s1.length;i++)	//��s1�г�����s2�е�Ԫ�ظ��Ƶ�s3��
		if (inset(s2,s1.data[i]))
		{	s3.data[s3.length]=s1.data[i];
			s3.length++;
		}
}
void main()
{	int a[]={1,4,2,6,8};
	int b[]={2,5,3,6};
	Set s1,s2,s3;
	cset(s1,a,5);
	cset(s2,b,4);
	printf("����s1:");
	dispset(s1);
	printf("����s2:");
	dispset(s2);
	add(s1,s2,s3);
	printf("����s1��s2�Ĳ���:");
	dispset(s3);
	sub(s1,s2,s3);
	printf("����s1��s2�Ĳ:");
	dispset(s3);
	intersection(s1,s2,s3);
	printf("����s1��s2�Ľ���:");
	dispset(s3);
}
