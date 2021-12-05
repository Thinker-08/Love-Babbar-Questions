class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int ans=0;
        unordered_map<int,list<int>::iterator> mp;
        list<int> l;
        for(int i=0;i<N;i++)
        {
            if(mp.find(pages[i])!=mp.end())
            {
                auto it = mp[pages[i]];
                int temp=(*it);
                l.erase(it);
                l.push_front(temp);
                mp[pages[i]]=l.begin();
            }
            else
            {
                if(l.size()==C)
                {
                    mp.erase(l.back());
                    l.pop_back();
                }
                l.push_front(pages[i]);
                mp[pages[i]]=l.begin();
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends