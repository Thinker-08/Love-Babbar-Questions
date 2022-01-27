// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
   vector<vector<int>> ans;
class Node
{
    public:
    bool end;
    vector<int> v;
    Node* next[26];
    Node()
    {
        end=false;
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
};
  class Trie
{
  public:
    Node* tr;
    Trie()
    {
        tr=new Node();
    }
    void insert(string s,int x)
    {
        int i=0;
        Node* it=tr;
        while(i<s.length())
        {
            if(it->next[s[i]-'a']==NULL)
                it->next[s[i]-'a']=new Node();
            it=it->next[s[i]-'a'];
            i++;
        }
        it->end=true;
        (it->v).push_back(x);
    }
};
  void find(Node* tr,vector<string> &string_list)
    {
    if(tr->end==true)
    {
        ans.push_back(tr->v);
        return;
    }
    for(int i=0;i<26;i++)
    {
        if(tr->next[i]!=NULL)
        {
            find(tr->next[i],string_list);
        }
    }
    }
    vector<vector<string> > Anagrams(vector<string>& string_list)
    {
        Trie* obj=new Trie();
    for(int i=0;i<string_list.size();i++)
    {
        string s=string_list[i];
        sort(s.begin(),s.end());
        obj->insert(s,i);
    }
    find(obj->tr,string_list);
    vector<vector<string>> ret;
    for(int i=0;i<ans.size();i++)
    {
        vector<string> temp;
        for(int j=0;j<ans[i].size();j++)
        {
            temp.push_back(string_list[ans[i][j]]);
        }
        ret.push_back(temp);
    }
    return ret;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends