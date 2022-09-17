#include "SqString.cpp"				//包含顺序串的基本运算函数
int Count(SqString s,SqString t)
{
	int num=0,i,j,k;				//i和j分别扫描主串s和子串t
	i=0;
	while (i<=s.length-t.length)
	{
		for (k=i,j=0;j<t.length && s.data[k]==t.data[j];k++,j++);
		if (j==t.length)			//j等于子串t的长度
		{	num++;					//找到一个子串
			i+=t.length;			//i跳过t.length个字符
		}
		else
			i++;					//i后移一个字符
	}
	return(num);
}

void main()
{
	SqString s,t;
	Assign(s,"aababababc");
	Assign(t,"abab");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("Count:%d\n",Count(s,t));
}

