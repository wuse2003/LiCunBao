#include <stdio.h>
#define MAX 10
void TransMat(int A[][MAX], int B[][MAX],int m,int n)	//ת���㷨
{	int i,j;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			B[j][i]=A[i][j];
}
void SetMat(int A[][MAX], int a[][4],int m,int n)	//������A��ֵ
{
	int i,j;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			A[i][j]=a[i][j];
}
void DispMat(int A[][MAX],int m,int n)		//�������A
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
	int A[MAX][MAX],B[MAX][MAX];
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	SetMat(A,a,3,4);
	printf("A:\n");	DispMat(A,3,4);
	printf("Aת��ΪB\n");
	TransMat(A,B,3,4);
	printf("B:\n");	DispMat(B,4,3);
}

