#include "SLinkNode.cpp"
void Delmaxnode(SLinkNode *&L)
{	SLinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
	while (p!=NULL)
	{	if (maxp->data<p->data)
		{	maxp=p;
			maxpre=pre;
		}
		pre=p;
		p=p->next;
	}
	maxpre->next=maxp->next;	//删除*maxp结点
	free(maxp);					//释放*maxp结点
}
void main()
{
	SLinkNode *L,*p;
	ElemType a[]={1,3,6,4,5,2};
	int n=6;
	CreateListR(L,a,n);			//尾插法建表
	printf("单链表L:");DispList(L);
	Delmaxnode(L);
	printf("删除后L:");DispList(L);
	DestroyList(L);
}
