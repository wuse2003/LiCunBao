#include "SLinkNode.cpp"
SLinkNode *Premaxnode(SLinkNode *L)
{	SLinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
	while (p!=NULL)
	{	if (maxp->data<p->data)
		{	maxp=p;		//当p指向更大的结点时，将其赋给maxp
			maxpre=pre;	//当p指向更大的结点时，将pre赋给maxpre
		}
		pre=p;			//pre、p同步后移，保证*pre始终为*p的前趋结点
		p=p->next;
	}
	if (maxpre==L) return NULL;		//不存在这样的结点返回NULL
	else return maxpre;
}
void main()
{
	SLinkNode *L,*p;
	ElemType a[]={1,3,6,4,5,2};
	int n=6;
	CreateListR(L,a,n);			//尾插法建表
	printf("单链表L:");DispList(L);
	p=Premaxnode(L);
	if (p!=NULL)
		printf("最大元素的前驱:%d\n",p->data);
	else
		printf("不存在\n");
	DestroyList(L);
}
