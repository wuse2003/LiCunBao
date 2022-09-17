#include"SqList.cpp"
#include<stdio.h>
#include<iostream>
using namespace std;

void Commelem (SqList A,SqList B,SqList &C)
{
    int i=0,j=0,k=0;
    while(i<A.length && j<B.length)
    {
        if (A.data[i]<B.data[j])
        {
            i++;
        }
        else if(A.data[i]>B.data[j])
        {
            
            j++;
        }
        else //A.data[i]=B.data[j]
        {
            C.data[k] = A.data[i];
            j++;i++;k++;
        } 
    }
     C.length=k;
   
}

int main()
{
    SqList L1,L2,L3;

    ElemType a[] = {1,2,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    CreateList(L1,a,n);

    ElemType b[] = {2,4,6,8,10};
    int m = sizeof(b)/sizeof(b[0]);
    CreateList(L2,b,m);

    DispList(L1);
    DispList(L2);
    Commelem(L1,L2,L3);
    DispList(L3);

}