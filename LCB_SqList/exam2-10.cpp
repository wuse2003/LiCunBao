#include"SqList.cpp"
#include<stdio.h>
#include<iostream>
using namespace std;
 
 #define INF 32767

 int Topk1(SqList A,SqList B,int k,ElemType &e)
 {
    int i=0,j=0;

    if (k<1||k>A.length+B.length)
    {
        return 0;
    }
    
    while (i<A.length && j<B.length)
    {
        k--;
        if (A.data[i] < B.data[j])
        {
            //k--;
            if (k==0)
            {
                e = A.data[i];
                return 1;
            }
            i++;            
        }
        else
        {
           // k--;
            if (k==0)
            {
                e = B.data[j];
                return 1;
            }
            j++;  
        }
    }
    if(i<A.length)
        e=A.data[i+k-1] ;//现在的k已经变小了 只剩下 k-i；
    else if(j<B.length)
        e=B.data[j+k-1];  
    return 1;
 }
 
 int Topk2(SqList A,SqList B,int k,ElemType &e)
 {
    int i=0,j=0;
    if ( k<1||k>A.length+B.length)
    {
        return 0;
    }
    for( ; ; )//开启编译优化选项的话没啥区别，-O0优化的话while多一次条件判断，for无条件跳转
    {
        k--;
        int x =(i<A.length?A.data[i]:INF);
        int y =(j<B.length?B.data[j]:INF);

        if (x<y)
        {
            if(k==0)
                {
                    e = A.data[i];
                    return 1;
                }
                i++;
        }
        else
        {
            if (k==0)
            {
                e = B.data[j];
                return 1;
            }
            j++;
        }
    }
}

 int main()
 {
    SqList L1,L2;
    ElemType a[] = {1,3,5,7,9};
    ElemType b[] = {2,4,6,8,10};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    CreateList(L1,a,n);
    CreateList(L2,b,m);

    DispList(L1);
    DispList(L2);

    ElemType e;
    int k;
    for ( k = 0; k <=m+n; k++)
    {
        if(Topk2(L1,L2,k,e))
            cout << e;
    }
   
     return 0;
 }