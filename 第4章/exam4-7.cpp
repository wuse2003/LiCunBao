#define MaxSize 100
#include "LinkString.cpp"	//包含链串的基本运算函数
typedef struct 
{	char ch;				//字符
	int num;				//该字符出现的次数
} Mytype; 
void Statchar(LinkString *s,Mytype t[],int &n)
{
	int i;
	LinkString *p=s->next;
	n=0;
	while (p!=NULL)			//p扫描链串s
	{
		if (n==0)			//为第一个字符时直接放入t中
		{
			t[n].ch=p->data;
			t[n].num=1;
			n++;
		}
		else				//不为第一个字符的情况
		{
			i=0;
			while (i<n && t[i].ch!=p->data)
				i++;
			if (i<n)				//在t中找到为p->data的字符
				t[i].num++;
			else					//在t中未找到为p->data的字符
			{
				t[n].ch=p->data;
				t[n].num=1;
				n++;
			}
		}
		p=p->next;
	}
}

void main()
{
	Mytype t[MaxSize];
	int n,i;
	LinkString *s;
	Assign(s,"aabcabc");
	printf("s:");DispStr(s);
	Statchar(s,t,n);
	printf("统计情况:");
	for (i=0;i<n;i++)
		printf("%c[%d]  ",t[i].ch,t[i].num);
	printf("\n");
}

