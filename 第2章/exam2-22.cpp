#include "DLinkNode.cpp"
void Delmax(DLinkNode *&L)
{	DLinkNode *p=L->next,*maxp=p,*pre,*post;
	while (p!=NULL)			//���ҵ�һ�����ֵ�Ľ��maxp
	{	if (p->data>maxp->data)
			maxp=p;
		p=p->next;
	}
	pre=maxp->prior;		//ָ��ɾ����ǰ�����
	post=maxp->next;		//ָ��ɾ���ĺ�̽��
	pre->next=post;			//ɾ��maxp���
	if (post!=NULL)
		post->prior=pre;
	free(maxp);				//�ͷ���ռ�
}
void main()
{
	DLinkNode *L;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);			//β�巨����
	printf("˫����L:");DispList(L);
	printf("ɾ�����ֵ���\n");
	Delmax(L);
	printf("ɾ����L:");DispList(L);
	DestroyList(L);
}
