#include <stdio.h>
#include <malloc.h>
#define MAX 20
typedef struct node	//定义多项式单链表结点类型
{  	double coef;	//系数
	int exp;		//指数
	struct node *next;
} PolyNode;

void CreateListR(PolyNode *&L,double a[],int b[],int n) //建立多项式单链表
{	PolyNode *s,*tc;
	int i;
	L=(PolyNode *)malloc(sizeof(PolyNode));
	tc=L;						//tc始终指向尾结点,开始时指向头结点
	for (i=0;i<n;i++)
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));         
		s->coef=a[i];
		s->exp=b[i];
		tc->next=s;					//将结点s插入tc之后
		tc=s;
	}
	tc->next=NULL;					//尾结点next域置为NULL
}
void DestroyList(PolyNode *&L)		//销毁多项式单链表
{ 	PolyNode *p=L,*q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
void DispPoly(PolyNode *L)				//输出多项式单链表
{
	PolyNode *p=L->next;
	while (p!=NULL)
	{
		printf("(%gx^%d) ",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
}
void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc)	//相加运算算法
{
	PolyNode *pa=ha->next,*pb=hb->next,*s,*tc;
	double c;
	hc=(PolyNode *)malloc(sizeof(PolyNode)); 
	tc=hc;
	while (pa!=NULL && pb!=NULL)
	{	if (pa->exp>pb->exp)
		{	s=(PolyNode *)malloc(sizeof(PolyNode));   
			s->exp=pa->exp;s->coef=pa->coef;
			tc->next=s;tc=s;
			pa=pa->next;
		}
		else if (pa->exp<pb->exp)
		{	s=(PolyNode *)malloc(sizeof(PolyNode));   
			s->exp=pb->exp;s->coef=pb->coef;
			tc->next=s;tc=s;
			pb=pb->next;
		}
		else					//pa->exp=pb->exp
		{	c=pa->coef+pb->coef;
			if (c!=0)			//系数之和不为0时创建新结点
			{ 	s=(PolyNode *)malloc(sizeof(PolyNode)); 
				s->exp=pa->exp;s->coef=c;	
				tc->next=s;
				tc=s;
			}
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL) pa=pb;		//复制余下的结点
	while (pa!=NULL)
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));
		s->exp=pa->exp;
		s->coef=pa->coef;
		tc->next=s;tc=s;
		pa=pa->next;
	}
	tc->next=NULL;
}
void main()
{	PolyNode *Poly1,*Poly2,*Poly3;
	double a[MAX];
	int b[MAX],n;
	//----创建第1个多项单链表-----
	a[0]=3.2;b[0]=5;
	a[1]=2.0;b[1]=3;
	a[2]=-6.0;b[2]=1;
	a[3]=10.0;b[3]=0;
	n=4;
	CreateListR(Poly1,a,b,n);
	printf("  第1个多项式:　");DispPoly(Poly1);
	//----创建第2个多项单链表-----
	a[0]=1.8; b[0]=5;
	a[1]=-2.5;b[1]=4;
	a[2]=-2.0;b[2]=3;
	a[3]=1.0; b[3]=2;
	a[4]=6.0;b[4]=1;
	a[5]=-5.0;b[5]=0;
	n=6;
	CreateListR(Poly2,a,b,n);
	printf("  第2个多项式:　");DispPoly(Poly2);
	Add(Poly1,Poly2,Poly3);
	printf("  相加后多项式:　");DispPoly(Poly3);
	DestroyList(Poly1);
	DestroyList(Poly2);
	DestroyList(Poly3);
}
