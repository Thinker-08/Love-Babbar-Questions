// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long ans=0;
    void merge(long long arr[],int l,int mid,int r,int N)
    {
        vector<long long> temp;
        int i=l,j=mid+1;
        while(i<=mid and j<=r)
        {
            if(arr[i]>arr[j])
            {
                ans=ans+(mid-i+1);
                temp.push_back(arr[j]);
                j++;
            }
            else
            {
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=r)
        {
            temp.push_back(arr[j]);
            j++;
        }
        for(int i=0,j=l;i<temp.size(),j<=r;i++,j++)
        {
            arr[j]=temp[i];
        }
    }
    void driver(long long arr[],int l,int r,int siz)
    {
        if(l>=r)
            return;
        int mid=(l+r)/2;
        driver(arr,l,mid,siz);
        driver(arr,mid+1,r,siz);
        merge(arr,l,mid,r,siz);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        driver(arr,0,N-1,N);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends