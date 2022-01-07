// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool issafe(int i,int j,int val,int arr[N][N])
    {
        for(int col=0;col<N;col++)
        {
            if(arr[i][col]==val)
            {
                return false;
            }
        }
        for(int r=0;r<N;r++)
        {
            if(arr[r][j]==val)
            {
                return false;
            }
        }
        int b = i-i%3;
        int a = j-j%3;
        for(int i=0;i<3;i++)
        {
            for(int q=0;q<3;q++)
            {
                if(arr[i+b][q+a]==val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        int f=0;
        int x;
        int y;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    f=1;
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        if(f==0)
        {
            return true;
        }
        for(int a=1;a<=9;a++)
        {
            if(issafe(x,y,a,grid))
            {
                grid[x][y]=a;
                if(SolveSudoku(grid))
                {
                    return true;
                }
                else
                {
                    grid[x][y]=0;
                }
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends