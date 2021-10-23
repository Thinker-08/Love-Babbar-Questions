#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int binary_search(vector<int>,int,int,int);
int main()
{
    int m,n;
    cin>>m;
    vector<int>a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    cin>>n;
    vector<int>b(n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int z;
    for(int i=0;i<n;i++)
    {
        z=binary_search(a,b[i],0,(n-1));
        cout<<z<<'\t';
    }
    return 0;
}
int binary_search(vector<int> a,int x,int l,int r)
{
    int m = (l+r)/2;
    if(a[m]==x)
    {
        return m;
    }
    else
    {
        if(a[m]>x)
        {
            if(m<=r&&m>=l)
            {
                return binary_search(a,x,l,m-1);
            }
            else
                return -1;
        }
        else
        {
            if(m<=r&&m>=l)
            {
                return binary_search(a,x,m+1,r);
            }
            else
            {
                return -1;
            }
        }
    }
}
