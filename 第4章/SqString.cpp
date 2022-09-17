#include <stdio.h>
#define MaxSize 100		//串中最多字符个数
typedef struct
{	char data[MaxSize];	//存放串字符
	int length;			//存放串的实际长度
} SqString;				//顺序串类型
void Assign(SqString &s,char str[])
{	int i=0;
	while (str[i]!='\0')	//遍历str的所有字符
	{	s.data[i]=str[i];
		i++;
	}
	s.length=i;
}
void DestroyStr(SqString s)
{    }
void StrCopy(SqString &s,SqString t)
{	int i;
	for (i=0;i<t.length;i++)
		s.data[i]=t.data[i];
	s.length=t.length;
}
int StrLength(SqString s)
{
	return(s.length);
}
int StrEqual(SqString s,SqString t)
{	int i=0;
	if (s.length!=t.length)				//串长不同时返回0
		return(0);
	else
	{	for (i=0;i<s.length;i++)
			if (s.data[i]!=t.data[i])	//有一个对应字符不同时返回0
				return 0;
		return 1;
	}
}
SqString Concat(SqString s,SqString t)
{	SqString r;
	int i,j;
	for (i=0;i<s.length;i++)		//将s复制到r
		r.data[i]=s.data[i];
	for (j=0;j<t.length;j++)		//将t复制到r
		r.data[s.length+j]=t.data[j];
	r.length=i+j;
	return r;						//返回r
}
SqString SubStr(SqString s,int i,int j)
{	SqString t;
	int k;
	if (i<1 || i>s.length || j<1 || i+j>s.length+1)
		t.length=0;			//参数错误时返回空串
	else
	{	for (k=i-1;k<i+j;k++)
			t.data[k-i+1]=s.data[k];
		t.length=j;
	}
	return t;
}
int Index(SqString s,SqString t)
{	int i=0,j=0;					//i和j分别扫描主串s和子串t
	while (i<s.length && j<t.length)
	{	if (s.data[i]==t.data[j])	//对应字符相同时,继续比较下一对字符
		{	i++;
			j++;
		}
		else				//否则,主子串指针回溯重新开始下一次匹配
		{	i=i-j+1;
			j=0;
		}
	}
	if (j>=t.length) return i-t.length+1;	//返回第一个字符的位置
	else return 0;							//返回0
}
int InsStr(SqString &s,int i,SqString t)
{	int j;
	if (i<1 || i>s.length+1)
		return 0;							//位置参数错误返回0
	else
	{	for (j=s.length-1;j>=i-1;j--)		//将s.data[i-1..s.length-1]
			s.data[j+t.length]=s.data[j];	//后移t.length个位置
		for (j=0;j<t.length;j++)			//插入子串t
			s.data[i+j-1]=t.data[j];
		s.length=s.length+t.length;			//修改s串长度
		return 1;							//成功插入返回1
	}
}
int DelStr(SqString &s,int i,int j)
{	int k;
	if (i<1 || i>s.length || j<1 || i+j>s.length+1)
		return 0;						//位置参数值错误
	else
	{	for (k=i+j-1;k<s.length;k++)	//将s的第i+j位置之后的字符前移j位
			s.data[k-j]=s.data[k];
		s.length=s.length-j;			//修改s的长度
		return 1;						//成功删除返回1
	}
}
SqString RepStrAll(SqString s,SqString s1,SqString s2)
{	int i;
	i=Index(s,s1);
	while (i>0)
	{	DelStr(s,i,s1.length);	//删除子串s1
		InsStr(s,i,s2);			//插入子串s2
		i=Index(s,s1);
	}
	return(s);
}
void DispStr(SqString s)
{	int i;
	for (i=0;i<s.length;i++)
		printf("%c",s.data[i]);
	printf("\n");
}
