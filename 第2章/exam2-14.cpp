#include "SLinkNode.cpp"
void Reverse(SLinkNode *&L)
{
	SLinkNode *p=L->next,*q;
	L->next=NULL;
	while (p!=NULL)			//�����������ݽ��
	{
		q=p->next;			//q��ʱ����p���֮��Ľ��
		p->next=L->next;	//�����p���뵽ͷ���֮��
		L->next=p;
		p=q;
	}
}
void Reverse1(SLinkNode *&L)
{
	SLinkNode *pre=NULL;
	SLinkNode *p=L->next;
	SLinkNode *post=p->next;
	while (post!=NULL)
	{
		p->next=pre;
		pre=p;
		p=post;
		post=post->next;
	}
	p->next=pre;
	L->next=p;
}
void main()
{
	SLinkNode *L;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);
	printf("������L:");DispList(L);
	printf("���õ�����L\n");
	Reverse1(L);
	printf("���ú�L:");DispList(L);
	DestroyList(L);
}
