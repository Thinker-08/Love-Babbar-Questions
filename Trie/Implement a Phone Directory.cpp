// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
struct trie
    {
        trie* child[26];
        bool isend;
    };
    trie* newNode()
    {
        trie* temp=new trie;
        temp->isend=0;
        for(int i=0;i<26;i++)
            temp->child[i]=NULL;
        
        return temp;
    }
    void insert(trie* temp,string& str)
    {
        for(int i=0;i<str.length();i++)
        {
            int indx=str[i]-'a';
            if(temp->child[indx]==NULL)
                temp->child[indx]=newNode();
            
            temp=temp->child[indx];
        }
        temp->isend =  true;
    }
    void calc(trie* root, string& str,vector<string>& res)
    {
        if(root==NULL)
            return;
        if(root->isend)
            res.push_back(str);
        
        trie* temp=root;
        for(int i=0;i<26;i++)
        {
            str.push_back(i+'a');
            calc(temp->child[i],str,res);
            str.pop_back();
        }
    }
    vector<vector<string>> displayContacts(int n, string p[], string str)
    {
        trie* root=newNode();
        for(int i=0;i<n;i++)
        {
            insert(root,p[i]);
        }
        vector<vector<string>> res(str.size());
        int i=0;
        for(i;i<str.length();i++)
        {
            vector<string> temp;
            root=root->child[str[i]-'a'];
            if(root==NULL)
                break;
            string s=str.substr(0,i+1);
            calc(root,s,temp);
            if(temp.size()==0)
            res[i]={"0"};
            else
            res[i]=temp;
        }
        while(i<str.length())
        {
            res[i]={"0"};
            i++;
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends