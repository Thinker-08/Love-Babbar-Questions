#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution{
public:

    void rearrange(int arr[], int n)
    {
        sort(arr,arr+n,greater<int>());
        int j;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                j=i;
                break;
            }
        }
        int i=0;
        while(i<n)
        {
            if(i%2==0)
            {
                if(arr[i]>=0)
                {
                    i++;
                }
            }
            else
            {
                if(j<n)
                {
                    swap(arr[j],arr[i]);
                    j++;i++;
                }
                else
                    break;
            }
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends