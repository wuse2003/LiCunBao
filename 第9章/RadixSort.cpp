#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 100
#define MAXD 10				//�ؼ������λ��
#define MAXR 20				//���Ļ���
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//��Źؼ���,KeyTypeΪ�ؼ�������
	ElemType data;			//��������,ElemTypeΪ�������ݵ�����
} SqType;
typedef struct rnode
{	char key[MAXD];			//��Źؼ���
	ElemType data;			//�����������
	struct rnode *next;
} RadixNode;				//������������
void CreateSLink(RadixNode *&h,char *A[],int n)	//��������ͷ���ĵ�����h
{
	int i;
	RadixNode *p,*tc;
	h=(RadixNode *)malloc(sizeof(RadixNode));
	strcpy(h->key,A[0]);
	tc=h;
	for (i=1;i<n;i++)
	{
		p=(RadixNode *)malloc(sizeof(RadixNode));
		strcpy(p->key,A[i]);
		tc->next=p;
		tc=p;
	}
	tc->next=NULL;
}
void DestroySLink(RadixNode *&h)	//���ٲ���ͷ���ĵ�����h
{
	RadixNode *pre=h,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
}
void DispLink(RadixNode *h)			//�������ͷ���ĵ�����h
{
	RadixNode *p=h;
	while (p!=NULL)
	{
		printf("%s ",p->key);
		p=p->next;
	}
	printf("\n");
}
void RadixSort1(RadixNode *&h,int d,int r)	//���λ���Ȼ��������㷨
//ʵ�ֻ�������:hΪ���������е�����ָ��,rΪ����,dΪ�ؼ���λ��
{	RadixNode *head[MAXR];					//�������Ӷ�ͷ����
	RadixNode *tail[MAXR];					//�������Ӷ�β����
	RadixNode *p,*tc;
	int i,j,k;
	for (i=d-1;i>=0;i--)					//�Ӹ�λ����λѭ��
	{	for (j=0;j<r;j++) 					//��ʼ���������ס�βָ��
			head[j]=tail[j]=NULL;
		p=h;
		while (p!=NULL)						//���䣺����ԭ������ÿ�����ѭ��
		{
			k=p->key[i]-'0';				//�ҵ�k������
			if (head[k]==NULL)				//��k�����ӿ�ʱ����ͷ��β��ָ��p���
				head[k]=tail[k]=p;
			else
			{	tail[k]->next=p;			//��k�����ӷǿ�ʱ��p������
				tail[k]=p;
			}
			p=p->next;						//ȡ��һ���������Ԫ��
		}
		h=NULL;								//������h���ռ����н��
		for (j=0;j<r;j++)					//�ռ�������ÿһ������ѭ��
			if (head[j]!=NULL)				//����j�������ǵ�һ���ǿ�����
			{	if (h==NULL)
				{	h=head[j];
					tc=tail[j];
				}
				else						//����j�������������ǿ�����
				{	tc->next=head[j];
					tc=tail[j];
				}
			}
		tc->next=NULL;						//β����next����NULL
		printf("i=%d������: ",i); DispLink(h);

	}
}

void main()
{
	char *A[]={"75","87","68","92","88","61","77","96","80","72"};
	int n=10;
	RadixNode *h;
	CreateSLink(h,A,n);
	printf("��ʼ����:    "); DispLink(h);
	RadixSort1(h,2,10);
	printf("������:    "); DispLink(h);
	DestroySLink(h);
}
