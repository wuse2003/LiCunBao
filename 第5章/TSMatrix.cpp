#include <stdio.h>
#define MaxSize  100		//矩阵中非零元素的最多个数
typedef int ElemType;
typedef struct 
{	int r;					//行号
	int c;					//列号
	ElemType d;				//元素值为ElemType类型
} TupNode;					//三元组定义
typedef struct 
{	int rows;				//行数
	int cols;				//列数
	int nums;				//非零元素个数
	TupNode data[MaxSize];
} TSMatrix;					//三元组顺序表定义

void CreatMat(TSMatrix &t,ElemType A[M][N])
{	int i,j;
	t.rows=M;t.cols=N;t.nums=0;
	for (i=0;i<M;i++)
	{	for (j=0;j<N;j++) 
			if (A[i][j]!=0) 	//只存储非零元素
			{	t.data[t.nums].r=i;t.data[t.nums].c=j;
				t.data[t.nums].d=A[i][j];t.nums++;
			}
	}
}

int Value(TSMatrix &t,ElemType x,int i,int j)
{	int k=0,k1;
	if (i>=t.rows || j>=t.cols)
		return 0;					//参数错误时返回0
	while (k<t.nums && i>t.data[k].r) k++;					//查找行
	while (k<t.nums && i==t.data[k].r && j>t.data[k].c) k++;//查找列
	if (t.data[k].r==i && t.data[k].c==j)	//存在这样的元素
		t.data[k].d=x;
	else									//不存在这样的元素时插入一个元素
	{	for (k1=t.nums-1;k1>=k;k1--)
		{	t.data[k1+1].r=t.data[k1].r;
			t.data[k1+1].c=t.data[k1].c;
			t.data[k1+1].d=t.data[k1].d;
		}
		t.data[k].r=i;t.data[k].c=j;t.data[k].d=x;
		t.nums++;
	}
	return 1;						//成功时返回1
}

int Assign(TSMatrix t,ElemType &x,int i,int j)
{	int k=0;
	if (i>=t.rows || j>=t.cols)
		return 0;			//参数错误时返回0
	while (k<t.nums && i>t.data[k].r) k++;					//查找行
	while (k<t.nums && i==t.data[k].r && j>t.data[k].c) k++;//查找列
	if (t.data[k].r==i && t.data[k].c==j)
		x=t.data[k].d;
	else
		x=0;				//在三元组中没有找到表示是零元素
	return 1;				//成功时返回1
}

void DispMat(TSMatrix t)
{	int i;
	if (t.nums<=0)			//没有非零元素时返回
		return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("\t------------------\n");
	for (i=0;i<t.nums;i++)
		printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
}
