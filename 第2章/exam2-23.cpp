#include "DLinkNode.cpp"
int Swap(DLinkNode *L,ElemType x)
{	DLinkNode *p=L->next,*post;
	while (p!=NULL && p->data!=x)
		p=p->next;
	if (p==NULL)					//δ�ҵ�ֵΪx�Ľ��
		return 0;
	else
	{	post=p->next;				//postָ����p�ĺ�̽��
		if (post!=NULL)
		{	p->prior->next=post;	//��ɾ��p���
			post->prior=p->prior;
			p->next=post->next;		//��p�����뵽post���֮��
			if (post->next!=NULL)	//��post�����ں�̽��
				post->next->prior=p;
			post->next=p;
			p->prior=post;
			return 1;
		}
		else
			return 0;		//��ʾֵΪx�Ľ����β���
	}
}
void main()
{
	DLinkNode *L;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	ElemType x=11;
	CreateListR(L,a,n);			//β�巨����
	printf("˫����L:");DispList(L);
	printf("%d���<->��̽��\n",x);
	if (Swap(L,x))
	{
		printf("������L:");DispList(L);
	}
	else
		printf("δ�ҵ�ֵΪ%d�Ľ���ý��Ϊβ���\n",x);
	DestroyList(L);
}
