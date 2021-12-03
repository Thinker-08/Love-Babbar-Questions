#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
void merge(vector<int> &v,int l,int mid,int r)
{
    int i=l,j=mid+1;
    vector<int> temp;
    while(i<=mid and j<=r)
    {
        if(v[i]<v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j<=r)
    {
        temp.push_back(v[j]);
        j++;
    }
    rep(i,0,temp.size())
    {
        v[l]=temp[i];
        l++;
    }
}
void merge_sort(vector<int> &v,int i,int j)
{
    if(i>=j)
        return;
    int mid=(i+j)/2;
    merge_sort(v,i,mid);
    merge_sort(v,mid+1,j);
    merge(v,i,mid,j);
}
int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    merge_sort(v,0,v.size()-1);
    rep(i,0,n)
        cout<<v[i]<<" ";
    return 0;
}