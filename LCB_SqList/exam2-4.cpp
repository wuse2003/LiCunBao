#include"SqList.cpp"
#include<stdio.h>
#include<iostream>
using namespace std;

int Deletek(SqList &L, int i,int k)
{
    int j;
    if(i<1 || k<1 || i + k - 1>L.length )
    {
        return 0;
    }

    for ( j = i-1+k ; j < L.length ; j++)
    {
        L.data[j - k] = L.data[j];  
    }
     L.length-=k;
    return 1;
}
int main()
{
    SqList L;
    ElemType a[] = {1,3,1,5,4,2};
    int n = sizeof(a)/sizeof(a[0]);
    CreateList(L,a,n);
    Deletek(L,2,3);
    DispList(L);
}