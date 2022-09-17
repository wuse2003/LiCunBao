#include <stdio.h>
#include "SqList.cpp"
void Move(SqList &L)
{	int i=0,j=L.length-1;
	ElemType temp;
	while (i<=j)
	{	while (L.data[i]%2==1) i++;		//��ǰ�����ż��
		while (L.data[j]%2==0) j--;		//�Ӻ���ǰ������
		if (i<j)
		{	temp=L.data[i];				//��������Ԫ��
			L.data[i]=L.data[j];
			L.data[j]=temp;
		}
	}
}
void main()
{
	SqList L;
	ElemType a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("���Ա�:");DispList(L);
	Move(L);
	printf("�ƶ���\n");
	printf("���Ա�:");DispList(L);
	DestroyList(L);
}
