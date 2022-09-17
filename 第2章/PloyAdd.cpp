#include <stdio.h>
#include <malloc.h>
#define MAX 20
typedef struct node	//�������ʽ������������
{  	double coef;	//ϵ��
	int exp;		//ָ��
	struct node *next;
} PolyNode;

void CreateListR(PolyNode *&L,double a[],int b[],int n) //��������ʽ������
{	PolyNode *s,*tc;
	int i;
	L=(PolyNode *)malloc(sizeof(PolyNode));
	tc=L;						//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	for (i=0;i<n;i++)
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));         
		s->coef=a[i];
		s->exp=b[i];
		tc->next=s;					//�����s����tc֮��
		tc=s;
	}
	tc->next=NULL;					//β���next����ΪNULL
}
void DestroyList(PolyNode *&L)		//���ٶ���ʽ������
{ 	PolyNode *p=L,*q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
void DispPoly(PolyNode *L)				//�������ʽ������
{
	PolyNode *p=L->next;
	while (p!=NULL)
	{
		printf("(%gx^%d) ",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
}
void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc)	//��������㷨
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
			if (c!=0)			//ϵ��֮�Ͳ�Ϊ0ʱ�����½��
			{ 	s=(PolyNode *)malloc(sizeof(PolyNode)); 
				s->exp=pa->exp;s->coef=c;	
				tc->next=s;
				tc=s;
			}
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL) pa=pb;		//�������µĽ��
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
	//----������1���������-----
	a[0]=3.2;b[0]=5;
	a[1]=2.0;b[1]=3;
	a[2]=-6.0;b[2]=1;
	a[3]=10.0;b[3]=0;
	n=4;
	CreateListR(Poly1,a,b,n);
	printf("  ��1������ʽ:��");DispPoly(Poly1);
	//----������2���������-----
	a[0]=1.8; b[0]=5;
	a[1]=-2.5;b[1]=4;
	a[2]=-2.0;b[2]=3;
	a[3]=1.0; b[3]=2;
	a[4]=6.0;b[4]=1;
	a[5]=-5.0;b[5]=0;
	n=6;
	CreateListR(Poly2,a,b,n);
	printf("  ��2������ʽ:��");DispPoly(Poly2);
	Add(Poly1,Poly2,Poly3);
	printf("  ��Ӻ����ʽ:��");DispPoly(Poly3);
	DestroyList(Poly1);
	DestroyList(Poly2);
	DestroyList(Poly3);
}
