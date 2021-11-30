// { Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
        int i=0,j=0;
        int count=0;
        int maxi=INT_MIN,index;
        sort(Entry,Entry+N);
        sort(Exit,Exit+N);
        while(i<N and j<N)
        {
            if(Entry[i]<=Exit[j])
            {
                count++;
                i++;
                if(count>maxi)
                {
                    maxi=count;
                    index=Entry[i-1];
                }
            }
            else
            {
                count--;
                j++;
            }
        }
        while(i<N)
        {
            count++;
            i++;
            if(count>maxi)
            {
                maxi=count;
                index=Entry[i-1];
            }
        }
        while(j<N)
        {
            count--;
            j++;
            maxi=max(maxi,count);
        }
        vector<int> ans;
        ans.push_back(maxi);
        ans.push_back(index);
        return ans;
	}    
};

// { Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends