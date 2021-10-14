#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        string test="";
        for(int i=0;i<n;i++)
        {
            test.append("0");
        }
        for(int i=0;i<n;i++)
        {
        
            if(v[i][i]=='0')
            {
                test[i] = '1';
            }
            else
            {
                continue;
            }

        }
        cout<<test<<endl;
    }
    return 0;
}