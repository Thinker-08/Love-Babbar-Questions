// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
       cpp_int dp[n+1];
        for(int i=0;i<n+1;i++)
        {
            if(i==0 || i==1)
                dp[i]=1;
            else
            {
                cpp_int sum=0;
                for(int j=0;j<i;j++)
                {
                    sum=dp[j]*dp[i-j-1]+sum;
                }
                dp[i]=sum;
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends