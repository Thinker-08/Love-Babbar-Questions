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
        int A[n]; 
        int pos = 0;
        int neg = 0;
        int no = 0;
        int po = 0;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]>1)
            {
                pos++;
            }
            if(A[i]<-1)
            {
                neg++;
            }
            if(A[i]==-1)
            {
                no++;
            }
            if(A[i]==1)
            {
                po++;
            }
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        if(n==2)
        {
            if(A[0]*A[1]==A[0] || A[0]*A[1]==A[1]){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
            continue;
        }
        if(pos==0 && neg==0)
        {
            if(no>1){
                if(po==0){
                    cout<<0<<endl;
                }
                else{
                    cout<<1<<endl;
                }
            }
            else{
                cout<<1<<endl;
            }
        }
        else if(pos==0 && neg==1)
        {
            if(no>0){
                cout<<0<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}