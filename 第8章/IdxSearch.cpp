#include <stdio.h>
#include <string.h>
#define MaxSize 100
typedef int KeyType;
typedef struct
{
	int no;				//学号,作为关键字
	char name[10];		//姓名
	int score;			//分数
} SqType;
typedef struct
{
	KeyType key;
	int pos;
} IdxType;
int BinSearch(IdxType I[],int n,int k)	//拆半查找算法
{	int low=0,high=n-1,mid;
	while (low<=high)				//当前区间存在元素时循环
	{	mid=(low+high)/2;			//求查找区间的中间位置
		if (I[mid].key==k)			//查找成功返回其逻辑序号mid+1
			return mid+1;			//找到后返回其逻辑序号mid+1
		if (I[mid].key>k)			//继续在I[low..mid-1]中查找
			high=mid-1;
		else						//I[mid].key<k
			low=mid+1;				//继续在R[mid+1..high]中查找
	}
	return 0;						//若当前查找区间没有元素时返回0
}
int IdxSearch(SqType R[],IdxType I[],int n,KeyType k)	//索引查找
{
	int i;
	i=BinSearch(I,n,k);
	if (i>0)		//在索引表中找到了,返回其逻辑序号
		return I[i-1].pos+1;
	else
		return 0;	//在索引表中没找到,返回0
}
void main()
{
	int n=5,i;
	KeyType k=201204;
	SqType R[MaxSize]={{201201,"王实",85},{201205,"李斌",82},{201206,"刘英",92},{201202,"张山",78},{201204,"陈功",90}};
	IdxType I[MaxSize]={{201201,0},{201202,3},{201204,4},{201205,1},{201206,2}};
	i=IdxSearch(R,I,n,k);
	if (i>0)
		printf("关键字为%d的记录的逻辑序号是%d\n",k,i);
	else
		printf("没有找到关键字为%d的记录\n",k);
}

