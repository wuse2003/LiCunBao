#include <stdio.h>
#include <string.h>
#define MaxSize 100
typedef int KeyType;
typedef struct
{
	int no;				//ѧ��,��Ϊ�ؼ���
	char name[10];		//����
	int score;			//����
} SqType;
typedef struct
{
	KeyType key;
	int pos;
} IdxType;
int BinSearch(IdxType I[],int n,int k)	//�������㷨
{	int low=0,high=n-1,mid;
	while (low<=high)				//��ǰ�������Ԫ��ʱѭ��
	{	mid=(low+high)/2;			//�����������м�λ��
		if (I[mid].key==k)			//���ҳɹ��������߼����mid+1
			return mid+1;			//�ҵ��󷵻����߼����mid+1
		if (I[mid].key>k)			//������I[low..mid-1]�в���
			high=mid-1;
		else						//I[mid].key<k
			low=mid+1;				//������R[mid+1..high]�в���
	}
	return 0;						//����ǰ��������û��Ԫ��ʱ����0
}
int IdxSearch(SqType R[],IdxType I[],int n,KeyType k)	//��������
{
	int i;
	i=BinSearch(I,n,k);
	if (i>0)		//�����������ҵ���,�������߼����
		return I[i-1].pos+1;
	else
		return 0;	//����������û�ҵ�,����0
}
void main()
{
	int n=5,i;
	KeyType k=201204;
	SqType R[MaxSize]={{201201,"��ʵ",85},{201205,"���",82},{201206,"��Ӣ",92},{201202,"��ɽ",78},{201204,"�¹�",90}};
	IdxType I[MaxSize]={{201201,0},{201202,3},{201204,4},{201205,1},{201206,2}};
	i=IdxSearch(R,I,n,k);
	if (i>0)
		printf("�ؼ���Ϊ%d�ļ�¼���߼������%d\n",k,i);
	else
		printf("û���ҵ��ؼ���Ϊ%d�ļ�¼\n",k);
}

