#include "CSLinkNode.cpp"
int Delallx(SLinkNode *&L,ElemType x)
{	SLinkNode *pre=L,*p=L->next;		//pre指向p结点的前驱结点
	while (p!=L && p->data!=x)			//找第一个值为x的结点p
	{	pre=p;
		p=p->next;
	}
	if (p==L) return 0;					//没有找到值为x的结点返回0
	while (p!=L && p->data==x)			//删除所有值为x的结点
	{	pre->next=p->next;
		free(p);
		p=pre->next;
	}
	return 1;							//成功删除返回1
}
void main()
{
	SLinkNode *L;
	ElemType a[]={1,2,2,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);
	printf("循环单链表L:"); DispList(L);
	printf("删除所有值为2的结点\n");
	if (Delallx(L,2))
	{
		printf("删除后循环单链表L:"); 
		DispList(L);
	}
	else
		printf("没有值为2的结点");
	DestroyList(L);
}
