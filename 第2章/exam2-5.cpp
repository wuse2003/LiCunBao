#include <stdio.h>
#include "SqList.cpp"
void Move(SqList &L)
{	int i=0,j=L.length-1;
	ElemType temp;
	while (i<=j)
	{	while (L.data[i]%2==1) i++;		//从前向后找偶数
		while (L.data[j]%2==0) j--;		//从后向前找奇数
		if (i<j)
		{	temp=L.data[i];				//交换这两元素
			L.data[i]=L.data[j];
			L.data[j]=temp;
		}
	}
}
void main()
{
	SqList L;
	ElemType a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("线性表:");DispList(L);
	Move(L);
	printf("移动后\n");
	printf("线性表:");DispList(L);
	DestroyList(L);
}
