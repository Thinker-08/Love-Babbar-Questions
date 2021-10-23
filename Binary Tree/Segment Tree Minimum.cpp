#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
int tree[4*N],ar[N];

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
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
int minElement(int node,int st,int en,int l,int r)
{
    if(st>r || en<l)
    {
        return INT_MAX;
    }
    if(l<=st && en<=r)
    {
        return tree[node];
    }
    
    int mid = (st+en)/2;
    int q1 = minElement(2*node,st,mid,l,r);
    int q2 = minElement(2*node+1,mid+1,en,l,r);
    return min(q1,q2);  
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ar[i] = a;
    }
    fun(1,0,n-1);
    int l,r;
    cin>>l>>r;
    int ans = minElement(1,0,n-1,l,r);
    cout<<ans;
    return 0;
}