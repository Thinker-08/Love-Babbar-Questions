#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    stack<int> st;
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && v[st.top()]<v[i])
        {
            v[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        v[st.top()] = -1;
        st.pop();
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}