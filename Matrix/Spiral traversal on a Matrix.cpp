#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int top=0;
        int bottom=r-1;
        int left=0;
        int right=c-1;
        vector<int> spiral;
      
      
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
             spiral.push_back(matrix[top][i]); top++;
             
            for(int j=top;j<=bottom;j++)
             spiral.push_back(matrix[j][right]); right--; 
             
             if(top<=bottom){
            for(int k=right;k>=left;k--)
             spiral.push_back(matrix[bottom][k]); bottom--; }
            
            if(left<=right){ 
            for(int l=bottom;l>=top;l--)
             spiral.push_back(matrix[l][left]);  left++; 
             }
        }
        
        return spiral;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends