#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
void test(vector<char>,int,int,int,int);
void test1(vector<char>,int,int,int,int);
using namespace std;
void main()
{
    int testcase,i=1;
    cin>>testcase;
    while(i<=testcase)
    {
        int n,k,j=0,s=0;
        cin>>n,k;
        vector<char> S(n);
        while(j!=(n-1))
        {
            cin>>S[i];
        }
        for(j=0;(j+1)<(n-j);j++)
        {
            if(S[j+1]!=S[n-j])
            {
                s++;
            }
        }
        if(s>k)
        {
            test(S,s,k,n,i);
        }
        else
        {
            if(s<k)
            {
                    test1(S,s,k,n,i)
            }
            else
            {
                cout<<"Case #i: 0";
            }
        }
    }
}
void test(vector<char> S,int s,int k,int n,int i)
{
    int a=0;
    for(int j=0;(j+1)<(n-j);j++)
    {
        if((s>k)&&(S[j]!=S[n-j]))
        {
            S[j]=S[n-j];
            a++;
        }
    }
    cout<<"Case #"<<i<<":"<<" "<<a;
}
void test1(vector<char> S,int s,int k,int n,int i)
{
    int a=0;
    for(int j=0;(j+1)<(n-j);j++)
    {
        if((s<k)&&(S[j]==S[n-j]))
        {
            S[j]=S[n-j]+1;
            a++;
        }
    }
    cout<<"Case #"<<i<<":"<<" "<<a;
}

