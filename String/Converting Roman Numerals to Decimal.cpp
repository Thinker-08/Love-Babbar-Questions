// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int sum=0;
        if(str.length()==1)
            return mp[str[0]];
        else
        {
            for(int i=0;i<str.length()-1;i++)
            {
                if(mp[str[i]]>=mp[str[i+1]])
                    sum=sum+mp[str[i]];
                else
                    {
                        sum=sum+mp[str[i+1]]-mp[str[i]];
                        i++;
                    }
            }
            if(mp[str[str.length()-2]]>=mp[str[str.length()-1]])
                sum=sum+mp[str[str.length()-1]];
            return sum;   
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends