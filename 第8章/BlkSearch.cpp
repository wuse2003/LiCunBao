#include <stdio.h>
#include <string.h>
#define MaxSize 100
typedef int KeyType;
typedef struct
{
	KeyType key;			//关键字
} SqType;
typedef struct
{	KeyType key;			//块关键字
	int low,high;			//块标识
} IdxType;
int BlkSearch(SqType R[],int n,IdxType I[] ,int b,int k)
//在主数据表为R[0..n-1]，索引表为I[0..b-1]中找k所在的记录的逻辑序号
{	int low=0,high=b-1,mid,i;
	int s=(n+b-1)/b;		//s为每块的元素个数，应为n/b的向上取整
	printf("s=%d\n",s);
	while (low<=high)		//在索引表中进行折半查找,找到的位置为high+1
	{	mid=(low+high)/2;
		if (I[mid].key>=k)
			high=mid-1;
		else 
			low=mid+1;
	}
	//应在索引表的high+1块中,再在顺序表在该块中顺序查找
	i=I[high+1].low;
	while (i<=I[high+1].high && R[i].key!=k)
		i++;
	if (i<=I[high+1].high)
		return i+1;		//查找成功,返回该元素的逻辑序号
	else
		return 0;		//查找失败,返回0
}
void main()
{
	int n=16,b=4,i;
	KeyType k=48;
	SqType R[MaxSize]={9,22,12,14,35,42,44,38,48,60,58,47,78,80,77,82};	//建立主数据表
	IdxType I[MaxSize]={{22,0,3},{44,4,7},{60,8,11},{82,12,15}};		//建立块索引表
	i=BlkSearch(R,n,I,b,k);
	if (i>0)
		printf("关键字为%d的记录的逻辑序号是%d\n",k,i);
	else
		printf("没有找到关键字为%d的记录\n",k);
}

