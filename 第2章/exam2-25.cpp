#include <stdio.h>
#include "CDLinkNode.cpp"
int Symmetric(DLinkNode *L)
{
	int flag=1;
	DLinkNode *p=L->next,*q=L->prior;
	while (flag==1)				//flag为1时循环
	{
		if (p->data!=q->data)
			flag=0;
		else
		{
			if (p==q || p->next==q)
				break;			//是对称的情况
			p=p->next;			//从前向后移动
			q=q->prior;			//从后向前移动
		}
	}
	return flag;
}
void main()
{
	DLinkNode *L;
	ElemType a[]={1,2,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);			//尾插法建表
	printf("循环双链表L:");DispList(L);
	printf("循环双链表L");
	if (Symmetric(L))
		printf("是对称的\n");
	else
		printf("不是对称的\n");
	DestroyList(L);
}