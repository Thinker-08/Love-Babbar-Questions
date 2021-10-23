#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
void mergesort(int [],int,int);
void mg(int [],int,int,int);
void printarray(int [],int);
int main()
{
    int a[10];
    int i=0,temp;
    int mi;
    while(i<10)
    {
        cout<<"Enter The Element : ";
        cin>>a[i];
        i++;
    }
    printarray(a,10);
    mergesort(a,0,9);
    printarray(a,10);
    getch();
    return 0;
}
void mergesort(int arr[],int l,int r)
{
    int m;
    if(l>=r)
    {
        return;
    }
    else
    {
        m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        mg(arr,l,m,r);
    }
}
void printarray(int arr[],int a)
{
    cout<<"\n";
    for(int i=0;i<a;i++)
    {
        cout<<arr[i]<<"  ";
    }
}
void mg(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(a[i]>b[j])
        {
            arr[k]=b[j];
            j++;
            k++;
        }
        else
        {
            arr[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        j++;
        k++;
    }
}
