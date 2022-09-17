#include "LinkString.cpp"		//���������Ļ������㺯��
LinkString *FindCommnode(LinkString *str1,LinkString *str2)
{	int m,n;
	LinkString *p,*q;
	m=StrLength(str1);		//������str1�ĳ���m
	n=StrLength(str2);		//������str2�ĳ���n
	for (p=str1;m>n;m--)	//��m����str1����m-n+1�����
		p=p->next;
	for (q=str2;m<n;n--)	//��n����str1����n-m+1�����
		q=q->next;
	while (p->next!=NULL && p->next!=q->next)
	{	p=p->next;			//p��qͬ�������ҵ�һ��ָ��ֵ��ȵĽ��
		q=q->next;
	}
	return p->next;
}
void CreateString(LinkString *&str1,LinkString *&str2)	//�����������������
{
	LinkString *t,*tc;
	Assign(t,"ing");
	Assign(str1,"load");
	Assign(str2,"be");
	tc=str1;
	while (tc->next!=NULL)		//�ҵ�str1��β���
		tc=tc->next;
	tc->next=t->next;
	tc=str2;
	while (tc->next!=NULL)		//�ҵ�str2��β���
		tc=tc->next;
	tc->next=t->next;
	free(t);
}
void main()
{
	LinkString *str1,*str2,*p;
	CreateString(str1,str2);
	printf("str1:");DispStr(str1);
	printf("str2:");DispStr(str2);
	p=FindCommnode(str1,str2);
	printf("p:%c\n",p->data);
}

