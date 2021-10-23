#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;

int tree[N],ar[N];

void fun(int node,int l,int r)
{
    if(l==r)
    {
        tree[node] = ar[l];
    }
    else
    {
        int mid = (l+r)/2;
        fun(2*node,l,mid);
        fun(2*node+1,mid+1,r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ar[i] = a;
    }
    fun(1,0,n-1);
    for(int i=1;i<16;i++)
    {
        cout<<tree[i]<<endl;
    }
    return 0;
}