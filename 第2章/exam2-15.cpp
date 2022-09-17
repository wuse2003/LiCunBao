#include "SLinkNode.cpp"
void Move1(SLinkNode *&L)
{
	SLinkNode *p=L->next,*q,*tc;
	L->next=NULL;					//将结果单链表L置为空表
	tc=L;							//tc为尾结点指针
	while (p!=NULL)					//扫描所有数据结点
	{
		if (p->data%2==1)			//找到奇数结点
		{
			q=p->next;				//q临时保存结点p的后继结点
			if (L->next==NULL)		//L为空表
			{
				p->next=L->next;	//将p结点插入到开头
				L->next=p;
				tc=p;				//p结点作为尾结点
			}
			else					//L不为空表
			{
				p->next=L->next;
				L->next=p;
			}
			p=q;
		}
		else						//找到偶数结点
		{
			tc->next=p;				//采用尾插法插入结点p
			tc=p;
			p=p->next;
		}
	}
	tc->next=NULL;				//尾结点next置为空
}
void main()
{
	SLinkNode *L;
	ElemType a[]={4,2,6,1,3,8};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);
	printf("单链表L:");DispList(L);
	printf("移动单链表L\n");
	Move1(L);
	printf("移动后L:");DispList(L);
	DestroyList(L);
}
