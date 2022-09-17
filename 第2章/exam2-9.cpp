#include <stdio.h>
#include "SqList.cpp"
void Commelem(SqList A,SqList B,SqList &C)	//C为引用型参数
{	int i=0,j=0,k=0;	//k记录顺序表C中的元素个数
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
	C.length=k;			//指定顺序表C的实际长度
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

	printf("递增有序顺序表L1:");DispList(L1);
	printf("递增有序顺序表L2:");DispList(L2);
	printf("由L1、L2的公共元素产生L3\n");
	InitList(L3);		//初始化顺序表L3
	Commelem(L1,L2,L3);
	printf("顺序表L3:");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
}
