#include "CSLinkNode.cpp"
int Nodes(SLinkNode *L,ElemType x)
{	int i=0;
	SLinkNode *p=L->next;
	while (p!=L)			//遍历所有数据结点
	{	if (p->data==x) i++;
		p=p->next;
	}
	return i;
}

void main()
{
	SLinkNode *L;
	ElemType a[]={2,5,1,3,2,4,2};
	int n=7;
	CreateListR(L,a,n);
	printf("循环单链表L:"); DispList(L);
	printf("值为2的结点个数:%d\n",Nodes(L,2));
	DestroyList(L);
}
