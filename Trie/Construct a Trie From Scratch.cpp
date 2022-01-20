#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long
using namespace std;
#define vi vector<int>
#define vvl vector<vector<int>>
#define vl vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define newline cout<<'\n'
class Trie
{
    public:
        class Node
        {
            public:
                bool end;
                Node* next[26];
                Node()
                {
                    end=false;
                    rep(i,0,26)
                    {
                        next[i]=NULL;
                    }
                }
        };
        Node *tr;
        Trie()
        {
            tr = new Node();
        }
        void insert(string s)
        {
            int i=0;
            Node *it=tr;
            while(i<s.length())
            {
                if(it->next[s[i]-'a']==NULL)
                    it->next[s[i]-'a']=new Node();
                it = it->next[s[i]-'a'];
                i++;
            }
            it->end=true;
        }
        bool search(string s)
        {
            int i=0;
            Node* it = tr;
            while(i<s.length())
            {
                if(it->next[s[i]-'a']==NULL)
                    return false;
                it=it->next[s[i]-'a'];
                i++;
            }
            return it->end;
        }
};
int32_t main()
{
    fast;
    int n;
    cin>>n;
    Trie *tr=new Trie();
    rep(i,0,n)
    {
        string s;
        cin>>s;
        tr->insert(s);
    }
    string check;
    cin>>check;
    if(tr->search(check))
        cout<<"EXISTS";
    else
        cout<<"DOES NOT EXIST";
    newline;
    return 0;
}