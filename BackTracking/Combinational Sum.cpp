// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    vector<vector<int>> ans;
    void driver(vector<int> &A,int sum,int B,vector<int> &temp,int idx)
    {
        if(sum==B)
        {
            ans.push_back(temp);
            return;
        }
        if(sum<B)
        {
            for(int i=idx;i<A.size();i++)
            {
                temp.push_back(A[i]);
                driver(A,sum+A[i],B,temp,i);
                temp.pop_back();
            }   
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B)
    {
        vector<int> temp,a;
        map<int,int> mp;
        for(int i=0;i<A.size();i++)
        {
            mp[A[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            a.push_back((*it).first);
        }
        driver(a,0,B,temp,0);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends