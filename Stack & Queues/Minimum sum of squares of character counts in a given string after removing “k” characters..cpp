// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        vector<int> v;
        sort(s.begin(),s.end());
        int j=1,l=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                j++;
            }
            else{
                v.push_back(j);
                j=1;
            }
        }
        v.push_back(j);
        sort(v.begin(),v.end());
        j=v.size()-1;
        while(k>0)
        {
            if(v[j]==v[j-1])
            {
                j--;
                continue;
            }
            v[j]-=1;
            k-=(v.size()-j);
        }
        for(int i=0;i<j;i++)
        {
            l+=(v[i]*v[i]);
        }
        if(k==0)
        {
            l+=((v.size()-j)*(v[j]*v[j]));
        }
        else{
            l=l+(-1*k)*((v[j]+1)*(v[j]+1));
            l=l+(v.size()-j+k)*(v[j]*v[j]);
        }
        return l;
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