#include "SLinkNode.cpp"
void Merge(SLinkNode *ha, SLinkNode *hb,SLinkNode *&hc)
{	SLinkNode *pa=ha->next,*pb=hb->next,*tc;
	hc=ha;						//将ha的头结点用作hc的头结点
	tc=hc;						//tc总是指向结果单链表的尾结点
	free(hb);					//释放hb的头结点
	while (pa!=NULL && pb!=NULL)
	{	if (pa->data<pb->data)
		{	tc->next=pa;tc=pa;	//将pa结点链接到tc结点之后
			pa=pa->next;
		}
		else if (pa->data>pb->data)
		{	tc->next=pb;tc=pb;	//将pb结点链接到tc结点之后
			pb=pb->next;
		}
	}
	tc->next=NULL;
	if (pa!=NULL) tc->next=pa;	//ha单链表没有扫描完时
	if (pb!=NULL) tc->next=pb;	//hb单链表没有扫描完时
}
void main()
{
	SLinkNode *ha,*hb,*hc;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(ha,a,n);			//尾插法建表
	ElemType b[]={2,4,6,8};
	int m=sizeof(b)/sizeof(b[0]);
	CreateListR(hb,b,m);			//尾插法建表
	printf("有序单链表ha:");DispList(ha);
	printf("有序单链表hb:");DispList(hb);
	Merge(ha,hb,hc);
	printf("合并后单链表hc:");DispList(hc);
	DestroyList(hc);
}
