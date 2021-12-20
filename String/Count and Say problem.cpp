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
string countAndSay(int n)
{
    if (n == 1)      return "1";
if (n == 2)      return "11";
string str = "11";
for (int i = 3; i<=n; i++)
{
    str += '$';
    int len = str.length();
    int cnt = 1;
    string  tmp = "";
    for (int j = 1; j < len; j++)
    {
        if (str[j] != str[j-1])
        {
            tmp += cnt + '0';
            tmp += str[j-1];
            cnt = 1;
        }
        else cnt++;
    }

    str = tmp;
}

return str;    
}
int main()
{
    fast;
    int n;
    cin>>n;
    string ans=countAndSay(n);
    cout<<ans;
    return 0;
}