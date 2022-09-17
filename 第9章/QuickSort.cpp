#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;			//��������,ElemTypeΪ�������ݵ�����
} SqType;
int k=1;
void QuickSort(SqType R[],int s,int t) //��R[s]��R[t]��Ԫ�ؽ��п�������
{
	int i=s,j=t;
	SqType tmp;
	if (s<t) 				//���������ٴ���һ��Ԫ�ص����
	{
		tmp=R[s];			//������ĵ�1����¼��Ϊ��׼
		while (i!=j)		//���������˽������м�ɨ��,ֱ��i=jΪֹ
		{	
			while (j>i && R[j].key>tmp.key) 
				j--;  		//��������ɨ��,�ҵ�1���ؼ���С��tmp.key��R[j] 
			R[i]=R[j];		//��R[j]ǰ�Ƶ�R[i]��λ��
			while (i<j && R[i].key<tmp.key) 
				i++;		//��������ɨ��,�ҵ�1���ؼ��ִ���tmp.key�ļ�¼R[i] 
			R[j]=R[i];		//��R[i]���Ƶ�R[j]��λ��
		}
		R[i]=tmp;
		printf("��%d������: ",k++);	//���һ��������
		for (int a=0;a<10;a++)
			printf("%3d",R[a].key);
		printf("\n");
		QuickSort(R,s,i-1);    	//��������ݹ�����
		QuickSort(R,i+1,t);    	//��������ݹ�����
	}
}
void main()
{	SqType R[MaxSize];
	KeyType A[]={75,87,68,92,88,61,77,96,80,72};
	int i,n=10;
	for (i=0;i<n;i++)
		R[i].key=A[i];
	QuickSort(R,0,n-1);
	printf("������:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
}
