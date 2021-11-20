// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long> ans;
    queue<pair<long long,long long>> q;
    for(long long i=0;i<N;i++)
    {
        if(A[i]<0)
            q.push(make_pair(A[i],i));
    }
    queue<long long> values_queue;
    for(long long i=0;i<K;i++)
    {
        values_queue.push(A[i]);
    }
    if(q.front().second==0)
    {
        ans.push_back(q.front().first);
        q.pop();
    }
    else
    {
        if(q.front().second>0 && q.front().second<K)
        {
            ans.push_back(q.front().first);
        }
        else
        {
            ans.push_back(0);
        }
    }
    values_queue.pop();
    for(long long i=K;i<N;i++)
    {
        values_queue.push(A[i]);
        if(q.front().second==i-K+1)
        {
            ans.push_back(q.front().first);
            q.pop();
        }
        else
        {
            if(q.front().second>i-K+1 && q.front().second<i+1)
            {
                ans.push_back(q.front().first);
            }
            else
            {
                ans.push_back(0);
            }
        }
        values_queue.pop();
    }
    return ans;
 }