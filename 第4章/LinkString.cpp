#include <stdio.h>
#include <malloc.h>
typedef struct node
{	char data;			//����ַ�
	struct node *next;	//ָ����
} LinkString;

void Assign(LinkString *&s,char str[])
{	int i=0;
	LinkString *p,*tc;
	s=(LinkString *)malloc(sizeof(LinkString));	//����ͷ���
	tc=s;				//tcָ��s����β���
	while (str[i]!='\0')
	{	p=(LinkString *)malloc(sizeof(LinkString));
		p->data=str[i];
		tc->next=p; tc=p;
		i++;
	}
	tc->next=NULL;		//β����next��NULL
}
void DestroyStr(LinkString *&s)
{	LinkString *pre=s,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p; p=p->next;	//pre��pͬ������
	}
	free(pre);
}
void StrCopy(LinkString *&s,LinkString *t)
{	LinkString *p=t->next,*q,*tc;
	s=(LinkString *)malloc(sizeof(LinkString));	//����ͷ���
	tc=s;				//tcָ��s��β���
	while (p!=NULL)		//����t�����н��
	{	q=(LinkString *)malloc(sizeof(LinkString));
		q->data=p->data;
		tc->next=q; tc=q;
		p=p->next;
	}
	tc->next=NULL;		//β����next��NULL
}
int StrLength(LinkString *s)
{	int n=0;
	LinkString *p=s->next;
	while (p!=NULL)		//ɨ������s���������ݽ��
	{	n++;
		p=p->next;
	}
	return n;
}
int StrEqual(LinkString *s,LinkString *t)
{	LinkString *p=s->next,*q=t->next;
	while (p!=NULL && q!=NULL)	//�Ƚ������ĵ�ǰ���
	{	if (p->data!=q->data)	//data�򲻵�ʱ����0
			return 0;
		p=p->next;				//p��q������һ�����
		q=q->next;
	}
	if (p!=NULL || q!=NULL)		//�������Ȳ���ʱ����0
		return 0;
	else return 1;				//�����������ʱ����1
}
LinkString *Concat(LinkString *s,LinkString *t)
{	LinkString *p=s->next,*q,*tc,*r;
	r=(LinkString *)malloc(sizeof(LinkString));  //����ͷ���
	tc=r;					//tc����ָ����������β���
	while (p!=NULL)			//��s�����Ƹ�r
	{	q=(LinkString *)malloc(sizeof(LinkString));
		q->data=p->data;
		tc->next=q; tc=q;
		p=p->next;
	}
	p=t->next;
	while (p!=NULL)			//��t�����Ƹ�r
	{	q=(LinkString *)malloc(sizeof(LinkString));
		q->data=p->data;
		tc->next=q; tc=q;
		p=p->next;
	}
	tc->next=NULL;
	return r;
}

LinkString *SubStr(LinkString *s,int i,int j)
{	int k=1;
	LinkString *r,*p=s->next,*q,*tc;
	r=(LinkString *)malloc(sizeof(LinkString));	//����ͷ���
	r->next=NULL;				//����rΪһ���մ�
	if (i<1) return r;			//i�������󷵻ؿմ�
	tc=r;						//tc����ָ����������β���
	while (k<i && p!=NULL)		//��s���ҵ�i�����*p
	{	p=p->next;
		k++;
	}
	if (p==NULL) return r;		//i�������󷵻ؿմ�
	k=1; q=p;
	while (k<j && q!=NULL)		//�ж�j�����Ƿ���ȷ
	{	q=q->next;
		k++;
	}
	if (q==NULL) return r;		//j�������󷵻ؿմ�
	k=1;
	while (k<=j && p!=NULL)		//���ƴ�*p��㿪ʼ��j����㵽r��
	{
		q=(LinkString *)malloc(sizeof(LinkString));
		q->data=p->data;
		tc->next=q; tc=q;
		p=p->next;
		k++;
	}
	tc->next=NULL;
	return r;
}

int Index(LinkString *s,LinkString *t)
{	LinkString *p=s->next,*p1,*q,*q1;
	int i=1;
	while (p!=NULL)				//����s��ÿ�����
	{	q=t->next;				//���Ǵ�t�ĵ�һ���ַ���ʼ�Ƚ�
		if (p->data==q->data)	//�ж�������ǰ�ַ����
		{	//�����ַ���ͬ,���ж�s����ַ��Ƿ���t֮���ַ�������ͬ
			p1=p->next;			//p1��q1ͬʱ����һ�����
			q1=q->next;
			while (p1!=NULL && q1!=NULL && p1->data==q1->data)
			{	p1=p1->next;	//p1��q1ͬʱ����һ�����
				q1=q1->next;
			}
			if (q1==NULL)	//������ͬ,�򷵻���ͬ���Ӵ�����ʼλ��
				return i;
		}
		p=p->next; i++;
	}
	return 0;				//�������Ӵ�,����0
}

int InsStr(LinkString *&s,int i,LinkString *t)
{	LinkString *p=s,*q,*r;		//pָ��s��ͷ���
	int k=1;
	if (i<1) return 0;			//����i���󷵻�0
	while (k<i && p!=NULL)		//��ͷ��㿪ʼ�ҵ�i����㼴��i-1�����ݽ��*p
	{	k++;
		p=p->next;
	}
	if (p==NULL) return 0;		//����i���󷵻�0
	q=t->next;					//qָ��t�ĵ�һ�����ݽ��
	while (q!=NULL)				//������ȷ��t�����н�㸴�Ʋ����뵽*p֮��
	{	r=(LinkString *)malloc(sizeof(LinkString));
		r->data=q->data;
		r->next=p->next;
		p->next=r;
		p=p->next;
		q=q->next;
	}
	return 1;
}

int DelStr(LinkString *&s,int i,int j)
{
	LinkString *p=s,*q;			//pָ��s��ͷ���
	int k=1;
	if (i<1 || j<1) return 0;	//i��j�������󷵻�0
	while (k<i && p!=NULL)		//��ͷ��㿪ʼ�ҵ�i����㼴��i-1�����ݽ��*p
	{	p=p->next;
		k++;
	}
	if (p==NULL) return 0;		//i�������󷵻ؿմ�
	k=1;
	q=p->next;
	while (k<j && q!=NULL)		//�ж�j�����Ƿ���ȷ
	{	q=q->next;
		k++;
	}
	if (q==NULL) return 0;		//j�������󷵻ؿմ�
	k=1;
	while (k<=j)				//ɾ��*p���֮���j�����
	{
		q=p->next;
		if (q->next==NULL)		//��*q��β���
		{	free(q);			//�ͷ�*q���
			p->next=NULL;		//*p����Ϊβ���
		}
		else					//��*q����β���
		{
			p->next=q->next;	//ɾ��*q���
			free(q);			//�ͷ�*q���
		}
		k++;
	}
	return 1;					//�ɹ�ɾ������1
}
LinkString *RepStrAll(LinkString *s,LinkString *s1,LinkString *s2)
{
	int i;
	i=Index(s,s1);
	while (i>0)
	{
		DelStr(s,i,StrLength(s1));	//ɾ���Ӵ�s1
		InsStr(s,i,s2);				//�����Ӵ�s2
		i=Index(s,s1);
	}
	return s;
}
void DispStr(LinkString *s)
{	LinkString *p=s->next;
	while (p!=NULL)
	{	printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
