#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int no;					//小孩编号
	struct node *next;		//指向下一个结点指针
} Child;					//结点类型
void CreateList(Child *&L,int n)	//建立有n个结点的循环单链表
{
	int i;
	Child *p,*tc;
	L=(Child *)malloc(sizeof(Child));
	L->no=1;					//先建立只有一个no为1结点的单链表
	tc=L;
	for (i=2;i<=n;i++)
	{
		p=(Child *)malloc(sizeof(Child));
		p->no=i;				//建立一个存放i的结点
		tc->next=p; tc=p;		//将p结点链到末尾
	}
	tc->next=L;					//构成一个头结点为L的循环单链表
}
void Joseph(int n,int m)		//求解约瑟夫序列
{
	int i,j;
	Child *L,*p,*q;
	CreateList(L,n);
	for (i=1;i<=n;i++)			//出列n个小孩
	{
		p=L; j=1;
		while (j<m-1)			//从L结点开始报数，报到第m-1个结点
		{
			j++;				//报数递增
			p=p->next;			//移到下一个结点
		}
		q=p->next;				//q指向第m个结点
		printf("%d ",q->no);	//该结点出列
		p->next=q->next;		//删除q结点
		free(q);				//释放其空间
		L=p->next;				//从下一个结点重新开始
	}
}
void main()
{
	int n=6,m=5;
	printf("n=%d,m=%d的约瑟夫序列:",n,m);
	Joseph(n,m); printf("\n");
}
