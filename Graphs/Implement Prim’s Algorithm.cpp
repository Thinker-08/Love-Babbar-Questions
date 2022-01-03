#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
ll min(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}
const int INF=1e9+7;
int mini(vector<int>& distance,vector<bool> &MST)
{
    int ans,ok=INT_MAX;
    for(int i=0;i<distance.size();i++)
    {
        if(distance[i]<ok and MST[i]==false)
        {
            ans=i;
            ok=distance[i];
        }
    }
    return ans;
}
void print_tree(vector<vector<int>> &matrix,vector<int> &parent)
{
    cout<<"Parent Child Distance"<<endl;
    for(int i=1;i<matrix.size();i++)
    {
        cout<<parent[i]<<"\t "<<i<<"\t "<<matrix[parent[i]][i]<<endl;
    }
}
void prims_tree(vector<vector<int>> &matrix)
{
    vector<int> distance(matrix.size()),parent(matrix.size());
    vector<bool> MST(matrix.size());
    rep(i,0,matrix.size())
    {
        distance[i]=INT_MAX;
        MST[i]=false;
    }
    distance[0]=0;
    parent[0]=-1;
    for(int i=0;i<matrix.size()-1;i++)
    {
        int x = mini(distance,MST);
        MST[x]=true;
        for(int j=0;j<matrix.size();j++)
        {
            if(matrix[x][j]!=0 and MST[j]==false and matrix[x][j]<distance[j])
            {
                distance[j]=matrix[i][j];
                parent[j]=x;
            }
        }
    }
    print_tree(matrix,parent);
}
int32_t main()
{
    fast;
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    rep(i,0,n)
        rep(j,0,n)
            cin>>matrix[i][j];
    prims_tree(matrix);
    return 0;
}