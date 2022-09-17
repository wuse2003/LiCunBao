#include "SLinkNode.cpp"
SLinkNode *Maxnode(SLinkNode *L)
{	SLinkNode *p=L->next,*maxp=p;
	while (p!=NULL)			//遍历所有的结点
	{	if (maxp->data<p->data)
			maxp=p;			//当p指向更大的结点时，将其赋给maxp
		p=p->next;			//p沿next域下移一个结点
	}
	return maxp;
}
void main()
{
	SLinkNode *L,*p;
	ElemType a[]={1,3,6,4,5,2};
	int n=6;
	CreateListR(L,a,n);			//尾插法建表
	printf("单链表L:");DispList(L);
	p=Maxnode(L);
	printf("最大元素:%d\n",p->data);
	DestroyList(L);
}
