#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;		//存放关键字,KeyType为关键字类型
	ElemType data;		//其他数据,ElemType为其他数据的类型
} SqType;
int SqSearch(SqType R[],int n,int k)	//顺序查找算法
{	int i=0;
	while (i<n && R[i].key!=k)	//从表头往后找
		i++;
	if (i>=n)					//未找到返回0
		return 0;
	else
		return i+1;				//找到后返回其逻辑序号i+1
}
void main()
{
	int i,j;
	KeyType a[]={3,9,1,5,8,10,6,7,2,4},k=6;
	int n=10;
	SqType R[MaxSize];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	j=SqSearch(R,n,k);
	if (j>0)
		printf("关键字为%d的记录的逻辑序号是%d\n",k,j);
	else
		printf("没有找到关键字为%d的记录\n",k);
}

