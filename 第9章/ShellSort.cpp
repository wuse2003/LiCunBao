#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;			//��������,ElemTypeΪ�������ݵ�����
} SqType;
void ShellSort(SqType R[],int n)//��R[0..n-1]�������������ϣ������
{	int i,j,d;
	SqType tmp;
	d=n/2;						//�����ó�ֵ
	while (d>0)
	{
		for (i=d;i<n;i++)		//���������dλ�õ�����Ԫ�������ֱ�Ӳ�������
		{	tmp=R[i];
			j=i-d;
			while (j>=0 && tmp.key<R[j].key)	//�����dλ�õ�Ԫ�����������
			 {	R[j+d]=R[j];
				j=j-d;
			}
			R[j+d]=tmp;
		}
		printf("d=%d: ",d);		//���ÿһ�˵Ľ��
		for (int a=0;a<n;a++)
			printf("%3d",R[a].key);
		printf("\n");
		d=d/2;					//��С����
	}
}

void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	ShellSort(R,n);
	printf("������:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
