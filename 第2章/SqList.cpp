#include <stdio.h>
#define MaxSize 100
typedef int ElemType;			//����˳���������Ԫ��Ϊint����
typedef struct
{	ElemType data[MaxSize];		//���˳����Ԫ��
	int length;					//˳����ʵ�ʳ���
} SqList;						//˳�������
void InitList(SqList &L)	//����LҪ�ش���ֵ�Σ���������������
{
	L.length=0;
}
void DestroyList(SqList L)
{
}
int GetLength(SqList L)
{
	return L.length;
}
int GetElem(SqList L,int i,ElemType &e)
{	if (i<1 || i>L.length)		//��Ч��iֵ
		return 0;
	else
	{	e=L.data[i-1];
		return 1;
	}
}
int Locate(SqList L,ElemType x)	
{	int i=0;
	while (i<L.length && L.data[i]!=x)
		i++; 	//����ֵΪx�ĵ�1��Ԫ��,���ҷ�ΧΪ0��L.length-1
	if (i>=L.length) return(0);	//δ�ҵ�����0
	else return(i+1);			//�ҵ��󷵻����߼����
}
int InsElem(SqList &L,ElemType x,int i)
{	int j;
	if (i<1 || i>L.length+1)		//��Ч�Ĳ���i
		return 0;
	for (j=L.length;j>i;j--)		//��λ��Ϊi�Ľ�㼰֮��Ľ�����
		L.data[j]=L.data[j-1];
	L.data[i-1]=x;					//��λ��i������x
	L.length++;						//���Ա�����1
	return 1;
}
int DelElem(SqList &L,int i)
{	int j;
	if (i<1 || i>L.length)			//��Ч�Ĳ���i
		return 0;
	for (j=i;j<L.length;j++)		//��λ��Ϊi�Ľ��֮��Ľ��ǰ��
		L.data[j-1]=L.data[j];
	L.length--;						//���Ա��ȼ�1
	return 1;
}
void DispList(SqList L)
{	int i;
	for (i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
	printf("\n");
}
void CreateList(SqList &L,ElemType a[],int n)
{
	int i,k=0;						//k�ۼ�˳���L�е�Ԫ�ظ���
	for (i=0;i<n;i++)
	{
		L.data[k]=a[i];				//��L�����һ��Ԫ��
		k++;						//L��Ԫ�ظ�����1
	}
	L.length=k;						//����L�ĳ���
}