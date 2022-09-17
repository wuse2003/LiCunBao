#include <stdio.h>
int fun(int a[],int i)
{	if (i==1)
		return a[0];
	else
		return (fun(a,i-1)+a[i-1]);
}

void main()
{
	int a[]={1,2,3,4,5};
	int n=5;
	printf("a的所有元素和:%d\n",fun(a,n));
}

