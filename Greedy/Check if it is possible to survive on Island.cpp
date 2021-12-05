class Solution{
public:
    int minimumDays(int S, int N, int M){
        if(N<M)
            return -1;
        else
        {
            if(6*N<7*M and S>6)
                return -1;
            else
            {
                int days;
                days = M*S/N;
                if(M*S%N!=0)
                    days++;
                return days;
            }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends