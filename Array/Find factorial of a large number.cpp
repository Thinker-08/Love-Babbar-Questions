// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution {
public:
    int multiply(vector<int> &v,int num,int siz)
    {
        int carry=0;
        for(int i=0;i<siz;i++)
        {
            int x=v[i]*num+carry;
            v[i]=x%10;
            carry=x/10;
        }
        while(carry)
        {
            v[siz]=carry%10;
            carry=carry/10;
            siz++;
        }
        return siz;
    }
    vector<int> factorial(int N){
        vector<int> v(1e5,0);
        v[0]=1;
        int siz=1;
        for(int i=2;i<=N;i++)
        {
            siz=multiply(v,i,siz);
        }
        vector<int> ans;
        for(int i=0;i<siz;i++)
        {
            ans.push_back(v[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends