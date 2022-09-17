#include "SqString.cpp"		//包含顺序串的基本运算函数
void main()
{	SqString s1,s2,s3,s4,s5,s6,s7;
	Assign(s1,"abcd");
	printf("s1:");DispStr(s1);
	printf("s1的长度:%d\n",StrLength(s1));
	printf("s1=>s2\n");
	StrCopy(s2,s1);
	printf("s2:");DispStr(s2);
	printf("s1和s2%s\n",(StrEqual(s1,s2)==1?"相同":"不相同"));
	Assign(s3,"12345678");
	printf("s3:");DispStr(s3);
	printf("s1和s3连接=>s4\n");
	s4=Concat(s1,s3);
	printf("s4:");DispStr(s4);
	printf("s3[2..5]=>s5\n");
	s5=SubStr(s3,2,4);
	printf("s5:");DispStr(s5);
	Assign(s6,"567");
	printf("s6:");DispStr(s6);
	printf("s6在s3中位置:%d\n",Index(s3,s6));
	printf("从s3中删除s3[3..6]字符\n");
	DelStr(s3,3,4);
	printf("s3:");DispStr(s3);
	printf("从s4中将s6替换成s1=>s7\n");
	s7=RepStrAll(s4,s6,s1);
	printf("s7:");DispStr(s7);
}

