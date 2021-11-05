#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1+1,vector<vector<int>> (n2+1,vector<int> (n3+1)));
    for(int i=0;i<n1+1;i++)
    {
        for(int j=0;j<n2+1;j++)
        {
            for(int k=0;k<n3+1;k++)
            {
                if(i==0 || j==0 || k==0)
                    dp[i][j][k]=0;
                else
                {
                    if(A[i-1]==B[j-1] && A[i-1]==C[k-1])
                        dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    else
                    {
                        dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                    }
                }
            }
        }
    }
    return dp[n1][n2][n3];
}