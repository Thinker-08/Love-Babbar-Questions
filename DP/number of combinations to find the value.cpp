#include<bits/stdc++.h>
#define ll long long;
using namespace std;
int main()
{
    int amount,n;
    vector<int> coins;
    cin>>amount>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        coins.push_back(temp);
    }
    int dp[n+1][amount+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(j==0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if(i==0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(coins[i-1]>j)
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                    }
                }
            }
        }
    }
    cout<<dp[n][amount]<<endl;
    return 0;
}