#include "SLinkNode.cpp"
SLinkNode *Maxnode(SLinkNode *L)
{	SLinkNode *p=L->next,*maxp=p;
	while (p!=NULL)			//�������еĽ��
	{	if (maxp->data<p->data)
			maxp=p;			//��pָ�����Ľ��ʱ�����丳��maxp
		p=p->next;			//p��next������һ�����
	}
	return maxp;
}
void main()
{
	SLinkNode *L,*p;
	ElemType a[]={1,3,6,4,5,2};
	int n=6;
	CreateListR(L,a,n);			//β�巨����
	printf("������L:");DispList(L);
	p=Maxnode(L);
	printf("���Ԫ��:%d\n",p->data);
	DestroyList(L);
}
