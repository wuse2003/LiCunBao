#define MaxSize 100
#include "LinkString.cpp"	//���������Ļ������㺯��
typedef struct 
{	char ch;				//�ַ�
	int num;				//���ַ����ֵĴ���
} Mytype; 
void Statchar(LinkString *s,Mytype t[],int &n)
{
	int i;
	LinkString *p=s->next;
	n=0;
	while (p!=NULL)			//pɨ������s
	{
		if (n==0)			//Ϊ��һ���ַ�ʱֱ�ӷ���t��
		{
			t[n].ch=p->data;
			t[n].num=1;
			n++;
		}
		else				//��Ϊ��һ���ַ������
		{
			i=0;
			while (i<n && t[i].ch!=p->data)
				i++;
			if (i<n)				//��t���ҵ�Ϊp->data���ַ�
				t[i].num++;
			else					//��t��δ�ҵ�Ϊp->data���ַ�
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
	printf("ͳ�����:");
	for (i=0;i<n;i++)
		printf("%c[%d]  ",t[i].ch,t[i].num);
	printf("\n");
}

