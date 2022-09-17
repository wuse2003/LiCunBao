#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
void Merge(SqType R[],int low,int mid,int high)
//将R[low..mid]和R[mid+1..high]两个相邻的有序表归并为一个有序表R[low..high]
{	SqType *R1;
	int i=low,j=mid+1,k=0;		//k是R1的下标,i、j分别为第1、2子表的下标
	R1=(SqType *)malloc((high-low+1)*sizeof(SqType));  //动态分配空间
	while (i<=mid && j<=high)	//在第1子表和第2子表均未扫描完时循环
		if (R[i].key<=R[j].key)	//将第1子表中的记录放入R1中
		{	R1[k]=R[i];
			i++;k++; 
		}
		else					//将第2子表中的记录放入R1中
		{	R1[k]=R[j];
			j++;k++; 
	}
	while (i<=mid)				//将第1子表余下部分复制到R1
	{	R1[k]=R[i];
		i++;k++; 
	}
	while (j<=high)				//将第2子表余下部分复制到R1
	{	R1[k]=R[j];
		j++;k++;  
	}
	for (k=0,i=low;i<=high;k++,i++) //将R1复制回R中
		 R[i]=R1[k];
	free(R1);
}
void MergePass(SqType R[],int length,int n)	//一趟二路归并排序
{	int i;
	for (i=0;i+2*length-1<n;i=i+2*length)	//归并length长的两相邻子表
		Merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n)						//余下两个子表,后者长度小于length
		Merge(R,i,i+length-1,n-1);			//归并这两个子表
}
void MergeSort(SqType R[],int n)			//二路归并算法
{	int length;
	for (length=1;length<n;length=2*length)
	{
		MergePass(R,length,n);
		printf("length=%d: ",length);	//输出一趟排序结果
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
	MergeSort(R,n);
	printf("排序结果:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
