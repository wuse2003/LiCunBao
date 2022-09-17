#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
void Sort1(int A[],int m,int n)
//��A[0..m-1]��A[m..n-1]�������ڵ������鲢Ϊһ�������A[0..n-1]
{
	int *A1;
	int i=0,j=m,k=0;
	A1=(int *)malloc(n*sizeof(int));  //��̬����ռ�
	while (i<=m-1 && j<=n-1)	//�ڵ�1�ӱ�͵�2�ӱ��δɨ����ʱѭ��
		if (A[i]<=A[j])			//����1�ӱ��еļ�¼����A1��
		{	A1[k]=A[i];
			i++;k++; 
		}
		else					//����2�ӱ��еļ�¼����A1��
		{	A1[k]=A[j];
			j++;k++; 
	}
	while (i<=m-1)				//����1�ӱ����²��ָ��Ƶ�A1
	{	A1[k]=A[i];
		i++;k++; 
	}
	while (j<=n-1)				//����2�ӱ����²��ָ��Ƶ�A1
	{	A1[k]=A[j];
		j++;k++;  
	}
	for (i=0;i<n;i++)			//��A1���ƻ�A��
		 A[i]=A1[i];
	free(A1);
}
void Sort2(int A[],int m,int n)  //��A[m..n-1]��Ԫ��������뵽ǰ��
{
	int i,j;
	int tmp;
	for (i=m;i<n;i++)
	{
		tmp=A[i];
		j=i-1;				//����������������A[0..i-1]����A[i]�Ĳ���λ��
		while (j>=0 && A[j]>tmp)
		{	A[j+1]=A[j];		//������tmp��Ԫ�غ���
			j--;				//������ǰ�Ƚ�
		}
		A[j+1]=tmp;			//��j+1������A[i]
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
	printf("Sort1�㷨ִ��ǰ:"); Disp(A,n);
	printf("m=%d,n=%d\n",m,n);
	Sort1(A,m,n);
	printf("Sort1��ִ�н��:");	Disp(A,n);
	printf("Sort2�㷨ִ��ǰ:");	Disp(B,n);
	printf("m=%d,n=%d\n",m,n);
	Sort2(B,m,n);
	printf("Sort2��ִ�н��:");	Disp(B,n);
}
