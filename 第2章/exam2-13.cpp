#include "SLinkNode.cpp"
void Delmaxnode(SLinkNode *&L)
{	SLinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
	while (p!=NULL)
	{	if (maxp->data<p->data)
		{	maxp=p;
			maxpre=pre;
		}
		pre=p;
		p=p->next;
	}
	maxpre->next=maxp->next;	//ɾ��*maxp���
	free(maxp);					//�ͷ�*maxp���
}
void main()
{
	SLinkNode *L,*p;
	ElemType a[]={1,3,6,4,5,2};
	int n=6;
	CreateListR(L,a,n);			//β�巨����
	printf("������L:");DispList(L);
	Delmaxnode(L);
	printf("ɾ����L:");DispList(L);
	DestroyList(L);
}
