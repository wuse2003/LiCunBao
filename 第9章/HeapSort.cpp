#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;			//��������,ElemTypeΪ�������ݵ�����
} SqType;
void Sift(SqType R[],int low,int high)		//��R[low..high]���ж�ɸѡ
{	int i=low,j=2*i;						//R[j]��R[i]������
	SqType tmp=R[i];
	while (j<=high)
	{	if (j<high && R[j].key<R[j+1].key) 	//���Һ��ӽϴ�,��jָ���Һ���
			j++;
		if (tmp.key<R[j].key) 
		{	R[i]=R[j];					//��R[j]������˫�׽��λ����
			i=j;							//�޸�i��jֵ,�Ա��������ɸѡ
			j=2*i;
		}
		else break;						//ɸѡ����
	}
	R[i]=tmp;								//��ɸѡ����ֵ��������λ��
}
void DispHeap(SqType R[],int n)
{
	int i;
	for (i=1;i<=n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
void HeapSort(SqType R[],int n)		//��R[1..n]���е���������
{	int i;
	SqType tmp;
	for (i=n/2;i>=1;i--)	//ѭ��������ʼ��
		Sift(R,i,n); 
	printf("��ʼ��:"); DispHeap(R,n);
	for (i=n;i>=2;i--)		//����n-1��ѭ��,��ɶ�����
	{
		tmp=R[1];			//��R[1]��R[i]����
		R[1]=R[i];
		R[i]=tmp;
		printf("i=%d: ",i); DispHeap(R,n);
		Sift(R,1,i-1);		//ɸѡ
	}
}
void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)		//�ؼ��ִ����R[1..n]��
		R[i+1].key=A[i];
	HeapSort(R,n);
	printf("������:");
	for (i=1;i<=n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
