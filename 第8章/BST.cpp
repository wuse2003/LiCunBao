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
		if (p->key==k)			//找到关键字为k的结点
			return p;
		else if (k<p->key)
			p=p->lchild;		//沿左子树查找
		else
            p=p->rchild;		//沿右子树查找
	}
	return NULL;				//未找到时返回NULL
}

int BSTInsert(BSTNode *&bt,KeyType k)
{	BSTNode *f,*p=bt;
	while (p!=NULL)					//找插入位置,即找插入新结点的双亲f结点
	{
		if (p->key==k)				//不能插入相同的关键字
			return 0;
		f=p;						//f指向p结点的双亲结点
		if (k<p->key)
			p=p->lchild;			//在左子树中查找
		else
			p=p->rchild;			//在右子树中查找
	}
	p=(BSTNode *)malloc(sizeof(BSTNode));
	p->key=k;						//建立一个存放关键字k的新结点
	p->lchild=p->rchild=NULL;		//新结点总是作为叶子结点插入的
	if (bt==NULL)					//原树为空时,p作为根结点插入
		bt=p;
	else if (k<f->key)
		f->lchild=p;				//插入p作为f的左孩子
	else
		f->rchild=p;				//插入p作为f的右孩子
	return 1;						//插入成功返回1
}

void CreateBST(BSTNode *&bt,KeyType a[],int n)
{
	bt=NULL;         			  //初始时bt为空树
	int i=0;
	while (i<n) 
	{  	
		BSTInsert(bt,a[i]); //将关键字a[i]插入到二叉排序树bt中
		i++;
    }
}

void DestroyBST(BSTNode *&bt)
{
	if (bt!=NULL)
	{
		DestroyBST(bt->lchild);	//销毁左子树
		DestroyBST(bt->rchild);	//销毁右子树
		free(bt);				//释放根结点
	}
}

void DispBST(BSTNode *bt)
{
	if (bt!=NULL)
	{	
		printf("%d",bt->key);		//输出根结点
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	
			printf("(");			//根结点有左或右孩子时输出'('
			DispBST(bt->lchild);	//递归输出左子树
			if (bt->rchild!=NULL)	//有右孩子时输出','
				printf(",");
			DispBST(bt->rchild);	//递归输出右子树
			printf(")");			//输出一个')'
		}
	}
}

int BSTDelete(BSTNode *&bt,KeyType k)
{
	BSTNode *p=bt,*f,*q,*q1,*f1;
	f=NULL;							//p指向待比较的结点,f指向p的双亲结点
	if (bt==NULL) return 0;			//空树返回0
	while (p!=NULL)					//查找关键字为k的结点p及双亲f
	{	
		if (p->key==k)				//找到关键字为k的结点,退出while循环
			break;
		f=p;
		if (k<p->key) 
			p=p->lchild;			//在左子树中查找
		else
			p=p->rchild;			//在右子树中查找
	}
	if (p==NULL) return 0;			//未找到关键字为k的结点,返回0
	else if (p->lchild==NULL)		//被删结点p没有左子树的情况
	{
		if (f==NULL)				//p是根结点,则用右孩子替换它
			bt=p->rchild;
		else if (f->lchild==p)		//p是双亲结点的左孩子,则用其右孩子替换它
			f->lchild=p->rchild;
		else if(f->rchild==p)		//p是双亲结点的右孩子,则用其右孩子替换它
			f->rchild=p->rchild;
		free(p);					//释放被删结点
	}
	else if (p->rchild==NULL)		//被删结点p没有右子树的情况
	{
		if (f==NULL)				//p是根结点,则用左孩子替换它
			bt=p->lchild;
		if (f->lchild==p)			//p是双亲结点的左孩子,则用其左孩子替换它
			f->lchild=p->lchild;
		else if(f->rchild==p)		//p是双亲结点的右孩子,则用其左孩子替换它
			f->rchild=p->lchild;
		free(p);					//释放被删结点
	}
	else							//被删结点p既有左子树又有右子树的情况
	{
		q=p->lchild;				//q指向p结点的左孩子
		if (q->rchild==NULL)		//若q结点无右孩子
		{
			p->key=q->key;			//将p结点值用q结点值代替
			p->data=q->data;
			p->lchild=q->lchild;	//删除q结点
			free(q);				//释放q结点
		}
		else						//若q结点有右孩子
		{
			f1=q;q1=f1->rchild; 
			while (q1->rchild!=NULL)//查找q结点的最右下结点q1,f1指向其双亲
			{	
				f1=q1;
				q1=q1->rchild;
			}
			p->key=q1->key;			//将p结点值用q1结点值代替
			p->data=q1->data;
			if (f1->lchild==q1)		//删除q1结点:q1是f1的左孩子,删除q1
				f1->lchild=q1->rchild;
			else if (f1->rchild==q1)//删除q1结点:q1是f1的右孩子,删除q1
				f1->rchild=q1->lchild;
			free(q1);				//释放q1所占空间
		}
	}
	return 1;						//删除成功返回1
}
