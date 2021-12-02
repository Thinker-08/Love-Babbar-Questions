#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
#include <iostream>
#include <string>
#define R 3
#define C 3
using namespace std;
void printUtil(string arr[R][C], int m, int n, string output[R])
{
    output[m] = arr[m][n];
    if (m==R-1)
    {
        for (int i=0; i<R; i++)
           cout << output[i] << " ";
        cout << endl;
        return;
    }
    for (int i=0; i<C; i++)
       if (arr[m+1][i] != "")
          printUtil(arr, m+1, i, output);
}

void print(string arr[R][C])
{
   string output[R];
   for (int i=0; i<C; i++)
     if (arr[0][i] != "")
        printUtil(arr, 0, i, output);
}
 
int main()
{
   string arr[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
 
   print(arr);
 
   return 0;
}