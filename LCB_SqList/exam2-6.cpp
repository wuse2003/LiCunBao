#include"SqList.cpp"
#include<stdio.h>
#include<iostream>
using namespace std;

void Deletex(SqList &L,ElemType x)
{
    int i, k=0;
    for ( i = 0; i < L.length; i++)
    {
        if (L.data[i]!=x)
        {
            L.data[k]=L.data[i];
            k++;
        }
    }
            L.length=k;

    
}

int main()
{
    SqList L;
    ElemType a[] = {1,2,1,4,1,6,1};
    int n = sizeof(a)/sizeof(a[0]);
    CreateList(L,a,n);
    DispList(L);
    Deletex(L,1);
    DispList(L);

}