#include <stdio.h>
#include "SqList.cpp"
int Deletek(SqList &L,int i,int k)
{	int j;
	if (i<1 || k<1 || i+k-1>L.length)
		return 0;						//�ж�i��k�Ƿ�Ϸ�
	for (j=i+k-1;j<L.length;j++)		//��Ԫ��ǰ��k��λ��
		L.data[j-k]=L.data[j];
	L.length-=k;						//L�ĳ��ȼ�k
	return 1;
}
void main()
{
	SqList L;
	ElemType a[]={1,3,1,5,4,2};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("���Ա�:");DispList(L);
	Deletek(L,2,3);
	printf("ɾ����\n");
	printf("���Ա�:");DispList(L);
	DestroyList(L);
}
