#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct bthnode
{	ElemType data;
	struct bthnode *lchild,*rchild;
	int ltag,rtag;
} BthNode;
//-------�������Ļ��������㷨-----------
void CreateBTree(BthNode * &bt,char *str)
{	BthNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;
	char ch;
	bt=NULL;			//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')	//strδɨ����ʱѭ��
	{	switch(ch)
		{
		case '(':top++;St[top]=p;k=1; break;	//Ϊ���ӽ��
		case ')':top--;break;
		case ',':k=2; break;					//Ϊ�Һ��ӽ��
		default:p=(BthNode *)malloc(sizeof(BthNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (bt==NULL)					//*pΪ�������ĸ����
					bt=p;
				else							//�ѽ��������������
				{	switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
void DispBTree(BthNode *bt) 
{	if (bt!=NULL)
	{	printf("%c",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");			//������ʱ����'('
			DispBTree(bt->lchild);	//�ݹ鴦��������
			if (bt->rchild!=NULL)	//��������ʱ����'.'
				printf(",");
			DispBTree(bt->rchild);	//�ݹ鴦��������
			printf(")");			//���������ϣ�������һ��')'
		}
	}
}
//-------���������������Ļ��������㷨-----------
BthNode *pre;						//����preΪȫ�ֱ���
void Thread(BthNode *&p)
//����*pΪ�����Ķ�������������������
{	if (p!=NULL)
	{	Thread(p->lchild);			//������������
		if (p->lchild==NULL)		//ǰ������
		{	p->lchild=pre;			//�����*p���ǰ������
			p->ltag=1;
		}
		else p->ltag=0;
		if (pre->rchild==NULL)
		{	pre->rchild=p;			//�����*pre��Ӻ������
			pre->rtag=1;
		}
		else pre->rtag=0;
		pre=p;
		Thread(p->rchild);			//������������
	}
}
BthNode *CreaThread(BthNode *bt)
//����*btΪ�����Ķ���������������,������һ��ͷ���head
{	BthNode *head;
	head=(BthNode *)malloc(sizeof(BthNode));	//����ͷ���
	head->ltag=0;head->rtag=1;
	head->rchild=bt;
	if (bt==NULL)				//btΪ����ʱ
		head->lchild=head;
	else
	{	head->lchild=bt;
		pre=head;				//pre��*p��ǰ�����,����������
		Thread(bt);				//�������������������
		pre->rchild=head;		//�����,����ָ�����������
		pre->rtag=1;
		head->rchild=pre;		//�������������
	}
	return head;
}
BthNode *FirstNode(BthNode *tb)	//�������������в����������еĵ�1�����
{	BthNode *p=tb->lchild;
	while (p->ltag==0)
		p=p->lchild;
	return(p);
}
BthNode *LastNode(BthNode *tb)	//�������������в����������е����1�����
{
	return(tb->rchild);
}
BthNode *PreNode(BthNode *p)
//������������������,����*p����ǰ�����
{	BthNode *pre;
	pre=p->lchild;
	if (p->ltag!=1)
		while (pre->rtag==0)
			pre=pre->rchild;
	return(pre);
}
BthNode *PostNode(BthNode *p)
//������������������,����*p���ĺ�̽��
{	BthNode *post;
	post=p->rchild;
	if (p->rtag!=1)
		while (post->ltag==0)
			post=post->lchild;
	return(post);
}
void ThInOrder(BthNode *tb)		//�����������������,��������������
{	BthNode *p;
	p=FirstNode(tb);
	while (p!=tb)
	{	printf("%c ",p->data);
		p=PostNode(p);
	}
	printf("\n");
}
void ThInOrder1(BthNode *tb)	//�����������������,����������������
{	BthNode *p;
	p=LastNode(tb);
	while (p!=tb)
	{	printf("%c ",p->data);
		p=PreNode(p);
	}
	printf("\n");
}
void DestroyBTree1(BthNode *&b)
{
	if (b->ltag==0)			//*b������,�ͷ�������
		DestroyBTree1(b->lchild);
	if (b->rtag==0)			//*b���Һ���,�ͷ�������
		DestroyBTree1(b->rchild);
	free(b);
}
void DestroyBTree(BthNode *&tb)
{
	DestroyBTree1(tb->lchild);	//�ͷ���tb->lchildΪ��������
	free(tb);					//�ͷ�ͷ���
}
