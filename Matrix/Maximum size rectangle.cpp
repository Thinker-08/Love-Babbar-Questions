// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int calc(vector<int> v)
  {
      stack<int> s;
      vector<int> left(v.size()),right(v.size());
      for(int i=0;i<v.size();i++)
      {
          if(s.empty())
          {
              left[i]=0;
              s.push(i);
          }
          else
          {
                while(!s.empty() and v[s.top()]>=v[i])
                    s.pop();
                left[i]=s.empty()? 0:s.top()+1;
                s.push(i);
          }
      }
      while(!s.empty())
        s.pop();
    for(int i=v.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            right[i]=v.size()-1;
            s.push(i);
        }
        else
        {
            while(!s.empty() and v[s.top()]>=v[i])
                s.pop();
            right[i]=s.empty()?v.size()-1:s.top()-1;
            s.push(i);
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans=max(ans,v[i]*(right[i]-left[i]+1));
    }
    return ans;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<vector<int>> lines(n+1,vector<int>(m,0));
        for(int i=1;i<n+1;i++)
        {
            vector<int> temp(m,0);
            for(int j=0;j<m;j++)
            {
                if(M[i-1][j]!=0)
                    temp[j]=lines[i-1][j]+1;
                else
                    temp[j]=0;
            }
            lines[i]=temp;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,calc(lines[i]));
        }   
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends