#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;		//存放关键字,KeyType为关键字类型
	ElemType data;		//其他数据,ElemType为其他数据的类型
} SqType;
void BinInsertSort(SqType R[],int n)	//对R[0..n-1]按递增有序进行折半插入排序
{	int i,j,low,high,mid;
	SqType tmp;
	for (i=1;i<n;i++)
	{
		if (R[i-1].key>R[i].key)
		{
			tmp=R[i];					//将R[i]保存到tmp中
			low=0;high=i-1;
			while (low<=high)			//在R[low..high]中折半查找有序插入的位置
			{	mid=(low+high)/2;		//取中间位置
				if (tmp.key<R[mid].key)
					high=mid-1;		//插入点在左半区
				else
					low=mid+1;		//插入点在右半区
			}
			for (j=i-1;j>=high+1;j--)	//元素后移
				R[j+1]=R[j];
			R[high+1]=tmp;			//插入原来的R[i]
		}
	}
}
void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	BinInsertSort(R,n);
	printf("排序结果:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
