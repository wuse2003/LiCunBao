#include <stdio.h>
#include "SqList.cpp"
void Deletex(SqList &L,ElemType x)
{	int i,k=0;
	for (i=0;i<L.length;i++)
		if (L.data[i]!=x)		//����Ϊx��Ԫ�ز��뵽L��
		{	L.data[k]=L.data[i];
			k++;
		}
	L.length=k;				//����L�ĳ���
}
void main()
{
	SqList L;
	ElemType a[]={1,2,1,5,1,1};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("���Ա�:");DispList(L);
	Deletex(L,1);
	printf("ɾ����\n");
	printf("���Ա�:");DispList(L);
	DestroyList(L);
}
