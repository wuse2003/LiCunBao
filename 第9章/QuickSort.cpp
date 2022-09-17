#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
int k=1;
void QuickSort(SqType R[],int s,int t) //对R[s]至R[t]的元素进行快速排序
{
	int i=s,j=t;
	SqType tmp;
	if (s<t) 				//区间内至少存在一个元素的情况
	{
		tmp=R[s];			//用区间的第1个记录作为基准
		while (i!=j)		//从区间两端交替向中间扫描,直至i=j为止
		{	
			while (j>i && R[j].key>tmp.key) 
				j--;  		//从右向左扫描,找第1个关键字小于tmp.key的R[j] 
			R[i]=R[j];		//将R[j]前移到R[i]的位置
			while (i<j && R[i].key<tmp.key) 
				i++;		//从左向右扫描,找第1个关键字大于tmp.key的记录R[i] 
			R[j]=R[i];		//将R[i]后移到R[j]的位置
		}
		R[i]=tmp;
		printf("第%d趟排序: ",k++);	//输出一趟排序结果
		for (int a=0;a<10;a++)
			printf("%3d",R[a].key);
		printf("\n");
		QuickSort(R,s,i-1);    	//对左区间递归排序
		QuickSort(R,i+1,t);    	//对右区间递归排序
	}
}
void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	QuickSort(R,0,n-1);
	printf("排序结果:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
