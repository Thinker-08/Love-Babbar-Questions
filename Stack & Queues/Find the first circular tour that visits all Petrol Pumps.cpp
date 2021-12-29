// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int start=0,end=1;
        int balance=p[start].petrol-p[start].distance;
        while(start!=end || balance<0)
        {
            while(start!=end and balance<0)
            {
                balance=balance-p[start].petrol+p[start].distance;
                start++;
                start=start%n;
                if(start==0)
                    return -1;
            }
            balance=balance+p[end].petrol-p[end].distance;
            end++;
            end%=n;
        }
        return start;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends