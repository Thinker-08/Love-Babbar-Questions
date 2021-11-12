// { Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string printSequence(string S)
{
    map<char,string> mp;
    string s;
    mp['A']=s+"2";
    mp['B']=s+"22";
    mp['C']=s+"222";
    mp['D']=s+"3";
    mp['E']=s+"33";
    mp['F']=s+"333";
    mp['G']=s+"4";
    mp['H']=s+"44";
    mp['I']=s+"444";
    mp['J']=s+"5";
    mp['K']=s+"55";
    mp['L']=s+"555";
    mp['M']=s+"6";
    mp['N']=s+"66";
    mp['O']=s+"666";
    mp['P']=s+"7";
    mp['Q']=s+"77";
    mp['R']=s+"777";
    mp['S']=s+"7777";
    mp['T']=s+"8";
    mp['U']=s+"88";
    mp['V']=s+"888";
    mp['W']=s+"9";
    mp['X']=s+"99";
    mp['Y']=s+"999";
    mp['Z']=s+"9999";
    mp[' ']=s+"0";
    string ans;
    for(int i=0;i<S.length();i++)
    {
        ans=ans+mp[S[i]];
    }
    return ans;
    
}