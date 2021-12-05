#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
#define vi vector<ll>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define newline cout<<'\n'
class LRUCache
{
    private:

    public:
    unordered_map<int,list<pair<int,int>>::iterator> mp;
        int size;
        list<pair<int,int>> l;
    LRUCache(int cap)
    {
        size=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            auto it = mp[key];
            pair<int,int> p = *it;
            l.erase(it);
            l.push_front(p);
            mp[key]=l.begin();
            return p.second;
        }
        else
            return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            l.erase(mp[key]);
        }
        else
        {
            if(l.size()==size)
            {
                mp.erase(l.back().first);
                l.pop_back();
            }
        }
        l.push_front(make_pair(key,value));
        mp[key]=l.begin();  
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends