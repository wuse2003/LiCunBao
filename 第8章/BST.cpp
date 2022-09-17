#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char ElemType;
typedef struct tnode
{
	KeyType key;
	ElemType data;
	struct tnode *lchild,*rchild;
} BSTNode;

BSTNode *BSTSearch(BSTNode *bt,KeyType k)
{
	BSTNode *p=bt;
	while (p!=NULL)
	{
		if (p->key==k)			//�ҵ��ؼ���Ϊk�Ľ��
			return p;
		else if (k<p->key)
			p=p->lchild;		//������������
		else
            p=p->rchild;		//������������
	}
	return NULL;				//δ�ҵ�ʱ����NULL
}

int BSTInsert(BSTNode *&bt,KeyType k)
{	BSTNode *f,*p=bt;
	while (p!=NULL)					//�Ҳ���λ��,���Ҳ����½���˫��f���
	{
		if (p->key==k)				//���ܲ�����ͬ�Ĺؼ���
			return 0;
		f=p;						//fָ��p����˫�׽��
		if (k<p->key)
			p=p->lchild;			//���������в���
		else
			p=p->rchild;			//���������в���
	}
	p=(BSTNode *)malloc(sizeof(BSTNode));
	p->key=k;						//����һ����Źؼ���k���½��
	p->lchild=p->rchild=NULL;		//�½��������ΪҶ�ӽ������
	if (bt==NULL)					//ԭ��Ϊ��ʱ,p��Ϊ��������
		bt=p;
	else if (k<f->key)
		f->lchild=p;				//����p��Ϊf������
	else
		f->rchild=p;				//����p��Ϊf���Һ���
	return 1;						//����ɹ�����1
}

void CreateBST(BSTNode *&bt,KeyType a[],int n)
{
	bt=NULL;         			  //��ʼʱbtΪ����
	int i=0;
	while (i<n) 
	{  	
		BSTInsert(bt,a[i]); //���ؼ���a[i]���뵽����������bt��
		i++;
    }
}

void DestroyBST(BSTNode *&bt)
{
	if (bt!=NULL)
	{
		DestroyBST(bt->lchild);	//����������
		DestroyBST(bt->rchild);	//����������
		free(bt);				//�ͷŸ����
	}
}

void DispBST(BSTNode *bt)
{
	if (bt!=NULL)
	{	
		printf("%d",bt->key);		//��������
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	
			printf("(");			//�����������Һ���ʱ���'('
			DispBST(bt->lchild);	//�ݹ����������
			if (bt->rchild!=NULL)	//���Һ���ʱ���','
				printf(",");
			DispBST(bt->rchild);	//�ݹ����������
			printf(")");			//���һ��')'
		}
	}
}

int BSTDelete(BSTNode *&bt,KeyType k)
{
	BSTNode *p=bt,*f,*q,*q1,*f1;
	f=NULL;							//pָ����ȽϵĽ��,fָ��p��˫�׽��
	if (bt==NULL) return 0;			//��������0
	while (p!=NULL)					//���ҹؼ���Ϊk�Ľ��p��˫��f
	{	
		if (p->key==k)				//�ҵ��ؼ���Ϊk�Ľ��,�˳�whileѭ��
			break;
		f=p;
		if (k<p->key) 
			p=p->lchild;			//���������в���
		else
			p=p->rchild;			//���������в���
	}
	if (p==NULL) return 0;			//δ�ҵ��ؼ���Ϊk�Ľ��,����0
	else if (p->lchild==NULL)		//��ɾ���pû�������������
	{
		if (f==NULL)				//p�Ǹ����,�����Һ����滻��
			bt=p->rchild;
		else if (f->lchild==p)		//p��˫�׽�������,�������Һ����滻��
			f->lchild=p->rchild;
		else if(f->rchild==p)		//p��˫�׽����Һ���,�������Һ����滻��
			f->rchild=p->rchild;
		free(p);					//�ͷű�ɾ���
	}
	else if (p->rchild==NULL)		//��ɾ���pû�������������
	{
		if (f==NULL)				//p�Ǹ����,���������滻��
			bt=p->lchild;
		if (f->lchild==p)			//p��˫�׽�������,�����������滻��
			f->lchild=p->lchild;
		else if(f->rchild==p)		//p��˫�׽����Һ���,�����������滻��
			f->rchild=p->lchild;
		free(p);					//�ͷű�ɾ���
	}
	else							//��ɾ���p�������������������������
	{
		q=p->lchild;				//qָ��p��������
		if (q->rchild==NULL)		//��q������Һ���
		{
			p->key=q->key;			//��p���ֵ��q���ֵ����
			p->data=q->data;
			p->lchild=q->lchild;	//ɾ��q���
			free(q);				//�ͷ�q���
		}
		else						//��q������Һ���
		{
			f1=q;q1=f1->rchild; 
			while (q1->rchild!=NULL)//����q���������½��q1,f1ָ����˫��
			{	
				f1=q1;
				q1=q1->rchild;
			}
			p->key=q1->key;			//��p���ֵ��q1���ֵ����
			p->data=q1->data;
			if (f1->lchild==q1)		//ɾ��q1���:q1��f1������,ɾ��q1
				f1->lchild=q1->rchild;
			else if (f1->rchild==q1)//ɾ��q1���:q1��f1���Һ���,ɾ��q1
				f1->rchild=q1->lchild;
			free(q1);				//�ͷ�q1��ռ�ռ�
		}
	}
	return 1;						//ɾ���ɹ�����1
}
