#include "DLinkNode.cpp"
void Delmax(DLinkNode *&L)
{	DLinkNode *p=L->next,*maxp=p,*pre,*post;
	while (p!=NULL)			//查找第一个最大值的结点maxp
	{	if (p->data>maxp->data)
			maxp=p;
		p=p->next;
	}
	pre=maxp->prior;		//指向被删结点的前驱结点
	post=maxp->next;		//指向被删结点的后继结点
	pre->next=post;			//删除maxp结点
	if (post!=NULL)
		post->prior=pre;
	free(maxp);				//释放其空间
}
void main()
{
	DLinkNode *L;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);			//尾插法建表
	printf("双链表L:");DispList(L);
	printf("删除最大值结点\n");
	Delmax(L);
	printf("删除后L:");DispList(L);
	DestroyList(L);
}
