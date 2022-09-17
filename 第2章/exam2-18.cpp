#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct node 
{	
	char name[10];					//����
	int score;						//�ɼ���
	struct node *next;				//ָ����
} StudList;							//ѧ��������������
void CreateStudent(StudList *&sl)	//����β�巨����ѧ��������
{	int n,i;
	StudList *s,*tc;
	sl=(StudList *)malloc(sizeof(StudList));	//����ͷ���
	tc=sl;							//tcʼ��ָ��β���,��ʼʱָ��ͷ���
	printf("  ѧ������:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{	s=(StudList *)malloc(sizeof(StudList));//�����½��
		printf("   ��%d��ѧ�������ͳɼ�:",i+1);
		scanf("%s",s->name);		//���������ͳɼ�
		scanf("%d",&s->score);
		tc->next=s;					//��*s����*tc֮��
		tc=s;
	}
	tc->next=NULL;					//β���next����ΪNULL
}
void SortList(StudList *&L)			//��ѧ���������ɼ��ݼ�����
{
	StudList *p,*pre,*q;
	p=L->next->next;				//pָ��L�ĵ�2�����ݽ��
	L->next->next=NULL;				//����ֻ��һ�����ݽ��������
	while (p!=NULL)
	{	q=p->next;					//q����*p����̽���ָ��
		pre=L;						//�������ͷ���бȽ�,preָ�����*p��ǰ�����
		while (pre->next!=NULL && pre->next->score>p->score)
			pre=pre->next;			//����������Ҳ���*p��ǰ�����*pre
		p->next=pre->next;			//��*pre֮�����*p
		pre->next=p;
		p=q;						//ɨ��ԭ���������µĽ��
	}
}
void DispList(StudList *L)			//���ѧ��������
{
	StudList *p=L->next;
	int i=1;
	printf("    ����       �� ��           �ɼ�\n");
	while (p!=NULL)
	{
		printf("    %d\t\t",i++);
		printf("%s\t\t",p->name);
		printf("%d\n",p->score);
		p=p->next;
	}
}
void DestroyList(StudList *&L)	//����ѧ��������
{
	StudList *pre=L,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p; p=p->next;		//pre��pͬ������
	}
	free(pre);
}
void main()
{
	StudList *st;
	printf("(1)����ѧ��������\n");
	CreateStudent(st);
	printf("(2)���ɼ��ݼ�����\n");
	SortList(st);
	printf("(3)�����Ľ��\n"); DispList(st);
	printf("(4)����ѧ��������\n");	DestroyList(st);
}
