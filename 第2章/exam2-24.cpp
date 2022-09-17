#include "CDLinkNode.cpp"
void Reverse(DLinkNode *&L)
{
	DLinkNode *p=L->next,*q;
	L->next=L->prior=L;		//构造一个空的循环双链表
	while (p!=L)
	{
		q=p->next;
		p->next=L->next;	//将*p结点插入到表头
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
	CreateListR(L,a,n);			//尾插法建表
	printf("循环双链表L:");DispList(L);
	printf("逆置循环双链表\n");
	Reverse(L);
	printf("逆置后L:");DispList(L);
	DestroyList(L);
}
