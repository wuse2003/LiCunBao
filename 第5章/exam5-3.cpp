#include <stdio.h>
#define MAX 10
void MutMat(int A[][MAX],int B[][MAX],int C[][MAX],int m,int n,int k)	//相乘运算
{	int i,j,l;
	for (i=0;i<m;i++)
		for (j=0;j<k;j++)
		{	C[i][j]=0;
			for (l=0;l<n;l++)
				C[i][j]+=A[i][l]*B[l][j];
		}
}
void SetMatA(int A[][MAX], int a[][4],int m,int n)	//给数组A赋值
{
	int i,j;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			A[i][j]=a[i][j];
}
void SetMatB(int A[][MAX], int a[][3],int m,int n)	//给数组B赋值
{
	int i,j;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			A[i][j]=a[i][j];
}
void DispMat(int A[][MAX],int m,int n)		//输出数组A
{
	int i,j;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
			printf("%4d",A[i][j]);
		printf("\n");
	}
}
void main()
{
	int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int b[4][3]={{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
	SetMatA(A,a,3,4);
	printf("A:\n");	DispMat(A,3,4);
	SetMatB(B,b,4,3);
	printf("B:\n");	DispMat(B,4,3);
	printf("A、B相乘得到C\n");
	MutMat(A,B,C,3,4,3);
	printf("C:\n");	DispMat(C,3,3);
}

