// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<vector<char>>> ans;
    bool isSafe(int a,int b,vector<vector<int>> &mat)
    {
        if(mat[a][b])
            return false;
        return true;
    }
    vector<vector<int>> make(int a,int b,vector<vector<int>> mat)
    {
        mat[a][b]=1;
        for(int i=a,j=b;i<mat.size();i++)
            mat[i][j]=1;
        for(int j=b,i=a;j<mat.size();j++)
            mat[i][j]=1;
        for(int i=a,j=b;i>=0;i--)
            mat[i][j]=1;
        for(int j=b,i=a;j>=0;j--)
            mat[i][j]=1;
        for(int i=a,j=b;i<mat.size() and j<mat.size();i++,j++)
            mat[i][j]=1;
        for(int i=a,j=b;i<mat.size() and j>=0;i++,j--)
            mat[i][j]=1;
        for(int i=a,j=b;i>=0 and j<mat.size();i--,j++)
            mat[i][j]=1;
        for(int i=a,j=b;i>=0 and j>=0;i--,j--)
            mat[i][j]=1;
        return mat;
    }
    void driver(vector<vector<char>> temp,vector<vector<int>> mat,int idx)
    {
        if(idx>=mat.size())
        {ans.push_back(temp);return;}
        for(int i=0;i<mat.size();i++)
        {
            if(isSafe(idx,i,mat))
            {
                temp[idx][i]='Q';
                vector<vector<int>> new_mat=make(idx,i,mat);
                driver(temp,new_mat,idx+1);
                temp[idx][i]='.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
       vector<vector<char>> temp(n,vector<char>(n,'.'));
        vector<vector<int>> mat(n,vector<int> (n,0));
        driver(temp,mat,0);
        vector<vector<int>> ret;
        for(int i=0;i<ans.size();i++)
        {
            vector<int> aa;
            for(int j=0;j<ans[i].size();j++)
            {
                for(int k=0;k<ans[i][j].size();k++)
                {
                    if(ans[i][j][k]=='Q')
                        aa.push_back(k+1);                        
                }
            }
            ret.push_back(aa);
        }
        return ret;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends