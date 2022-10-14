#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
#define int long long
int find(vector<vector<int>>&matrix)
{
    vector<vector<int>> maxi(matrix.size(),vector<int>(matrix[0].size(),INT_MIN));
    for(int i=matrix.size()-1;i>=0;i--)
    {
        for(int j=matrix[i].size()-1;j>=0;j--)
        {
            if(i+1<matrix.size())
            {
                if(j+1<matrix[0].size())
                    maxi[i][j]=max({maxi[i+1][j],maxi[i][j+1],maxi[i+1][j+1]});
                else
                    maxi[i][j]=max({maxi[i+1][j],matrix[i][j]});
            }
            else
            {
                if(j+1<matrix[0].size())
                    maxi[i][j]=max({matrix[i][j],maxi[i][j+1]});
                else
                    maxi[i][j]=matrix[i][j];
            }
        }
    }
    newline;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
            cout<<maxi[i][j]<<" ";
        newline;
    }
    int ans=INT_MIN;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            if(i+1<matrix.size() and j+1<matrix[0].size() and ans<maxi[i+1][j+1]-matrix[i][j])
            {
                ans=maxi[i+1][j+1]-matrix[i][j];
                cout<<maxi[i+1][j+1]<<" "<<matrix[i][j]<<endl;
            }
        }
    }
    return ans;
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    rep(i,0,n)
    {
        rep(j,0,n)
            cin>>matrix[i][j];
    }
    int ans = find(matrix);
    cout<<ans;
    newline;
}
