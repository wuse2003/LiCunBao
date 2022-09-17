#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct tnode
{	ElemType data;					//������
	struct tnode *lchild,*rchild;	//ָ����
} BTNode;

void CreateBTree(BTNode * &bt,char *str)
{	BTNode *St[MaxSize],*p=NULL;
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
		default:p=(BTNode *)malloc(sizeof(BTNode));
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
void DestroyBTree(BTNode *&bt)
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}
int BTHeight(BTNode *bt) 
{	int lchilddep,rchilddep;
	if (bt==NULL) return(0); 			//�����ĸ߶�Ϊ0
	else
	{	lchilddep=BTHeight(bt->lchild);	//���������ĸ߶�Ϊlchilddep
		rchilddep=BTHeight(bt->rchild);	//���������ĸ߶�Ϊrchilddep
		return (lchilddep>rchilddep)? (lchilddep+1):(rchilddep+1);
	}
}
int NodeCount(BTNode *bt)			//�������bt�Ľ�����
{	int num1,num2;
	if (bt==NULL)					//��������0
		return 0;
	else
	{	num1=NodeCount(bt->lchild);	//��������������
		num2=NodeCount(bt->rchild);	//��������������
		return (num1+num2+1);		//���غͼ���1
	}
}
int LeafCount(BTNode *bt)				//�������bt��Ҷ�ӽ�����
{	int num1,num2;
	if (bt==NULL)						//��������0
		return 0;
	else if (bt->lchild==NULL && bt->rchild==NULL) 
		return 1;						//Ҷ�ӽ��ʱ����1
	else
	{	num1=LeafCount(bt->lchild);		//��������Ҷ�ӽ�����
		num2=LeafCount(bt->rchild); 	//��������Ҷ�ӽ�����
		return (num1+num2);				//���غ�
	}
}
void DispBTree(BTNode *bt) 
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
