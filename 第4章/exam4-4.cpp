#include "LinkString.cpp"		//���������Ļ������㺯��
void Repl(LinkString *&s)
{	LinkString *p=s->next,*q;
	int find=0;
	while (p->next!=NULL && find==0)			//����'ab'�Ӵ�
	{	if (p->data=='a' && p->next->data=='b')//�ҵ���ab�Ӵ�
		{	p->data='x';p->next->data='z';		//�滻Ϊxyz
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

