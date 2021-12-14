// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        map<char,int> mp;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
        }
        string ans;
        int distinct=mp.size();
        map<char,int> hash;
        int i=0,j=0,mini=INT_MAX;
        while(i<str.length() and j<str.length())
        {
            hash[str[j]]++;
            if(hash.size()<distinct)
                j++;
            else
            {
                while(hash.size()==distinct and i<=j)
                {
                    if(hash[str[i]]-1==0)
                        hash.erase(str[i]);
                    else
                        hash[str[i]]--;
                    int x=hash.size();
                    if(mini>j-i+1)
                    {
                        ans="";
                        mini=j-i+1;
                        for(int k=i;k<=j;k++)
                            ans=ans+str[k];
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends