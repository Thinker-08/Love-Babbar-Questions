#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution
{
    public:
    bool check(int p, int n)
    {
        int temp = p, count = 0, f = 5;
        while (f <= temp)
        {
            count += temp/f;
            f = f*5;
        }
        return (count >= n);
    }
        int findNum(int n)
        {
            if (n==1)
            return 5;
            int low = 0;
            int high = 5*n;
         
            // Binary Search.
            while (low <high)
            {
                int mid = (low + high) >> 1;
                if (check(mid, n))
                    high = mid;
                else
                    low = mid+1;
            }
         
            return low;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends