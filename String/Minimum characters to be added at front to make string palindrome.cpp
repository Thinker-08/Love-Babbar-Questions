//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string A){
        string temp=A;
    reverse(A.begin(),A.end());
    temp+='$'+A;
    vector<int> v(temp.length());
    int i=0,j=1;
    while(j<temp.length())
    {
        if(temp[i]==temp[j])
        {
            v[j]=i+1;
            i++;
            j++;
        }
        else if(temp[j]=='$')
        {
            i=0,j++;
        }
        else if(i!=0)
        {
            i=v[i-1];
        }
        else
        {
            v[j]=0;
            j++;
        }
    }
    return A.length()-v[temp.length()-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends