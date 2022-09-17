#include "DLinkNode.cpp"
void main()
{	int i;
	ElemType e;
	DLinkNode *L;
	InitList(L);		//初始化双链表L
	InsElem(L,1,1);		//插入元素
	InsElem(L,3,2);		//插入元素3
	InsElem(L,1,3);		//插入元素1
	InsElem(L,5,4);		//插入元素5
	InsElem(L,4,5);		//插入元素4
	InsElem(L,2,6);		//插入元素2
	printf("线性表:");DispList(L);
	printf("长度:%d\n",GetLength(L));
	i=3;GetElem(L,i,e);
	printf("第%d个元素:%d\n",i,e);
	e=1;
	printf("元素%d是第%d个元素\n",e,Locate(L,e));
	i=4;printf("删除第%d个元素\n",i);
	DelElem(L,i);
	printf("线性表:");DispList(L);
}
