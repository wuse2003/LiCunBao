#include "SqString.cpp"		//����˳�򴮵Ļ������㺯��
void main()
{	SqString s1,s2,s3,s4,s5,s6,s7;
	Assign(s1,"abcd");
	printf("s1:");DispStr(s1);
	printf("s1�ĳ���:%d\n",StrLength(s1));
	printf("s1=>s2\n");
	StrCopy(s2,s1);
	printf("s2:");DispStr(s2);
	printf("s1��s2%s\n",(StrEqual(s1,s2)==1?"��ͬ":"����ͬ"));
	Assign(s3,"12345678");
	printf("s3:");DispStr(s3);
	printf("s1��s3����=>s4\n");
	s4=Concat(s1,s3);
	printf("s4:");DispStr(s4);
	printf("s3[2..5]=>s5\n");
	s5=SubStr(s3,2,4);
	printf("s5:");DispStr(s5);
	Assign(s6,"567");
	printf("s6:");DispStr(s6);
	printf("s6��s3��λ��:%d\n",Index(s3,s6));
	printf("��s3��ɾ��s3[3..6]�ַ�\n");
	DelStr(s3,3,4);
	printf("s3:");DispStr(s3);
	printf("��s4�н�s6�滻��s1=>s7\n");
	s7=RepStrAll(s4,s6,s1);
	printf("s7:");DispStr(s7);
}

