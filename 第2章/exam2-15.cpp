#include "SLinkNode.cpp"
void Move1(SLinkNode *&L)
{
	SLinkNode *p=L->next,*q,*tc;
	L->next=NULL;					//�����������L��Ϊ�ձ�
	tc=L;							//tcΪβ���ָ��
	while (p!=NULL)					//ɨ���������ݽ��
	{
		if (p->data%2==1)			//�ҵ��������
		{
			q=p->next;				//q��ʱ������p�ĺ�̽��
			if (L->next==NULL)		//LΪ�ձ�
			{
				p->next=L->next;	//��p�����뵽��ͷ
				L->next=p;
				tc=p;				//p�����Ϊβ���
			}
			else					//L��Ϊ�ձ�
			{
				p->next=L->next;
				L->next=p;
			}
			p=q;
		}
		else						//�ҵ�ż�����
		{
			tc->next=p;				//����β�巨������p
			tc=p;
			p=p->next;
		}
	}
	tc->next=NULL;				//β���next��Ϊ��
}
void main()
{
	SLinkNode *L;
	ElemType a[]={4,2,6,1,3,8};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);
	printf("������L:");DispList(L);
	printf("�ƶ�������L\n");
	Move1(L);
	printf("�ƶ���L:");DispList(L);
	DestroyList(L);
}
