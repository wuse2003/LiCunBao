#include "SqString.cpp"		//����˳�򴮵Ļ������㺯��
int Strcmp(SqString s,SqString t)
{	int i,comlen;
	if (s.length<t.length) comlen=s.length;	//��s��t�Ĺ�ͬ����
	else comlen=t.length;
	for (i=0;i<comlen;i++)			//�ڹ�ͬ����������ַ��Ƚ�
		if (s.data[i]>t.data[i])
			return 1;
		else if (s.data[i]<t.data[i])
			return -1;
	if (s.length==t.length)			//s==t
		return 0;
	else if (s.length>t.length)		//s>t
		return 1;
	else  return -1;				//s<t
}

void main()
{
	SqString s,t;
	Assign(s,"ac");
	Assign(t,"abcd");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	switch(Strcmp(s,t))
	{
	case 0:printf("s=t\n");
		break;
	case 1:printf("s>t\n");
		break;
	case -1:printf("s<t\n");
		break;
	}
}

