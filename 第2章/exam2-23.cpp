#include "DLinkNode.cpp"
int Swap(DLinkNode *L,ElemType x)
{	DLinkNode *p=L->next,*post;
	while (p!=NULL && p->data!=x)
		p=p->next;
	if (p==NULL)					//未找到值为x的结点
		return 0;
	else
	{	post=p->next;				//post指向结点p的后继结点
		if (post!=NULL)
		{	p->prior->next=post;	//先删除p结点
			post->prior=p->prior;
			p->next=post->next;		//将p结点插入到post结点之后
			if (post->next!=NULL)	//若post结点存在后继结点
				post->next->prior=p;
			post->next=p;
			p->prior=post;
			return 1;
		}
		else
			return 0;		//表示值为x的结点是尾结点
	}
}
void main()
{
	DLinkNode *L;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	ElemType x=11;
	CreateListR(L,a,n);			//尾插法建表
	printf("双链表L:");DispList(L);
	printf("%d结点<->后继结点\n",x);
	if (Swap(L,x))
	{
		printf("交换后L:");DispList(L);
	}
	else
		printf("未找到值为%d的结点或该结点为尾结点\n",x);
	DestroyList(L);
}
