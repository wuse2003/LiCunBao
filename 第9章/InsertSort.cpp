#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;			//��������,ElemTypeΪ�������ݵ�����
} SqType;
void InsertSort(SqType R[],int n)	//��R[0..n-1]�������������ֱ�Ӳ�������
{	int i,j;
	SqType tmp;
	for (i=1;i<n;i++)			//ֱ�Ӳ��������Ǵӵڶ���Ԫ�ؼ�R[1]��ʼ��
	{
		if (R[i-1].key>R[i].key)
		{
			tmp=R[i];			//ȡ���������ĵ�һ��Ԫ��
			j=i-1;				//����������������R[0..i-1]����R[i]�Ĳ���λ��
			do
			{
				R[j+1]=R[j];	//���ؼ��ִ���tmp.key��Ԫ�غ���
				j--;			//������ǰ�Ƚ�
			} while (j>=0 && R[j].key>tmp.key);
			R[j+1]=tmp;			//��j+1������R[i]
		}
	}
}
void main()
{
	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	InsertSort(R,n);
	printf("������:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
