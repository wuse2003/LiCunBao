#include <stdio.h>
#include "CDLinkNode.cpp"
int Symmetric(DLinkNode *L)
{
	int flag=1;
	DLinkNode *p=L->next,*q=L->prior;
	while (flag==1)				//flagΪ1ʱѭ��
	{
		if (p->data!=q->data)
			flag=0;
		else
		{
			if (p==q || p->next==q)
				break;			//�ǶԳƵ����
			p=p->next;			//��ǰ����ƶ�
			q=q->prior;			//�Ӻ���ǰ�ƶ�
		}
	}
	return flag;
}
void main()
{
	DLinkNode *L;
	ElemType a[]={1,2,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	CreateListR(L,a,n);			//β�巨����
	printf("ѭ��˫����L:");DispList(L);
	printf("ѭ��˫����L");
	if (Symmetric(L))
		printf("�ǶԳƵ�\n");
	else
		printf("���ǶԳƵ�\n");
	DestroyList(L);
}