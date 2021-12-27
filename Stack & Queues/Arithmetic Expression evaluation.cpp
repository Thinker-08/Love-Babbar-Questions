#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
int evalRPN(vector<string>& tokens)
{
    stack<int> s;
    for(int i=0;i<tokens.size();i++)
    {
        if(tokens[i]=="+")
        {
            int a,b;
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a+b);
        }
        else if(tokens[i]=="-")
        {
            int a,b;
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b-a);
        }
        else if(tokens[i]=="*")
        {
            int a,b;
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a*b);
        }
        else if(tokens[i]=="/")
        {
            int a,b;
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b/a);
        }
        else
        {
            stringstream ss;
            ss<<tokens[i];
            int temp;
            ss>>temp;
            s.push(temp);
        }
    }
    return s.top();
}
int main()
{
    int n;
    cin>>n;
    vector<string> tokens(n);
    rep(i,0,n)
        cin>>tokens[i];
    int ans=evalRPN(tokens);
    cout<<ans;
}