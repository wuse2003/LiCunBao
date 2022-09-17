#include <stdio.h>
#include "SqList.cpp"
void Commelem(SqList A,SqList B,SqList &C)	//CΪ�����Ͳ���
{	int i=0,j=0,k=0;	//k��¼˳���C�е�Ԫ�ظ���
	while (i<A.length && j<B.length)
	{	if (A.data[i]<B.data[j])
			i++;
		else if (A.data[i]>B.data[j])
			j++;
		else		//A.data[i]=B.data[j]
		{	C.data[k]=A.data[i];
			i++; j++; k++;
		}
	}
	C.length=k;			//ָ��˳���C��ʵ�ʳ���
}
void main()
{
	SqList L1,L2,L3;
	ElemType a[]={1,2,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L1,a,n);

	ElemType b[]={2,4,6,8,10};
	int m=sizeof(b)/sizeof(b[0]);
	CreateList(L2,b,m);

	printf("��������˳���L1:");DispList(L1);
	printf("��������˳���L2:");DispList(L2);
	printf("��L1��L2�Ĺ���Ԫ�ز���L3\n");
	InitList(L3);		//��ʼ��˳���L3
	Commelem(L1,L2,L3);
	printf("˳���L3:");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
}
