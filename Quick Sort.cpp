#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;
void quick_sort(vector<int>&,int,int);
int pivot(vector<int>&,int,int);
void display(vector<int>&);
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,(n-1));
    display(a);
    return 0;
}
void display(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<'\t';
    }
    cout<<'\n';
}
void quick_sort(vector<int> &a,int l,int r)
{
    if(l<r)
    {
        int m=pivot(a,l,r);
        quick_sort(a,l,m-1);
        quick_sort(a,m+1,r);
    }
}
int pivot(vector<int> &a,int l,int r)
{
    int pi=a[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j]<=pi)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return (i+1);
}
