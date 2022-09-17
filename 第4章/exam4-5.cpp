#include "LinkString.cpp"		//包含链串的基本运算函数
LinkString *FindCommnode(LinkString *str1,LinkString *str2)
{	int m,n;
	LinkString *p,*q;
	m=StrLength(str1);		//求链串str1的长度m
	n=StrLength(str2);		//求链串str2的长度n
	for (p=str1;m>n;m--)	//若m大，则str1后移m-n+1个结点
		p=p->next;
	for (q=str2;m<n;n--)	//若n大，则str1后移n-m+1个结点
		q=q->next;
	while (p->next!=NULL && p->next!=q->next)
	{	p=p->next;			//p、q同步后移找第一个指针值相等的结点
		q=q->next;
	}
	return p->next;
}
void CreateString(LinkString *&str1,LinkString *&str2)	//创建两个特殊的链串
{
	LinkString *t,*tc;
	Assign(t,"ing");
	Assign(str1,"load");
	Assign(str2,"be");
	tc=str1;
	while (tc->next!=NULL)		//找到str1的尾结点
		tc=tc->next;
	tc->next=t->next;
	tc=str2;
	while (tc->next!=NULL)		//找到str2的尾结点
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

