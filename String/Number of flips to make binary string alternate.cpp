// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    int count1=0,count2=0;
    for(int i=0;i<S.length();i++)
    {
        if(i%2==0)
        {
            if(S[i]=='0')
                continue;
            else
                count1++;
        }
        else
        {
            if(S[i]=='1')
                continue;
            else
                count1++;
        }
    }
    for(int i=0;i<S.length();i++)
    {
        if(i%2==0)
        {
            if(S[i]=='1')
                continue;
            else
                count2++;
        }
        else
        {
            if(S[i]=='0')
                continue;
            else
                count2++;
        }
    }
    return min(count1,count2);
}