#include"SqList.cpp"
#include<stdio.h>
#include<iostream>
using namespace std;

void swap(ElemType &x,ElemType &y)
{
    ElemType temp = x;
    x = y;
    y = temp;
}

void swapmaxmin(SqList &L)
{
    ElemType i,min,max;
    min = max = 0;
    for ( i = 0; i < L.length; i++)
    {
        if(L.data[i] > L.data[max])
            max = i;
        else //if(L.data[i] < L.data[min])
            min = i;
    }
    swap(L.data[max],L.data[min]);

}
int main()
{
    SqList L;
    ElemType a[] = {1,3,6,5};
    int n = sizeof(a)/sizeof(a[0]);
    CreateList(L,a,n);
    DispList(L);
    swapmaxmin(L);
    DispList(L);
}