#include <stdio.h>
#include "SqList.cpp"
void Deleteminus(SqList &L)
{	int i,k=0;
	for (i=0;i<L.length;i++)
		if (L.data[i]>=0)		//����Ϊ������Ԫ�ز��뵽L��
		{	L.data[k]=L.data[i];
			k++;
		}
	L.length=k;				//����L�ĳ���
}
void main()
{
	SqList L;
	ElemType a[]={1,-2,1,5,-1,1};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("���Ա�:");DispList(L);
	Deleteminus(L);
	printf("ɾ����\n");
	printf("���Ա�:");DispList(L);
	DestroyList(L);
}
