#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
void Sort1(int A[],int m,int n)
//将A[0..m-1]和A[m..n-1]两个相邻的有序表归并为一个有序表A[0..n-1]
{
	int *A1;
	int i=0,j=m,k=0;
	A1=(int *)malloc(n*sizeof(int));  //动态分配空间
	while (i<=m-1 && j<=n-1)	//在第1子表和第2子表均未扫描完时循环
		if (A[i]<=A[j])			//将第1子表中的记录放入A1中
		{	A1[k]=A[i];
			i++;k++; 
		}
		else					//将第2子表中的记录放入A1中
		{	A1[k]=A[j];
			j++;k++; 
	}
	while (i<=m-1)				//将第1子表余下部分复制到A1
	{	A1[k]=A[i];
		i++;k++; 
	}
	while (j<=n-1)				//将第2子表余下部分复制到A1
	{	A1[k]=A[j];
		j++;k++;  
	}
	for (i=0;i<n;i++)			//将A1复制回A中
		 A[i]=A1[i];
	free(A1);
}
void Sort2(int A[],int m,int n)  //将A[m..n-1]的元素有序插入到前端
{
	int i,j;
	int tmp;
	for (i=m;i<n;i++)
	{
		tmp=A[i];
		j=i-1;				//从右向左在有序区A[0..i-1]中找A[i]的插入位置
		while (j>=0 && A[j]>tmp)
		{	A[j+1]=A[j];		//将大于tmp的元素后移
			j--;				//继续向前比较
		}
		A[j+1]=tmp;			//在j+1处插入A[i]
	}
}
void Disp(int A[],int n)
{
	int i;
	for (i=0;i<n;i++)
		printf("%3d",A[i]);
	printf("\n");
}
void main()
{
	int A[]={1,5,7,9,2,3,4,5,8,10,12,15};
	int B[]={1,5,7,9,2,3,4,5,8,10,12,15};
	int n=12,m=4;
	printf("Sort1算法执行前:"); Disp(A,n);
	printf("m=%d,n=%d\n",m,n);
	Sort1(A,m,n);
	printf("Sort1的执行结果:");	Disp(A,n);
	printf("Sort2算法执行前:");	Disp(B,n);
	printf("m=%d,n=%d\n",m,n);
	Sort2(B,m,n);
	printf("Sort2的执行结果:");	Disp(B,n);
}
