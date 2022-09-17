#define M 6
#define N 7
#include "TSMatrix.cpp"
void main()
{
	TSMatrix t;
	ElemType x;
	ElemType a[M][N]={{0,0,1,0,0,0,0},{0,2,0,0,0,0,0},{3,0,0,0,0,0,0},
	{0,0,0,5,0,0,0},{0,0,0,0,6,0,0},{0,0,0,0,0,7,4}};
	CreatMat(t,a);
	printf("三元组t表示:\n"); DispMat(t);
	printf("执行A[4][1]=8\n");
	Value(t,8,4,1);
	printf("三元组t表示:\n"); DispMat(t);
	printf("求x=A[4][1]\n");
	Assign(t,x,4,1);
	printf("x=%d\n",x);
}

