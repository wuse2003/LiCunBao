#include <stdio.h>
#include "SqList.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y;
	y=tmp;
}
void Swapmaxmin(SqList &L)
{
	int i,maxi,mini;
	maxi=mini=0;
	for (i=1;i<L.length;i++)
		if (L.data[i]>L.data[maxi])
			maxi=i;
		else if (L.data[i]<L.data[mini])
			mini=i;
	swap(L.data[maxi],L.data[mini]);
}

void main()
{
	SqList L;
	ElemType a[]={1,3,6,5,4,0};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("线性表:");DispList(L);
	Swapmaxmin(L);
	printf("线性表:");DispList(L);
	DestroyList(L);
}
