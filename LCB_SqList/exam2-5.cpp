#include"SqList.cpp"
#include<stdio.h>
#include<iostream>
using namespace std;

void Move(SqList &L)
{
    int i= 0,j=L.length-1;//移动到最后一位就是要减1；
    while(i<j)
    {
        while(L.data[i]%2==1) i++;
        while(L.data[j]%2==0) j--;
        
        if(i<j)
        {
            ElemType temp = L.data[i];
            L.data[i] = L.data[j];
            L.data[j] =temp;
        }
    }
}
int main()
{
    SqList L;
    ElemType a[] = {1,2,3,4,5,6,7};
    int n = sizeof(a)/sizeof(a[0]);
    CreateList(L,a,n);
    DispList(L);
    Move(L);
    DispList(L);

}