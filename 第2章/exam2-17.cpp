#include "SLinkNode.cpp"
void Commelem(SLinkNode *ha, SLinkNode *hb,SLinkNode *&hc)
{	SLinkNode *pa=ha->next,*pb=hb->next,*tc,*s;
	hc=(SLinkNode *)malloc(sizeof(SLinkNode));			//����hcͷ���
	tc=hc;			//tcָ���½�������hc��β���
	while (pa!=NULL && pb!=NULL)
	{	if (pa->data<pb->data)
			pa=pa->next;
		else if (pa->data>pb->data)
			pb=pb->next;
		else	//pa->data==pb-data
		{	s=(SLinkNode *)malloc(sizeof(SLinkNode));	//����s���
			s->data=pa->data;					//����data��
			tc->next=s;tc=s;					//��s�������tc���ĺ���
			pa=pa->next;pb=pb->next;
		}
	}
	tc->next=NULL;								//β���next���ÿ�
}
void main()
{
	SLinkNode *ha,*hb,*hc;
	ElemType a[]={1,3,4,5,8,9};
	int n=6;
	CreateListR(ha,a,n);			//β�巨����
	ElemType b[]={3,4,6,8};
	int m=4;
	CreateListR(hb,b,m);			//β�巨����
	printf("��������ha:");DispList(ha);
	printf("��������hb:");DispList(hb);
	Commelem(ha,hb,hc);
	printf("����Ԫ�صĵ�����hc:");DispList(hc);
	DestroyList(ha);
	DestroyList(hb);
	DestroyList(hc);
}
