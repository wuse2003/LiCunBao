#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;		//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;		//��������,ElemTypeΪ�������ݵ�����
} SqType;
int BinSearch(SqType R[],int n,int k)	//�������㷨
{	int low=0,high=n-1,mid;
	while (low<=high)				//��ǰ�������Ԫ��ʱѭ��
	{	mid=(low+high)/2;			//�����������м�λ��
		if (R[mid].key==k)			//���ҳɹ��������߼����mid+1
			return mid+1;			//�ҵ��󷵻����߼����mid+1
		else if (R[mid].key>k)		//������R[low..mid-1]�в���
			high=mid-1;
		else						//R[mid].key<k
			low=mid+1;				//������R[mid+1..high]�в���
	}
	return 0;						//����ǰ��������û��Ԫ��ʱ����0
}

void main()
{
	int i,j;
	KeyType a[]={2,4,7,9,10,14,18,26,32,40},k=7;
	int n=10;
	SqType R[MaxSize];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	j=BinSearch(R,n,k);
	if (j>0)
		printf("�ؼ���Ϊ%d�ļ�¼���߼������%d\n",k,j);
	else
		printf("û���ҵ��ؼ���Ϊ%d�ļ�¼\n",k);
}

