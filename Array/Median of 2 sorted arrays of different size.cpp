// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        vector<int> v;
        int n1=array1.size(), n2=array2.size();
        int i=0, j=0, k=n1-1;
        while(i<=k && j<n2){
            if(array1[i]>array2[j])
                swap(array1[k--], array2[j++]);
            else
                i++;
        }
        sort(array1.begin(),array1.end());
        sort(array2.begin(),array2.end());
        for(auto i:array1) v.push_back(i);
        for(auto i:array2) v.push_back(i);
        int x=n1+n2;
        if(x%2!=0) return (double) v[x/2];
        else return (double)(v[x/2]+v[x/2-1])/2;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends