#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
vector<vector<int>> path;
void driver(vector<vector<int>> &matrix,int i,int j,vector<int>& temp)
{
    if(i>=matrix.size() || j>=matrix[0].size())
        return;
    if(i==matrix.size()-1 and j==matrix[0].size()-1)
    {
        temp.push_back(matrix[i][j]);
        path.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.push_back(matrix[i][j]);
    driver(matrix,i+1,j,temp);
    driver(matrix,i,j+1,temp);
    temp.pop_back();
}
vector<vector<int>> all_paths(vector<vector<int>> &matrix)
{
    vector<int> temp;
    driver(matrix,0,0,temp);
    return path;
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    rep(i,0,n)
    {
        rep(j,0,m)
            cin>>matrix[i][j];
    }
    vector<vector<int>> ans=all_paths(matrix);
    rep(i,0,ans.size())
    {
        rep(j,0,ans[i].size())
            cout<<ans[i][j]<<" ";
        newline;
    }
    return 0;
}