// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

int countRev (string s)
{
    int open=0,close=0,ans=0;
    if(s.length()%2!=0)
        return -1;
    for(int i=0;i<s.length();i++)
    {
        if(open==0 and s[i]=='}')
        {
            open++;
            ans++;
        }
        else
        {
            if(s[i]=='{')
                open++;
            else
            {
                open--;
            }
        }
    }
    if(open%2==0)
        return ans+open/2;
    else
        return -1;
}