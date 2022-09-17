#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
void BubbleSort(SqType R[],int n)
{	int i,j,exchange;
	SqType tmp;
	for (i=0;i<n-1;i++)
	{	exchange=0;			//本趟排序前置exchange为0
		for (j=n-1;j>i;j--)	//比较,找出最小关键字的记录
			if (R[j].key<R[j-1].key)
			{	tmp=R[j];	//R[j]与R[j-1]进行交换,将最小关键字记录前移
				R[j]=R[j-1];
				R[j-1]=tmp;
				exchange=1;	//本趟排序发生交换置exchange为1
			}
		printf("i=%d: ",i);	//输出一趟排序结果
		for (int a=0;a<n;a++)
			printf("%3d",R[a].key);
		printf("\n");
		if (exchange==0)	//本趟未发生交换时结束算法
			return;
	}
}
void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	BubbleSort(R,n);
	printf("排序结果:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
