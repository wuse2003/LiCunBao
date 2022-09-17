#include <stdio.h>
#include <string.h>
#define MaxSize 100
typedef int KeyType;
typedef struct
{
	KeyType key;			//�ؼ���
} SqType;
typedef struct
{	KeyType key;			//��ؼ���
	int low,high;			//���ʶ
} IdxType;
int BlkSearch(SqType R[],int n,IdxType I[] ,int b,int k)
//�������ݱ�ΪR[0..n-1]��������ΪI[0..b-1]����k���ڵļ�¼���߼����
{	int low=0,high=b-1,mid,i;
	int s=(n+b-1)/b;		//sΪÿ���Ԫ�ظ�����ӦΪn/b������ȡ��
	printf("s=%d\n",s);
	while (low<=high)		//���������н����۰����,�ҵ���λ��Ϊhigh+1
	{	mid=(low+high)/2;
		if (I[mid].key>=k)
			high=mid-1;
		else 
			low=mid+1;
	}
	//Ӧ���������high+1����,����˳����ڸÿ���˳�����
	i=I[high+1].low;
	while (i<=I[high+1].high && R[i].key!=k)
		i++;
	if (i<=I[high+1].high)
		return i+1;		//���ҳɹ�,���ظ�Ԫ�ص��߼����
	else
		return 0;		//����ʧ��,����0
}
void main()
{
	int n=16,b=4,i;
	KeyType k=48;
	SqType R[MaxSize]={9,22,12,14,35,42,44,38,48,60,58,47,78,80,77,82};	//���������ݱ�
	IdxType I[MaxSize]={{22,0,3},{44,4,7},{60,8,11},{82,12,15}};		//������������
	i=BlkSearch(R,n,I,b,k);
	if (i>0)
		printf("�ؼ���Ϊ%d�ļ�¼���߼������%d\n",k,i);
	else
		printf("û���ҵ��ؼ���Ϊ%d�ļ�¼\n",k);
}

