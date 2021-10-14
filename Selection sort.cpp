#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    char b='y';
    int i=0,d,temp;
    int mi;
    while(b=='y'||b=='Y')
    {
        cout<<"Enter The Element : ";
        cin>>d;
        a.push_back(d);
        i++;
        cout<<"\nWant to enter more?(y/n) : ";
        cin>>b;
    }
    i=0;
    int c=a.size();
    for(i=0;i<c;i++)
    {
        mi=a[i];
        temp=i;
        for(int j=i;j<c;j++)
        {
            if(mi>a[j])
            {
                mi=a[j];
                temp=j;
            }
            else
            {
                ;
            }
        }
        a[temp]=a[i];
        a[i]=mi;
    }
    cout<<"\nThe Sorted Array is : ";
    for(i=0;i<c;i++)
    {
        cout<<a[i]<<"  ";
    }
    getch();
}
