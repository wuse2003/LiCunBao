#include "SLinkNode.cpp"
void Reverse(SLinkNode *&L)
{
	SLinkNode *p=L->next,*q;
	L->next=NULL;
	while (p!=NULL)			//遍历所有数据结点
	{
		q=p->next;			//q临时保存p结点之后的结点
		p->next=L->next;	//将结点p插入到头结点之后
		L->next=p;
		p=q;
	}
}
void Reverse1(SLinkNode *&L)
{
	SLinkNode *pre=NULL;
	SLinkNode *p=L->next;
	SLinkNode *post=p->next;
	while (post!=NULL)
	{
		p->next=pre;
		pre=p;
		p=post;
		post=post->next;
	}
	p->next=pre;
	L->next=p;
}
void main()
{
	SLinkNode *L;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);
	printf("单链表L:");DispList(L);
	printf("逆置单链表L\n");
	Reverse1(L);
	printf("逆置后L:");DispList(L);
	DestroyList(L);
}
