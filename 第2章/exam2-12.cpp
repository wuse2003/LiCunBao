#include "SLinkNode.cpp"
SLinkNode *Premaxnode(SLinkNode *L)
{	SLinkNode *p=L->next,*pre=L,*maxp=p,*maxpre=pre;
	while (p!=NULL)
	{	if (maxp->data<p->data)
		{	maxp=p;		//��pָ�����Ľ��ʱ�����丳��maxp
			maxpre=pre;	//��pָ�����Ľ��ʱ����pre����maxpre
		}
		pre=p;			//pre��pͬ�����ƣ���֤*preʼ��Ϊ*p��ǰ�����
		p=p->next;
	}
	if (maxpre==L) return NULL;		//�����������Ľ�㷵��NULL
	else return maxpre;
}
void main()
{
	SLinkNode *L,*p;
	ElemType a[]={1,3,6,4,5,2};
	int n=6;
	CreateListR(L,a,n);			//β�巨����
	printf("������L:");DispList(L);
	p=Premaxnode(L);
	if (p!=NULL)
		printf("���Ԫ�ص�ǰ��:%d\n",p->data);
	else
		printf("������\n");
	DestroyList(L);
}
