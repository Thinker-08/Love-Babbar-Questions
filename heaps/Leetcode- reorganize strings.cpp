class cmp
{
    public:
    bool operator()(pair<int,char> &a,pair<int,char> &b)
    {
        return a.first<b.first;
    }
};
class Solution {
public:
    string reorganizeString(string s)
    {
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        string ans;
        while(!pq.empty())
        {
            pair<int,char> temp1=pq.top();
            pq.pop();
            if(pq.empty() and temp1.first>1)
            {
                return "";
            }
            else
            {
                if(pq.empty())
                {
                    ans+=temp1.sn ans;
                }econd;
                    retur
                pair<int,char> temp2=pq.top();
                pq.pop();
                ans+=temp1.second;
                ans+=temp2.second;
                temp1.first--;
                temp2.first--;
                if(temp1.first!=0)
                    pq.push(temp1);
                if(temp2.first!=0)
                    pq.push(temp2);
            }
        }
        return ans;
    }
};