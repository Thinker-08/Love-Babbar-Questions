// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans;
        sort(candies,candies+N);
        int i=0,j=N-1;
        int min_cost=0,max_cost=0;
        while(i<=j)
        {
            min_cost=min_cost+candies[i];
            i++;
            j=j-K;
        }
        ans.push_back(min_cost);
        sort(candies,candies+N,greater<int>());
        i=0;j=N-1;
        while(i<=j)
        {
            max_cost=max_cost+candies[i];
            i++;
            j=j-K;
        }
        ans.push_back(max_cost);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends