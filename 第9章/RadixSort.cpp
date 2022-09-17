#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 100
#define MAXD 10				//关键字最多位数
#define MAXR 20				//最大的基数
typedef int KeyType;
typedef char ElemType;
typedef struct
{	KeyType key;			//存放关键字,KeyType为关键字类型
	ElemType data;			//其他数据,ElemType为其他数据的类型
} SqType;
typedef struct rnode
{	char key[MAXD];			//存放关键字
	ElemType data;			//存放其他数据
	struct rnode *next;
} RadixNode;				//单链表结点类型
void CreateSLink(RadixNode *&h,char *A[],int n)	//建立不带头结点的单链表h
{
	int i;
	RadixNode *p,*tc;
	h=(RadixNode *)malloc(sizeof(RadixNode));
	strcpy(h->key,A[0]);
	tc=h;
	for (i=1;i<n;i++)
	{
		p=(RadixNode *)malloc(sizeof(RadixNode));
		strcpy(p->key,A[i]);
		tc->next=p;
		tc=p;
	}
	tc->next=NULL;
}
void DestroySLink(RadixNode *&h)	//销毁不带头结点的单链表h
{
	RadixNode *pre=h,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
}
void DispLink(RadixNode *h)			//输出不带头结点的单链表h
{
	RadixNode *p=h;
	while (p!=NULL)
	{
		printf("%s ",p->key);
		p=p->next;
	}
	printf("\n");
}
void RadixSort1(RadixNode *&h,int d,int r)	//最高位优先基数排序算法
//实现基数排序:h为待排序数列单链表指针,r为基数,d为关键字位数
{	RadixNode *head[MAXR];					//建立链队队头数组
	RadixNode *tail[MAXR];					//建立链队队尾数组
	RadixNode *p,*tc;
	int i,j,k;
	for (i=d-1;i>=0;i--)					//从高位到低位循环
	{	for (j=0;j<r;j++) 					//初始化各链队首、尾指针
			head[j]=tail[j]=NULL;
		p=h;
		while (p!=NULL)						//分配：对于原链表中每个结点循环
		{
			k=p->key[i]-'0';				//找第k个链队
			if (head[k]==NULL)				//第k个链队空时，队头队尾均指向p结点
				head[k]=tail[k]=p;
			else
			{	tail[k]->next=p;			//第k个链队非空时，p结点入队
				tail[k]=p;
			}
			p=p->next;						//取下一个待排序的元素
		}
		h=NULL;								//重新用h来收集所有结点
		for (j=0;j<r;j++)					//收集：对于每一个链队循环
			if (head[j]!=NULL)				//若第j个链队是第一个非空链队
			{	if (h==NULL)
				{	h=head[j];
					tc=tail[j];
				}
				else						//若第j个链队是其他非空链队
				{	tc->next=head[j];
					tc=tail[j];
				}
			}
		tc->next=NULL;						//尾结点的next域置NULL
		printf("i=%d排序结果: ",i); DispLink(h);

	}
}

void main()
{
	char *A[]={"75","87","68","92","88","61","77","96","80","72"};
	int n=10;
	RadixNode *h;
	CreateSLink(h,A,n);
	printf("初始序列:    "); DispLink(h);
	RadixSort1(h,2,10);
	printf("排序结果:    "); DispLink(h);
	DestroySLink(h);
}
