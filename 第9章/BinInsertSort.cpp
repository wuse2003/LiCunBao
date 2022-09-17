#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;		//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;		//��������,ElemTypeΪ�������ݵ�����
} SqType;
void BinInsertSort(SqType R[],int n)	//��R[0..n-1]��������������۰��������
{	int i,j,low,high,mid;
	SqType tmp;
	for (i=1;i<n;i++)
	{
		if (R[i-1].key>R[i].key)
		{
			tmp=R[i];					//��R[i]���浽tmp��
			low=0;high=i-1;
			while (low<=high)			//��R[low..high]���۰������������λ��
			{	mid=(low+high)/2;		//ȡ�м�λ��
				if (tmp.key<R[mid].key)
					high=mid-1;		//������������
				else
					low=mid+1;		//��������Ұ���
			}
			for (j=i-1;j>=high+1;j--)	//Ԫ�غ���
				R[j+1]=R[j];
			R[high+1]=tmp;			//����ԭ����R[i]
		}
	}
}
void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	BinInsertSort(R,n);
	printf("������:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
