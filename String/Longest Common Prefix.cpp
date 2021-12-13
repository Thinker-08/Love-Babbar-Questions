#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
#define MOD 1e9+7
bool cmp(string a,string b)
{
    return a.length()<b.length();
}
string longestCommonPrefix(vector<string>& strs)
{
    string ans="";
    sort(strs.begin(),strs.end(),cmp);
    for(int i=0;i<strs[0].length();i++)
    {
        int flag=0;
        for(int j=0;j<strs.size()-1;j++)
        {
            if(strs[j][i]==strs[j+1][i])
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            return ans;
        }
        ans=ans+strs[0][i];
    }
    return ans;
}
int main()
{
    fast;
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,0,n)
    {
        cin>>s[i];
    }
    string ans = longestCommonPrefix(s);
    cout<<ans;
    return 0;
}