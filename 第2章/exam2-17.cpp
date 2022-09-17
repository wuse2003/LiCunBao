#include "SLinkNode.cpp"
void Commelem(SLinkNode *ha, SLinkNode *hb,SLinkNode *&hc)
{	SLinkNode *pa=ha->next,*pb=hb->next,*tc,*s;
	hc=(SLinkNode *)malloc(sizeof(SLinkNode));			//创建hc头结点
	tc=hc;			//tc指向新建单链表hc的尾结点
	while (pa!=NULL && pb!=NULL)
	{	if (pa->data<pb->data)
			pa=pa->next;
		else if (pa->data>pb->data)
			pb=pb->next;
		else	//pa->data==pb-data
		{	s=(SLinkNode *)malloc(sizeof(SLinkNode));	//创建s结点
			s->data=pa->data;					//复制data域
			tc->next=s;tc=s;					//将s结点链到tc结点的后面
			pa=pa->next;pb=pb->next;
		}
	}
	tc->next=NULL;								//尾结点next域置空
}
void main()
{
	SLinkNode *ha,*hb,*hc;
	ElemType a[]={1,3,4,5,8,9};
	int n=6;
	CreateListR(ha,a,n);			//尾插法建表
	ElemType b[]={3,4,6,8};
	int m=4;
	CreateListR(hb,b,m);			//尾插法建表
	printf("有序单链表ha:");DispList(ha);
	printf("有序单链表hb:");DispList(hb);
	Commelem(ha,hb,hc);
	printf("公共元素的单链表hc:");DispList(hc);
	DestroyList(ha);
	DestroyList(hb);
	DestroyList(hc);
}
