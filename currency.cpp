#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int fun(int);
int main() {
    int a,b;
    int c;
    cin>>a;
    vector<int> arr;
    for(int i=0;i<a;i++)
    {
        cin>>b;
        arr.push_back(b);
    }
    for(int i=0;i<a;i++)
    {
        cout<<arr[i];
        c=arr[i];
        fun(c);
        cout<<endl;
    }
    return 0;
}
int fun(int a)
{
    int max;
    if(a==1)
    {
        return 0;
    }
    else
    {
        for(int i=1;i<a;i++)
        {
            if((a%i)==0)
            {
                max=i;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<'\t'<<max;
    fun(max);
}
