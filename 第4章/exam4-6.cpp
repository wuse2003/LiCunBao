#include "SqString.cpp"		//包含顺序串的基本运算函数
int EqSubString(SqString s,SqString &t)
{
	int i=0,counti,maxi=i,maxcount=0,j,k;
	while (i<s.length)			//扫描字符串s
	{
		j=i+1;
		counti=1;				//统计位置i开始的等值子串长度counti
		while (j<s.length && s.data[i]==s.data[j])
		{	j++;
			counti++;
		}
		if (maxcount<counti)	//将较长的等值子串保存在maxi和maxcount中
		{	maxi=i;
			maxcount=counti;
		}
		i=j;
	}
	if (maxcount>1)				//找到长度大于1的等值子串,将其存入t中
	{
		k=0;
		for (i=maxi;i<maxi+maxcount;i++)
		{
			t.data[k]=s.data[i];
			k++;
		}
		t.length=k;
		return 1;
	}
	else return 0;				//没有长度大于1的等值子串返回0
}

void main()
{
	SqString s,t;
	Assign(s,"aaacccc");
	printf("s:"); DispStr(s);
	if (EqSubString(s,t))
	{
		printf("最大等值子串:"); DispStr(t);
	}
	else
		printf("没有长度大于1的等值子串\n");

}

