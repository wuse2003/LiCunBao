#include "SqString.cpp"		//����˳�򴮵Ļ������㺯��
int EqSubString(SqString s,SqString &t)
{
	int i=0,counti,maxi=i,maxcount=0,j,k;
	while (i<s.length)			//ɨ���ַ���s
	{
		j=i+1;
		counti=1;				//ͳ��λ��i��ʼ�ĵ�ֵ�Ӵ�����counti
		while (j<s.length && s.data[i]==s.data[j])
		{	j++;
			counti++;
		}
		if (maxcount<counti)	//���ϳ��ĵ�ֵ�Ӵ�������maxi��maxcount��
		{	maxi=i;
			maxcount=counti;
		}
		i=j;
	}
	if (maxcount>1)				//�ҵ����ȴ���1�ĵ�ֵ�Ӵ�,�������t��
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
	else return 0;				//û�г��ȴ���1�ĵ�ֵ�Ӵ�����0
}

void main()
{
	SqString s,t;
	Assign(s,"aaacccc");
	printf("s:"); DispStr(s);
	if (EqSubString(s,t))
	{
		printf("����ֵ�Ӵ�:"); DispStr(t);
	}
	else
		printf("û�г��ȴ���1�ĵ�ֵ�Ӵ�\n");

}

