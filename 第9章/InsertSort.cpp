#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
void InsertSort(SqType R[],int n)	//对R[0..n-1]按递增有序进行直接插入排序
{	int i,j;
	SqType tmp;
	for (i=1;i<n;i++)			//直接插入排序是从第二个元素即R[1]开始的
	{
		if (R[i-1].key>R[i].key)
		{
			tmp=R[i];			//取出无序区的第一个元素
			j=i-1;				//从右向左在有序区R[0..i-1]中找R[i]的插入位置
			do
			{
				R[j+1]=R[j];	//将关键字大于tmp.key的元素后移
				j--;			//继续向前比较
			} while (j>=0 && R[j].key>tmp.key);
			R[j+1]=tmp;			//在j+1处插入R[i]
		}
	}
}
void main()
{
	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	InsertSort(R,n);
	printf("排序结果:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
