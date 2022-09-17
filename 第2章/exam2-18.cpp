#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node 
{	
	char name[10];					//姓名
	int score;						//成绩域
	struct node *next;				//指针域
} StudList;							//学生单链表结点类型
void CreateStudent(StudList *&sl)	//采用尾插法创建学生单链表
{	int n,i;
	StudList *s,*tc;
	sl=(StudList *)malloc(sizeof(StudList));	//创建头结点
	tc=sl;							//tc始终指向尾结点,开始时指向头结点
	printf("  学生人数:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{	s=(StudList *)malloc(sizeof(StudList));//创建新结点
		printf("   第%d个学生姓名和成绩:",i+1);
		scanf("%s",s->name);		//输入姓名和成绩
		scanf("%d",&s->score);
		tc->next=s;					//将*s插入*tc之后
		tc=s;
	}
	tc->next=NULL;					//尾结点next域置为NULL
}
void SortList(StudList *&L)			//将学生单链表按成绩递减排序
{
	StudList *p,*pre,*q;
	p=L->next->next;				//p指向L的第2个数据结点
	L->next->next=NULL;				//构造只含一个数据结点的有序表
	while (p!=NULL)
	{	q=p->next;					//q保存*p结点后继结点的指针
		pre=L;						//从有序表开头进行比较,pre指向插入*p的前驱结点
		while (pre->next!=NULL && pre->next->score>p->score)
			pre=pre->next;			//在有序表中找插入*p的前驱结点*pre
		p->next=pre->next;			//将*pre之后插入*p
		pre->next=p;
		p=q;						//扫描原单链表余下的结点
	}
}
void DispList(StudList *L)			//输出学生单链表
{
	StudList *p=L->next;
	int i=1;
	printf("    名次       姓 名           成绩\n");
	while (p!=NULL)
	{
		printf("    %d\t\t",i++);
		printf("%s\t\t",p->name);
		printf("%d\n",p->score);
		p=p->next;
	}
}
void DestroyList(StudList *&L)	//销毁学生单链表
{
	StudList *pre=L,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p; p=p->next;		//pre、p同步后移
	}
	free(pre);
}
void main()
{
	StudList *st;
	printf("(1)建立学生单链表\n");
	CreateStudent(st);
	printf("(2)按成绩递减排序\n");
	SortList(st);
	printf("(3)排序后的结果\n"); DispList(st);
	printf("(4)销毁学生单链表\n");	DestroyList(st);
}
