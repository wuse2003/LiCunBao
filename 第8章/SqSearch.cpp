#include <stdio.h>
#define MaxSize 100
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;		//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;		//��������,ElemTypeΪ�������ݵ�����
} SqType;
int SqSearch(SqType R[],int n,int k)	//˳������㷨
{	int i=0;
	while (i<n && R[i].key!=k)	//�ӱ�ͷ������
		i++;
	if (i>=n)					//δ�ҵ�����0
		return 0;
	else
		return i+1;				//�ҵ��󷵻����߼����i+1
}
void main()
{
	int i,j;
	KeyType a[]={3,9,1,5,8,10,6,7,2,4},k=6;
	int n=10;
	SqType R[MaxSize];
	for (i=0;i<n;i++)
		R[i].key=a[i];
	j=SqSearch(R,n,k);
	if (j>0)
		printf("�ؼ���Ϊ%d�ļ�¼���߼������%d\n",k,j);
	else
		printf("û���ҵ��ؼ���Ϊ%d�ļ�¼\n",k);
}

