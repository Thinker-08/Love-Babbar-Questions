#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            if(matrix[i][j]==target)
                return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int> (m));
    rep(i,0,n)
    {
        rep(j,0,m)
            cin>>v[i][j];
    }
    int target;
    cin>>target;
    if(searchMatrix(v,target))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}