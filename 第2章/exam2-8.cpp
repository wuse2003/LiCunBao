#include <stdio.h>
#include "SqList.cpp"
void Merge(SqList A,SqList B,SqList &C)	//C为引用型参数
{	int i=0,j=0,k=0;	//k记录顺序表C中的元素个数
	while (i<A.length && j<B.length) 
	{	if (A.data[i]<B.data[j])
		{	C.data[k]=A.data[i];
			i++;k++;
		}
		else			//A.data[i]>=B.data[j]
		{	C.data[k]=B.data[j];
			j++;k++;
		}
	}
	while (i<A.length)	//将A中剩余的元素复制到C中
	{	C.data[k]=A.data[i];
		i++;k++;
	}
	while (j<B.length)	//将B中剩余的元素复制到C中
	{	C.data[k]=B.data[j];
		j++;k++;
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
	printf("L1、L2二路归并到L3\n");
	Merge(L1,L2,L3);
	printf("递增有序顺序表L3:");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
}
