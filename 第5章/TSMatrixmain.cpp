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
	printf("��Ԫ��t��ʾ:\n"); DispMat(t);
	printf("ִ��A[4][1]=8\n");
	Value(t,8,4,1);
	printf("��Ԫ��t��ʾ:\n"); DispMat(t);
	printf("��x=A[4][1]\n");
	Assign(t,x,4,1);
	printf("x=%d\n",x);
}

