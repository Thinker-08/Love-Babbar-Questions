#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> fun(vector<int> [],vector<int> [],int,int,int);
int main()
{
    vector<int> A,B,C;
    int b;
    cout<<"Enter The number of elements : ";
    cin>>b;
    cout<<"Enter The Elements of A\n";
    for(int i=0;i<b;i++)
    {
        cout<<"Enter The Element  : ";
        cin>>A[i];
    }
    cout<<"\nEnter The Elements of B\n";
    for(int i=0;i<b;i++)
    {
        cout<<"Enter The Element  : ";
        cin>>B[i];
    }
    C=fun(A,B,b,0,0);
    cout<<"\n The Result is : ";
    for(int i = 0; i<C.size(); i++)
    {
        cout<<C[i]<<" ";
    }
    getch();
    return 0;
}
vector<int> fun(vector<int> A,vector<int> B,int n,int a,int b)
{
    vector<int> R;
    if(n==1)
    {
        R[0]=A[a]*B[b];
        return R;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                R[i+j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                R[i+j]=R[i+j]+fun(A,B,1,i,j);
            }
        }
        return R;
    }
}
