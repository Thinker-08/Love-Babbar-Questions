// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n)
    {
        stack<long long> s;
        long long ans=0;
        for(long long i=0;i<n;i++)
        {
            while(!s.empty() and arr[s.top()]<arr[i])
            {
                long long pop_h=arr[s.top()];
                s.pop();
                if(s.empty())
                    break;
                long long distance=i-s.top()-1;
                long long min_h=min(arr[s.top()],arr[i])-pop_h;
                ans=ans+distance*min_h;
            }
            s.push(i);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends