#include "CSLinkNode.cpp"
int Nodes(SLinkNode *L,ElemType x)
{	int i=0;
	SLinkNode *p=L->next;
	while (p!=L)			//�����������ݽ��
	{	if (p->data==x) i++;
		p=p->next;
	}
	return i;
}

void main()
{
	SLinkNode *L;
	ElemType a[]={2,5,1,3,2,4,2};
	int n=7;
	CreateListR(L,a,n);
	printf("ѭ��������L:"); DispList(L);
	printf("ֵΪ2�Ľ�����:%d\n",Nodes(L,2));
	DestroyList(L);
}
