#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int no;					//С�����
	struct node *next;		//ָ����һ�����ָ��
} Child;					//�������
void CreateList(Child *&L,int n)	//������n������ѭ��������
{
	int i;
	Child *p,*tc;
	L=(Child *)malloc(sizeof(Child));
	L->no=1;					//�Ƚ���ֻ��һ��noΪ1���ĵ�����
	tc=L;
	for (i=2;i<=n;i++)
	{
		p=(Child *)malloc(sizeof(Child));
		p->no=i;				//����һ�����i�Ľ��
		tc->next=p; tc=p;		//��p�������ĩβ
	}
	tc->next=L;					//����һ��ͷ���ΪL��ѭ��������
}
void Joseph(int n,int m)		//���Լɪ������
{
	int i,j;
	Child *L,*p,*q;
	CreateList(L,n);
	for (i=1;i<=n;i++)			//����n��С��
	{
		p=L; j=1;
		while (j<m-1)			//��L��㿪ʼ������������m-1�����
		{
			j++;				//��������
			p=p->next;			//�Ƶ���һ�����
		}
		q=p->next;				//qָ���m�����
		printf("%d ",q->no);	//�ý�����
		p->next=q->next;		//ɾ��q���
		free(q);				//�ͷ���ռ�
		L=p->next;				//����һ��������¿�ʼ
	}
}
void main()
{
	int n=6,m=5;
	printf("n=%d,m=%d��Լɪ������:",n,m);
	Joseph(n,m); printf("\n");
}
