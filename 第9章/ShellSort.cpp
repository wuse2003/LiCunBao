#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
void ShellSort(SqType R[],int n)//对R[0..n-1]按递增有序进行希尔排序
{	int i,j,d;
	SqType tmp;
	d=n/2;						//增量置初值
	while (d>0)
	{
		for (i=d;i<n;i++)		//对所有相隔d位置的所有元素组采用直接插入排序
		{	tmp=R[i];
			j=i-d;
			while (j>=0 && tmp.key<R[j].key)	//对相隔d位置的元素组进行排序
			 {	R[j+d]=R[j];
				j=j-d;
			}
			R[j+d]=tmp;
		}
		printf("d=%d: ",d);		//输出每一趟的结果
		for (int a=0;a<n;a++)
			printf("%3d",R[a].key);
		printf("\n");
		d=d/2;					//减小增量
	}
}

void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	ShellSort(R,n);
	printf("排序结果:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
