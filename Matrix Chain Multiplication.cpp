#include<bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#define ll long long
int matrix(int arr[],int n)
{
    int c[n+1][n+1];
    rep(i,1,n+1)
    {
        c[i][i] = 0;
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+len-1;
            c[i][j] = INT_MAX;
            for(int k=i;j<n && k<=j-1;k++)
            {
                int cost = c[i][k]+c[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(cost<c[i][j])
                c[i][j] = cost;                
            }
        }
    }
    return c[1][n-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    cout<<matrix(arr,n);
    return 0;
}