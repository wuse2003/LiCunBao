#include "LinkString.cpp"		//包含链串的基本运算函数
void Repl(LinkString *&s)
{	LinkString *p=s->next,*q;
	int find=0;
	while (p->next!=NULL && find==0)			//查找'ab'子串
	{	if (p->data=='a' && p->next->data=='b')//找到了ab子串
		{	p->data='x';p->next->data='z';		//替换为xyz
			q=(LinkString *)malloc(sizeof(LinkString));
			q->data='y';
			q->next=p->next;
			p->next=q;
			find=1;
		}
		else p=p->next; 
	}
}
void main()
{
	LinkString *s;
	Assign(s,"aabcabc");
	printf("s:");DispStr(s);
	printf("ab=>xyz\n");
	Repl(s);
	printf("s:");DispStr(s);
}

