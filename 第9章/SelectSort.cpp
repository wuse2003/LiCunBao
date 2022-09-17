#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
void SelectSort(SqType R[],int n)
{	int i,j,k;
	SqType tmp;
	for (i=0;i<n-1;i++)
	{	k=i;
		for (j=i+1;j<n;j++)
			if (R[j].key<R[k].key) 
				k=j;			//用k指出每趟在无序区段的最小元素
		if (k!=i)
		{	tmp=R[i];			//将R[k]与R[i]交换
			R[i]=R[k];
			R[k]=tmp;
		}
		printf("i=%d: ",i);		//输出一趟排序结果
		for (int a=0;a<n;a++)
			printf("%3d",R[a].key);
		printf("\n");
	}
}

void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	SelectSort(R,n);
	printf("排序结果:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
