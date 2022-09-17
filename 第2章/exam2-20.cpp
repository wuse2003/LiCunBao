#include "CSLinkNode.cpp"
int Delallx(SLinkNode *&L,ElemType x)
{	SLinkNode *pre=L,*p=L->next;		//preָ��p����ǰ�����
	while (p!=L && p->data!=x)			//�ҵ�һ��ֵΪx�Ľ��p
	{	pre=p;
		p=p->next;
	}
	if (p==L) return 0;					//û���ҵ�ֵΪx�Ľ�㷵��0
	while (p!=L && p->data==x)			//ɾ������ֵΪx�Ľ��
	{	pre->next=p->next;
		free(p);
		p=pre->next;
	}
	return 1;							//�ɹ�ɾ������1
}
void main()
{
	SLinkNode *L;
	ElemType a[]={1,2,2,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);
	printf("ѭ��������L:"); DispList(L);
	printf("ɾ������ֵΪ2�Ľ��\n");
	if (Delallx(L,2))
	{
		printf("ɾ����ѭ��������L:"); 
		DispList(L);
	}
	else
		printf("û��ֵΪ2�Ľ��");
	DestroyList(L);
}
