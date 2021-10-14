#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
using namespace std;
void fun2(vector<int>);
void fun(vector<int> );
void fun3(vector<vector<int> >);
int main()
{
    vector<int> a;
    int b;
    char c;
    while(1)
    {
        cout<<"\nEnter The number  :";
        cin>>b;
        a.push_back(b);
        cout<<"\nWant to enter More  :";
        cin>>c;
        if(c=='y'||c=='Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    fun(a);
    getch();
    return 0;
}
void fun(vector<int> a)
{
    int i,sum,d,e,m;
    vector<int> num;
    for(i=0;i<a.size();i++)
    {
        d=a[i];
        vector<int> b;
        for(int x=0;x<a.size();x++)
        {
            m=a[x];
            b.push_back(m);
        }
        b.erase(b.begin()+i);
        for(int j=0;j<b.size();j++)
        {
            e=b[j];
            vector<int> c;
            for(int y=0;y<b.size();y++)
            {
                m=b[y];
                c.push_back(m);
            }
            c.erase(c.begin()+j);
            for(int k=0;k<c.size();k++)
            {
                sum = d+e+c[k];
                if(sum==0)
                {
                    num.push_back(d);
                    num.push_back(e);
                    num.push_back(c[k]);
                    cout<<'\n'<<d<<"   "<<e<<"   "<<c[k];
                }
                else
                {
                    ;
                }
            }
        }
    }
    cout<<endl;
    fun2(num);
}
void fun2(vector<int> a)
{
    int c=0,m;
    vector< vector<int> > b;
    for(int i=0;i<(a.size()/3);i++)
    {
        vector<int> temp;
        for(int j=0;j<3;j++)
        {
            m=a[c];
            temp.push_back(m);
            c++;
        }
        b.push_back(temp);
    }
    fun3(b);
}
void fun3(vector<vector<int> > a)
{
    vector<vector<int> > b;
    int m;
    for(int i=0;i<a.size();i++)
    {
        vector<int> temp(3);
        vector<int> temp1(3);
        for(int x=0;x<3;x++)
        {
            m=a[i][x];
            temp.push_back(m);
        }
        for(int x=0;x<a.size();x++)
        {
            for(int y=0;y<3;y++)
            {
                m=a[x][y];
                temp1=
            }
            b.push_back()
        }
    }
}
