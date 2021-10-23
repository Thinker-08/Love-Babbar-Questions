#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N=1e5;
string s;
int main()
{
    cin>>s;
    int e=1,a=0,ab=0,abc=0;
    rep(i,0,s.size())
    {
        if(s[i]=='a')
            a = a+e;
        else if(s[i]=='b')
            ab = ab + a;
        else if(s[i]=='c')
            abc = abc + ab;
        else if(s[i] == '?')
        {
            abc = 3*abc+ab;
            ab = 3*ab + a;
            a = 3*a + e;
        }
    }
    cout<<abc;
    return 0;
}