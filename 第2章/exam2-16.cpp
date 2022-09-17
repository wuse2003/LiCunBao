#include "SLinkNode.cpp"
void Merge(SLinkNode *ha, SLinkNode *hb,SLinkNode *&hc)
{	SLinkNode *pa=ha->next,*pb=hb->next,*tc;
	hc=ha;						//��ha��ͷ�������hc��ͷ���
	tc=hc;						//tc����ָ�����������β���
	free(hb);					//�ͷ�hb��ͷ���
	while (pa!=NULL && pb!=NULL)
	{	if (pa->data<pb->data)
		{	tc->next=pa;tc=pa;	//��pa������ӵ�tc���֮��
			pa=pa->next;
		}
		else if (pa->data>pb->data)
		{	tc->next=pb;tc=pb;	//��pb������ӵ�tc���֮��
			pb=pb->next;
		}
	}
	tc->next=NULL;
	if (pa!=NULL) tc->next=pa;	//ha������û��ɨ����ʱ
	if (pb!=NULL) tc->next=pb;	//hb������û��ɨ����ʱ
}
void main()
{
	SLinkNode *ha,*hb,*hc;
	ElemType a[]={1,3,5,7,9,11};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(ha,a,n);			//β�巨����
	ElemType b[]={2,4,6,8};
	int m=sizeof(b)/sizeof(b[0]);
	CreateListR(hb,b,m);			//β�巨����
	printf("��������ha:");DispList(ha);
	printf("��������hb:");DispList(hb);
	Merge(ha,hb,hc);
	printf("�ϲ�������hc:");DispList(hc);
	DestroyList(hc);
}
