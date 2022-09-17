#include <stdio.h>
#include "SqList.cpp"
int Deletek(SqList &L,int i,int k)
{	int j;
	if (i<1 || k<1 || i+k-1>L.length)
		return 0;						//判断i和k是否合法
	for (j=i+k-1;j<L.length;j++)		//将元素前移k个位置
		L.data[j-k]=L.data[j];
	L.length-=k;						//L的长度减k
	return 1;
}
void main()
{
	SqList L;
	ElemType a[]={1,3,1,5,4,2};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("线性表:");DispList(L);
	Deletek(L,2,3);
	printf("删除后\n");
	printf("线性表:");DispList(L);
	DestroyList(L);
}
