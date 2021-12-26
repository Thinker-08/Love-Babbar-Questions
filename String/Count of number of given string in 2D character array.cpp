// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int find(vector<vector<char>>& arr, string& word, int i, int j, int mov)
    {
        
    if(i >= 0 && j >= 0 && i < arr.size() && j < arr[0].size() && arr[i][j] == word[mov])
    {
        if(mov == word.length() - 1)
        return 1;
        
        char ch = arr[i][j];
        arr[i][j] = '#';
        
        int all =  find(arr, word, i, j - 1, mov + 1) +
                   find(arr, word, i - 1, j, mov + 1) +
                   find(arr, word, i, j + 1, mov + 1) +
                   find(arr, word, i + 1, j, mov + 1);
                   
        arr[i][j] = ch;           
        return all;
    }
    
    return 0;
    }
    int findOccurrence(vector<vector<char> > &arr, string word)
    {
        int row = arr.size();
        int col = arr[0].size();
        
        int ans = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(arr[i][j] == word[0])
                {
                    ans = ans + find(arr, word, i, j, 0);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}
  // } Driver Code Ends