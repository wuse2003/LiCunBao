#include <stdio.h>
#include "SqList.cpp"
void Deletex(SqList &L,ElemType x)
{	int i,k=0;
	for (i=0;i<L.length;i++)
		if (L.data[i]!=x)		//将不为x的元素插入到L中
		{	L.data[k]=L.data[i];
			k++;
		}
	L.length=k;				//重置L的长度
}
void main()
{
	SqList L;
	ElemType a[]={1,2,1,5,1,1};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("线性表:");DispList(L);
	Deletex(L,1);
	printf("删除后\n");
	printf("线性表:");DispList(L);
	DestroyList(L);
}
