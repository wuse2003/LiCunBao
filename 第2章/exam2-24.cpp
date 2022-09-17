#include "CDLinkNode.cpp"
void Reverse(DLinkNode *&L)
{
	DLinkNode *p=L->next,*q;
	L->next=L->prior=L;		//����һ���յ�ѭ��˫����
	while (p!=L)
	{
		q=p->next;
		p->next=L->next;	//��*p�����뵽��ͷ
		L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;
	}
}
void main()
{
	DLinkNode *L;
	ElemType a[]={1,3,5,7,9,11};
	int n=6;
	ElemType x=7;
	CreateListR(L,a,n);			//β�巨����
	printf("ѭ��˫����L:");DispList(L);
	printf("����ѭ��˫����\n");
	Reverse(L);
	printf("���ú�L:");DispList(L);
	DestroyList(L);
}
