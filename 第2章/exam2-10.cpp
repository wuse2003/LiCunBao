#include <stdio.h>
#include "SqList.cpp"
#define INF 32767
int Topk1(SqList A,SqList B,int k,ElemType &e)
{
	int i=0,j=0;
	if (k<1 || k>A.length+B.length)
		return 0;				//�������󷵻�0
	while (i<A.length && j<B.length)
	{
		k--;
		if (A.data[i]<B.data[j])
		{
			if (k==0)
			{
				e=A.data[i];
				return 1;
			}
			i++;
		}
		else
		{
			if (k==0)
			{
				e=B.data[j];
				return 1;
			}
			j++;
		}
	}
	if (i<A.length)				//Aû��ɨ�����
		e=A.data[i+k-1];
	else if (j<B.length)		//Bû��ɨ�����
		e=B.data[j+k-1];
	return 1;
}
int Topk2(SqList A,SqList B,int k,ElemType &e)
{
	int i=0,j=0;
	if (k<1 || k>A.length+B.length)
		return 0;				//�������󷵻�0
	while (true)
	{
		k--;
		int x=(i<A.length?A.data[i]:INF);
		int y=(j<B.length?B.data[j]:INF);
		if (x<y)
		{
			if (k==0)
			{
				e=x;
				return 1;
			}
			i++;
		}
		else
		{
			if (k==0)
			{
				e=y;
				return 1;
			}
			j++;
		}
	}
}
void main()
{
	SqList L1,L2;
	ElemType a[]={1,2,5,6,8};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L1,a,n);

	ElemType b[]={3,4,7,9,10,20};
	int m=sizeof(b)/sizeof(b[0]);
	CreateList(L2,b,m);

	printf("��������˳���L1:");DispList(L1);
	printf("��������˳���L2:");DispList(L2);

	ElemType e;
	for (int k=0;k<=m+n+1;k++)
	{
		if (Topk1(L1,L2,k,e))
			printf("��%dС��Ԫ��:%d\n",k,e);
		else
			printf("k=%d:��������\n",k);
	}
	DestroyList(L1);
	DestroyList(L2);
}
