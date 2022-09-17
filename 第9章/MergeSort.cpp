#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;			//��������,ElemTypeΪ�������ݵ�����
} SqType;
void Merge(SqType R[],int low,int mid,int high)
//��R[low..mid]��R[mid+1..high]�������ڵ������鲢Ϊһ�������R[low..high]
{	SqType *R1;
	int i=low,j=mid+1,k=0;		//k��R1���±�,i��j�ֱ�Ϊ��1��2�ӱ���±�
	R1=(SqType *)malloc((high-low+1)*sizeof(SqType));  //��̬����ռ�
	while (i<=mid && j<=high)	//�ڵ�1�ӱ�͵�2�ӱ��δɨ����ʱѭ��
		if (R[i].key<=R[j].key)	//����1�ӱ��еļ�¼����R1��
		{	R1[k]=R[i];
			i++;k++; 
		}
		else					//����2�ӱ��еļ�¼����R1��
		{	R1[k]=R[j];
			j++;k++; 
	}
	while (i<=mid)				//����1�ӱ����²��ָ��Ƶ�R1
	{	R1[k]=R[i];
		i++;k++; 
	}
	while (j<=high)				//����2�ӱ����²��ָ��Ƶ�R1
	{	R1[k]=R[j];
		j++;k++;  
	}
	for (k=0,i=low;i<=high;k++,i++) //��R1���ƻ�R��
		 R[i]=R1[k];
	free(R1);
}
void MergePass(SqType R[],int length,int n)	//һ�˶�·�鲢����
{	int i;
	for (i=0;i+2*length-1<n;i=i+2*length)	//�鲢length�����������ӱ�
		Merge(R,i,i+length-1,i+2*length-1);
	if (i+length-1<n)						//���������ӱ�,���߳���С��length
		Merge(R,i,i+length-1,n-1);			//�鲢�������ӱ�
}
void MergeSort(SqType R[],int n)			//��·�鲢�㷨
{	int length;
	for (length=1;length<n;length=2*length)
	{
		MergePass(R,length,n);
		printf("length=%d: ",length);	//���һ��������
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
	printf("������:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
