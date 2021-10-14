#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
#define bb ios_base::sync_with_stdio(false)
#define bb1 cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
vs ans;
void brackets(string &s,int open,int close)
{
    if(open>0)
    {
        s.push_back('(');
        brackets(s,open-1,close);
        s.pop_back();
    }
    if(close>0)
    {
        if(open<close)
        {
            s.push_back(')');
            brackets(s,open,close-1);
            s.pop_back();
        }
    }
    if(open==0 && close==0)
    {
        ans.push_back(s);
    }
}
int main()
{
    bb;bb1;
    int n;
    cin>>n;
    string s;
    brackets(s,n,n);
    rep(i,0,ans.size())
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}