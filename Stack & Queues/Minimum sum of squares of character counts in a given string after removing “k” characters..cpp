// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        vector<int> v;
        for(auto it=mp.begin();it!=mp.end();it++)
            v.push_back((*it).second);
        priority_queue<int> pq;
        for(int i=0;i<v.size();i++)
        {
            pq.push(v[i]);
        }
        while(k!=0)
        {
            if(pq.top()>=1)
            {
                int temp=pq.top();
                pq.pop();
                temp--;
                k--;
                pq.push(temp);
            }
        }
        int count=0;
        while(!pq.empty())
        {
            count=count+pq.top()*pq.top();
            pq.pop();
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends